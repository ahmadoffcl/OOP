/**
 * @file    CourseManager.cpp
 * @brief   Implementation of the CourseManager class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-07
 *
 * OOP Concepts: File I/O, Arrays, Custom Exception Handling
 */

#include "CourseManager.h"
#include "../utils/Exceptions.h"
#include "../utils/Utils.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

CourseManager::CourseManager(string courseFile, string enrollmentFile) {
    courseFileName = courseFile;
    enrollmentFileName = enrollmentFile;
    courseCount = 0;
    enrollmentCount = 0;
}

void CourseManager::clearCourses() {
    courseCount = 0;
    enrollmentCount = 0;
}

void CourseManager::seedDefaultCourse(PersonManager& personManager) {
    Faculty* faculty = personManager.getFirstFaculty();

    if (faculty != NULL) {
        addCourse(Course("CS-104L", "Object Oriented Programming Lab", 1, faculty, 1));
    }
}

bool CourseManager::addCourse(Course course) {
    if (courseCount >= MAX_COURSES) {
        cout << "Course storage is full." << endl;
        return false;
    }

    if (findCourseByCode(course.getCourseCode()) != NULL) {
        cout << "Course with this code already exists." << endl;
        return false;
    }

    courses[courseCount] = course;
    courseCount++;
    return true;
}

Course* CourseManager::findCourseByCode(string code) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].getCourseCode() == code) {
            return &courses[i];
        }
    }

    return NULL;
}

Course* CourseManager::getCourse(int index) {
    if (index >= 0 && index < courseCount) {
        return &courses[index];
    }

    return NULL;
}

int CourseManager::getCourseCount() const {
    return courseCount;
}

int CourseManager::getEnrollmentCount() const {
    return enrollmentCount;
}

void CourseManager::loadCourses(PersonManager& personManager) {
    ifstream file(courseFileName);

    courseCount = 0;
    enrollmentCount = 0;

    if (!file) {
        seedDefaultCourse(personManager);
        saveCourses();
        return;
    }

    string line;
    while (getline(file, line) && courseCount < MAX_COURSES) {
        if (line == "") {
            continue;
        }

        string part[5];
        stringstream ss(line);
        int count = 0;

        while (count < 5 && getline(ss, part[count], '|')) {
            count++;
        }

        if (count >= 5) {
            Faculty* faculty = dynamic_cast<Faculty*>(personManager.findByID(part[3]));

            if (faculty == NULL) {
                cout << "Skipped course with missing instructor: " << line << endl;
                continue;
            }

            try {
                addCourse(Course(part[0], part[1], stoi(part[2]), faculty, stoi(part[4])));
            } catch (...) {
                cout << "Skipped wrong course record: " << line << endl;
            }
        }
    }

    file.close();

    if (courseCount == 0) {
        seedDefaultCourse(personManager);
        saveCourses();
    }
}

void CourseManager::saveCourses() const {
    ofstream file(courseFileName);

    if (!file) {
        cout << "Course file could not be opened for saving." << endl;
        return;
    }

    for (int i = 0; i < courseCount; i++) {
        Faculty* faculty = courses[i].getInstructor();
        string instructorID = "N/A";

        if (faculty != NULL) {
            instructorID = faculty->getEmployeeID();
        }

        file << courses[i].getCourseCode() << "|" << courses[i].getCourseName()
             << "|" << courses[i].getCreditHours() << "|" << instructorID
             << "|" << courses[i].getMaxCapacity() << endl;
    }

    file.close();
}

void CourseManager::loadEnrollments(PersonManager& personManager) {
    ifstream file(enrollmentFileName);

    enrollmentCount = 0;

    if (!file) {
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line == "") {
            continue;
        }

        string part[5];
        stringstream ss(line);
        int count = 0;

        while (count < 5 && getline(ss, part[count], '|')) {
            count++;
        }

        if (count >= 5) {
            Student* student = dynamic_cast<Student*>(personManager.findByID(part[0]));
            Course* course = findCourseByCode(part[1]);

            if (student == NULL || course == NULL) {
                cout << "Skipped enrollment with missing student/course: " << line << endl;
                continue;
            }

            try {
                if (part[4] == "Enrolled") {
                    course->enrollStudent(student);
                } else if (part[4] == "Waiting") {
                    course->addToWaitingList(student);
                }
            } catch (CapacityExceededException&) {
            }

            if (enrollmentCount < MAX_ENROLLMENTS) {
                enrollments[enrollmentCount].setStudent(student);
                enrollments[enrollmentCount].setCourse(course);
                enrollments[enrollmentCount].setEnrollmentDate(part[2]);
                enrollments[enrollmentCount].setGrade(part[3]);
                enrollments[enrollmentCount].setStatus(part[4]);
                enrollmentCount++;
            }
        }
    }

    file.close();
}

void CourseManager::saveEnrollments() const {
    ofstream file(enrollmentFileName);

    if (!file) {
        cout << "Enrollment file could not be opened for saving." << endl;
        return;
    }

    for (int i = 0; i < courseCount; i++) {
        for (int j = 0; j < courses[i].getEnrolledCount(); j++) {
            Student* student = courses[i].getEnrolledStudent(j);
            if (student != NULL) {
                file << student->getRollNo() << "|" << courses[i].getCourseCode()
                     << "|" << Utils::getTodayDate() << "|" << student->calculateGrade()
                     << "|Enrolled" << endl;
            }
        }

        for (int j = 0; j < courses[i].getWaitingCount(); j++) {
            Student* student = courses[i].getWaitingStudent(j);
            if (student != NULL) {
                file << student->getRollNo() << "|" << courses[i].getCourseCode()
                     << "|" << Utils::getTodayDate() << "|" << student->calculateGrade()
                     << "|Waiting" << endl;
            }
        }
    }

    file.close();
}

void CourseManager::loadAll(PersonManager& personManager) {
    loadCourses(personManager);
    loadEnrollments(personManager);
}

void CourseManager::saveAll() const {
    saveCourses();
    saveEnrollments();
}

bool CourseManager::enrollStudent(string rollNo, string courseCode, PersonManager& personManager) {
    Student* student = dynamic_cast<Student*>(personManager.findByID(rollNo));
    Course* course = findCourseByCode(courseCode);

    if (student == NULL) {
        cout << "Student not found." << endl;
        return false;
    }

    if (course == NULL) {
        cout << "Course not found." << endl;
        return false;
    }

    if (course->isStudentEnrolled(rollNo)) {
        cout << student->getName() << " is already enrolled in " << courseCode << "." << endl;
        return false;
    }

    if (course->isStudentWaiting(rollNo)) {
        cout << student->getName() << " is already in waiting list." << endl;
        return false;
    }

    try {
        course->enrollStudent(student);
        cout << student->getName() << " enrolled in " << courseCode << "." << endl;
    } catch (CapacityExceededException& e) {
        cout << "Error: " << e.what() << endl;
        if (course->isStudentWaiting(rollNo)) {
            cout << student->getName() << " was added to waiting list." << endl;
        }
    }

    rebuildEnrollmentRecords();
    return true;
}

bool CourseManager::dropStudent(string rollNo, string courseCode) {
    Course* course = findCourseByCode(courseCode);

    if (course == NULL) {
        cout << "Course not found." << endl;
        return false;
    }

    if (course->removeStudent(rollNo)) {
        rebuildEnrollmentRecords();
        cout << "Student removed from course/waiting list." << endl;
        return true;
    }

    cout << "Student was not found in this course." << endl;
    return false;
}

void CourseManager::rebuildEnrollmentRecords() {
    enrollmentCount = 0;

    for (int i = 0; i < courseCount; i++) {
        for (int j = 0; j < courses[i].getEnrolledCount() && enrollmentCount < MAX_ENROLLMENTS; j++) {
            Student* student = courses[i].getEnrolledStudent(j);
            enrollments[enrollmentCount] = Enrollment(student, &courses[i], Utils::getTodayDate());
            if (student != NULL) {
                enrollments[enrollmentCount].setGrade(student->calculateGrade());
            }
            enrollments[enrollmentCount].setStatus("Enrolled");
            enrollmentCount++;
        }

        for (int j = 0; j < courses[i].getWaitingCount() && enrollmentCount < MAX_ENROLLMENTS; j++) {
            Student* student = courses[i].getWaitingStudent(j);
            enrollments[enrollmentCount] = Enrollment(student, &courses[i], Utils::getTodayDate());
            if (student != NULL) {
                enrollments[enrollmentCount].setGrade(student->calculateGrade());
            }
            enrollments[enrollmentCount].setStatus("Waiting");
            enrollmentCount++;
        }
    }
}

void CourseManager::showAllCourses() const {
    if (courseCount == 0) {
        cout << "No courses saved." << endl;
        return;
    }

    for (int i = 0; i < courseCount; i++) {
        cout << courses[i];
    }
}

void CourseManager::showEnrollmentRecords() const {
    if (enrollmentCount == 0) {
        cout << "No enrollment records found." << endl;
        return;
    }

    for (int i = 0; i < enrollmentCount; i++) {
        enrollments[i].displayEnrollment();
    }
}

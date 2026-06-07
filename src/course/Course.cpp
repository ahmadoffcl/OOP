/**
 * @file    Course.cpp
 * @brief   Implementation of the Course class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Operator Overloading, Friend Function, Custom Exception
 */

#include "Course.h"
#include "../utils/Exceptions.h"

Course::Course() {
    courseCode = "N/A";
    courseName = "N/A";
    creditHours = 0;
    instructor = NULL;
    maxCapacity = 0;
    enrolledCount = 0;
    waitingCount = 0;

    for (int i = 0; i < MAX_COURSE_STUDENTS; i++) {
        enrolledStudents[i] = NULL;
        waitingList[i] = NULL;
    }
}

Course::Course(string code, string name, int hours, Faculty* fac, int capacity) {
    courseCode = code;
    courseName = name;
    creditHours = hours;
    instructor = fac;
    maxCapacity = capacity;
    enrolledCount = 0;
    waitingCount = 0;

    for (int i = 0; i < MAX_COURSE_STUDENTS; i++) {
        enrolledStudents[i] = NULL;
        waitingList[i] = NULL;
    }
}

Course::Course(const Course& other) {
    courseCode = other.courseCode;
    courseName = other.courseName;
    creditHours = other.creditHours;
    instructor = other.instructor;
    maxCapacity = other.maxCapacity;
    enrolledCount = other.enrolledCount;
    waitingCount = other.waitingCount;

    for (int i = 0; i < enrolledCount; i++) {
        enrolledStudents[i] = other.enrolledStudents[i];
    }

    for (int i = 0; i < waitingCount; i++) {
        waitingList[i] = other.waitingList[i];
    }

    for (int i = enrolledCount; i < MAX_COURSE_STUDENTS; i++) {
        enrolledStudents[i] = NULL;
    }

    for (int i = waitingCount; i < MAX_COURSE_STUDENTS; i++) {
        waitingList[i] = NULL;
    }
}

Course& Course::operator=(const Course& other) {
    if (this != &other) {
        courseCode = other.courseCode;
        courseName = other.courseName;
        creditHours = other.creditHours;
        instructor = other.instructor;
        maxCapacity = other.maxCapacity;
        enrolledCount = other.enrolledCount;
        waitingCount = other.waitingCount;

        for (int i = 0; i < enrolledCount; i++) {
            enrolledStudents[i] = other.enrolledStudents[i];
        }

        for (int i = enrolledCount; i < MAX_COURSE_STUDENTS; i++) {
            enrolledStudents[i] = NULL;
        }

        for (int i = 0; i < waitingCount; i++) {
            waitingList[i] = other.waitingList[i];
        }

        for (int i = waitingCount; i < MAX_COURSE_STUDENTS; i++) {
            waitingList[i] = NULL;
        }
    }

    return *this;
}

void Course::setCourseCode(string code) {
    courseCode = code;
}

void Course::setCourseName(string name) {
    courseName = name;
}

void Course::setCreditHours(int hours) {
    creditHours = hours;
}

void Course::setInstructor(Faculty* fac) {
    instructor = fac;
}

void Course::setMaxCapacity(int capacity) {
    maxCapacity = capacity;
}

string Course::getCourseCode() const {
    return courseCode;
}

string Course::getCourseName() const {
    return courseName;
}

int Course::getCreditHours() const {
    return creditHours;
}

Faculty* Course::getInstructor() const {
    return instructor;
}

int Course::getMaxCapacity() const {
    return maxCapacity;
}

int Course::getEnrolledCount() const {
    return enrolledCount;
}

int Course::getWaitingCount() const {
    return waitingCount;
}

Student* Course::getEnrolledStudent(int index) const {
    if (index >= 0 && index < enrolledCount) {
        return enrolledStudents[index];
    }

    return NULL;
}

Student* Course::getWaitingStudent(int index) const {
    if (index >= 0 && index < waitingCount) {
        return waitingList[index];
    }

    return NULL;
}

bool Course::isStudentEnrolled(string rollNo) const {
    for (int i = 0; i < enrolledCount; i++) {
        if (enrolledStudents[i] != NULL && enrolledStudents[i]->getRollNo() == rollNo) {
            return true;
        }
    }

    return false;
}

bool Course::isStudentWaiting(string rollNo) const {
    for (int i = 0; i < waitingCount; i++) {
        if (waitingList[i] != NULL && waitingList[i]->getRollNo() == rollNo) {
            return true;
        }
    }

    return false;
}

void Course::enrollStudent(Student* st) {
    if (st == NULL) {
        cout << "Student record is empty." << endl;
        return;
    }

    if (isStudentEnrolled(st->getRollNo())) {
        cout << st->getName() << " is already enrolled in " << courseCode << "." << endl;
        return;
    }

    if (isStudentWaiting(st->getRollNo())) {
        cout << st->getName() << " is already in waiting list." << endl;
        return;
    }

    if (enrolledCount >= maxCapacity) {
        addToWaitingList(st);
        throw CapacityExceededException();
    }

    enrolledStudents[enrolledCount] = st;
    enrolledCount++;
    st->addCourse(courseCode);
}

void Course::addToWaitingList(Student* st) {
    if (st == NULL) {
        return;
    }

    if (isStudentWaiting(st->getRollNo())) {
        cout << st->getName() << " is already in waiting list." << endl;
        return;
    }

    if (isStudentEnrolled(st->getRollNo())) {
        cout << st->getName() << " is already enrolled in " << courseCode << "." << endl;
        return;
    }

    if (waitingCount < MAX_COURSE_STUDENTS) {
        waitingList[waitingCount] = st;
        waitingCount++;
    } else {
        cout << "Waiting list is full." << endl;
    }
}

bool Course::removeStudent(string rollNo) {
    for (int i = 0; i < enrolledCount; i++) {
        if (enrolledStudents[i] != NULL && enrolledStudents[i]->getRollNo() == rollNo) {
            for (int j = i; j < enrolledCount - 1; j++) {
                enrolledStudents[j] = enrolledStudents[j + 1];
            }

            enrolledStudents[enrolledCount - 1] = NULL;
            enrolledCount--;
            return true;
        }
    }

    for (int i = 0; i < waitingCount; i++) {
        if (waitingList[i] != NULL && waitingList[i]->getRollNo() == rollNo) {
            for (int j = i; j < waitingCount - 1; j++) {
                waitingList[j] = waitingList[j + 1];
            }

            waitingList[waitingCount - 1] = NULL;
            waitingCount--;
            return true;
        }
    }

    return false;
}

void Course::displayEnrolledStudents() const {
    cout << "\nEnrolled Students:" << endl;

    if (enrolledCount == 0) {
        cout << "No student enrolled yet." << endl;
    }

    for (int i = 0; i < enrolledCount; i++) {
        cout << i + 1 << ". " << enrolledStudents[i]->getName()
             << " (" << enrolledStudents[i]->getRollNo() << ")" << endl;
    }
}

void Course::displayWaitingList() const {
    cout << "\nWaiting List:" << endl;

    if (waitingCount == 0) {
        cout << "No student in waiting list." << endl;
    }

    for (int i = 0; i < waitingCount; i++) {
        cout << i + 1 << ". " << waitingList[i]->getName()
             << " (" << waitingList[i]->getRollNo() << ")" << endl;
    }
}

bool Course::operator==(const Course& other) const {
    return courseCode == other.courseCode;
}

Student** Course::operator+(const Course& other) const {
    int total = waitingCount + other.waitingCount;
    Student** mergedList = new Student*[total];
    int index = 0;

    for (int i = 0; i < waitingCount; i++) {
        mergedList[index] = waitingList[i];
        index++;
    }

    for (int i = 0; i < other.waitingCount; i++) {
        mergedList[index] = other.waitingList[i];
        index++;
    }

    return mergedList;
}

ostream& operator<<(ostream& out, const Course& course) {
    out << "\nCourse Code: " << course.courseCode << endl;
    out << "Course Name: " << course.courseName << endl;
    out << "Credit Hours: " << course.creditHours << endl;

    if (course.instructor != NULL) {
        out << "Instructor: " << course.instructor->getName() << endl;
    } else {
        out << "Instructor: Not assigned" << endl;
    }

    out << "Capacity: " << course.enrolledCount << "/" << course.maxCapacity << endl;
    out << "Waiting Students: " << course.waitingCount << endl;
    return out;
}

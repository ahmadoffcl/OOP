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
}

Course::Course(string code, string name, int hours, Faculty* fac, int capacity) {
    courseCode = code;
    courseName = name;
    creditHours = hours;
    instructor = fac;
    maxCapacity = capacity;
    enrolledCount = 0;
    waitingCount = 0;
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

void Course::enrollStudent(Student* st) {
    if (enrolledCount >= maxCapacity) {
        addToWaitingList(st);
        throw CapacityExceededException();
    }

    enrolledStudents[enrolledCount] = st;
    enrolledCount++;
    st->addCourse(courseCode);
}

void Course::addToWaitingList(Student* st) {
    if (waitingCount < MAX_COURSE_STUDENTS) {
        waitingList[waitingCount] = st;
        waitingCount++;
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

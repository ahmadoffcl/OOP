/**
 * @file    Enrollment.cpp
 * @brief   Implementation of the Enrollment class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Association, Encapsulation
 */

#include "Enrollment.h"
#include <iostream>
using namespace std;

Enrollment::Enrollment() {
    student = NULL;
    course = NULL;
    enrollmentDate = "N/A";
    grade = "Not Assigned";
    status = "Enrolled";
}

Enrollment::Enrollment(Student* st, Course* c, string date) {
    student = st;
    course = c;
    enrollmentDate = date;
    grade = "Not Assigned";
    status = "Enrolled";
}

void Enrollment::setGrade(string g) {
    grade = g;
}

void Enrollment::setStatus(string s) {
    status = s;
}

void Enrollment::setStudent(Student* st) {
    student = st;
}

void Enrollment::setCourse(Course* c) {
    course = c;
}

void Enrollment::setEnrollmentDate(string date) {
    enrollmentDate = date;
}

string Enrollment::getGrade() const {
    return grade;
}

string Enrollment::getStatus() const {
    return status;
}

Student* Enrollment::getStudent() const {
    return student;
}

Course* Enrollment::getCourse() const {
    return course;
}

string Enrollment::getEnrollmentDate() const {
    return enrollmentDate;
}

void Enrollment::displayEnrollment() const {
    cout << "\nEnrollment Date: " << enrollmentDate << endl;

    if (student != NULL) {
        cout << "Student: " << student->getName() << " (" << student->getRollNo() << ")" << endl;
    }

    if (course != NULL) {
        cout << "Course: " << course->getCourseCode() << " - " << course->getCourseName() << endl;
    }

    cout << "Grade: " << grade << endl;
    cout << "Status: " << status << endl;
}

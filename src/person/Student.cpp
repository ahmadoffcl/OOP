/**
 * @file    Student.cpp
 * @brief   Implementation of the Student class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Single Inheritance, Runtime Polymorphism, Arrays
 */

#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : Person() {
    rollNo = "N/A";
    semester = 1;
    gpa = 0.0;
    courseCount = 0;
}

Student::Student(string n, string c, int a, string con, string roll, int sem, double gp)
    : Person(n, c, a, con) {
    rollNo = roll;
    semester = sem;
    gpa = gp;
    courseCount = 0;
}

void Student::setRollNo(string roll) {
    rollNo = roll;
}

void Student::setSemester(int sem) {
    semester = sem;
}

void Student::setGPA(double gp) {
    gpa = gp;
}

string Student::getRollNo() const {
    return rollNo;
}

int Student::getSemester() const {
    return semester;
}

double Student::getGPA() const {
    return gpa;
}

void Student::addCourse(string courseCode) {
    if (courseCount < MAX_STUDENT_COURSES) {
        enrolledCourses[courseCount] = courseCode;
        courseCount++;
    }
}

string Student::calculateGrade() const {
    if (gpa >= 3.7) {
        return "A";
    } else if (gpa >= 3.0) {
        return "B";
    } else if (gpa >= 2.0) {
        return "C";
    }
    return "F";
}

void Student::displayInfo() const {
    cout << "\nStudent Name: " << name << endl;
    cout << "Roll No: " << rollNo << endl;
    cout << "Semester: " << semester << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Grade: " << calculateGrade() << endl;
    cout << "Courses: ";

    if (courseCount == 0) {
        cout << "No course added";
    }

    for (int i = 0; i < courseCount; i++) {
        cout << enrolledCourses[i] << " ";
    }
    cout << endl;
}

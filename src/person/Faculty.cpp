/**
 * @file    Faculty.cpp
 * @brief   Implementation of the Faculty class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Inheritance, Encapsulation, Arrays
 */

#include "Faculty.h"
#include <iostream>
using namespace std;

Faculty::Faculty() : Person() {
    employeeID = "N/A";
    department = "N/A";
    designation = "N/A";
    assignedCount = 0;
}

Faculty::Faculty(string n, string c, int a, string con, string emp, string dept, string desig)
    : Person(n, c, a, con) {
    employeeID = emp;
    department = dept;
    designation = desig;
    assignedCount = 0;
}

void Faculty::setEmployeeID(string emp) {
    employeeID = emp;
}

void Faculty::setDepartment(string dept) {
    department = dept;
}

void Faculty::setDesignation(string desig) {
    designation = desig;
}

string Faculty::getEmployeeID() const {
    return employeeID;
}

string Faculty::getDepartment() const {
    return department;
}

string Faculty::getDesignation() const {
    return designation;
}

void Faculty::assignCourse(string courseCode) {
    if (assignedCount < MAX_FACULTY_COURSES) {
        assignedCourses[assignedCount] = courseCode;
        assignedCount++;
    }
}

void Faculty::displayInfo() const {
    cout << "\nFaculty Name: " << name << endl;
    cout << "Employee ID: " << employeeID << endl;
    cout << "Department: " << department << endl;
    cout << "Designation: " << designation << endl;
    cout << "Assigned Courses: ";

    if (assignedCount == 0) {
        cout << "No course assigned";
    }

    for (int i = 0; i < assignedCount; i++) {
        cout << assignedCourses[i] << " ";
    }
    cout << endl;
}

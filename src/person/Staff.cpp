/**
 * @file    Staff.cpp
 * @brief   Implementation of the Staff class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Inheritance, Encapsulation
 */

#include "Staff.h"
#include <iostream>
using namespace std;

Staff::Staff() : Person() {
    staffID = "N/A";
    role = "N/A";
    salary = 0;
}

Staff::Staff(string n, string c, int a, string con, string id, string r, double sal)
    : Person(n, c, a, con) {
    staffID = id;
    role = r;
    salary = sal;
}

void Staff::setStaffID(string id) {
    staffID = id;
}

void Staff::setRole(string r) {
    role = r;
}

void Staff::setSalary(double sal) {
    salary = sal;
}

string Staff::getStaffID() const {
    return staffID;
}

string Staff::getRole() const {
    return role;
}

double Staff::getSalary() const {
    return salary;
}

void Staff::displayInfo() const {
    cout << "\nStaff Name: " << name << endl;
    cout << "Staff ID: " << staffID << endl;
    cout << "Role: " << role << endl;
    cout << "Salary: " << salary << endl;
}

string Staff::getPersonType() const {
    return "Staff";
}

string Staff::getUniqueID() const {
    return staffID;
}

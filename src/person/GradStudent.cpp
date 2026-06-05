/**
 * @file    GradStudent.cpp
 * @brief   Implementation of the GradStudent class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Multi-level Inheritance, Runtime Polymorphism
 */

#include "GradStudent.h"
#include <iostream>
using namespace std;

GradStudent::GradStudent() : Student() {
    thesisTitle = "Not Selected";
}

GradStudent::GradStudent(string n, string c, int a, string con, string roll, int sem, double gp, string thesis)
    : Student(n, c, a, con, roll, sem, gp) {
    thesisTitle = thesis;
}

void GradStudent::setThesisTitle(string thesis) {
    thesisTitle = thesis;
}

string GradStudent::getThesisTitle() const {
    return thesisTitle;
}

void GradStudent::displayInfo() const {
    Student::displayInfo();
    cout << "Thesis: " << thesisTitle << endl;
}

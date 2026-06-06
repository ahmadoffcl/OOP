/**
 * @file    Faculty.h
 * @brief   Faculty class derived from Person
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Inheritance, Encapsulation, Arrays
 */

#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include <string>
using namespace std;

const int MAX_FACULTY_COURSES = 5;

class Faculty : public Person {
private:
    string employeeID;
    string department;
    string designation;
    string assignedCourses[MAX_FACULTY_COURSES];
    int assignedCount;

public:
    Faculty();
    Faculty(string n, string c, int a, string con, string emp, string dept, string desig);

    void setEmployeeID(string emp);
    void setDepartment(string dept);
    void setDesignation(string desig);

    string getEmployeeID() const;
    string getDepartment() const;
    string getDesignation() const;

    void assignCourse(string courseCode);
    void displayInfo() const;
};

#endif

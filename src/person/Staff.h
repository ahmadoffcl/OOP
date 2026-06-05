/**
 * @file    Staff.h
 * @brief   Staff class derived from Person
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Inheritance, Encapsulation
 */

#ifndef STAFF_H
#define STAFF_H

#include "Person.h"
#include <string>
using namespace std;

class Staff : public Person {
private:
    string staffID;
    string role;
    double salary;

public:
    Staff();
    Staff(string n, string c, int a, string con, string id, string r, double sal);

    void setStaffID(string id);
    void setRole(string r);
    void setSalary(double sal);

    string getStaffID() const;
    string getRole() const;
    double getSalary() const;

    void displayInfo() const;
};

#endif

/**
 * @file    GradStudent.h
 * @brief   Graduate student class for multi-level inheritance example
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Multi-level Inheritance
 */

#ifndef GRADSTUDENT_H
#define GRADSTUDENT_H

#include "Student.h"
#include <string>
using namespace std;

class GradStudent : public Student {
private:
    string thesisTitle;

public:
    GradStudent();
    GradStudent(string n, string c, int a, string con, string roll, int sem, double gp, string thesis);

    void setThesisTitle(string thesis);
    string getThesisTitle() const;

    void displayInfo() const;
    string getPersonType() const;
};

#endif

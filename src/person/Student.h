/**
 * @file    Student.h
 * @brief   Student class derived from Person
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Single Inheritance, Encapsulation, Arrays
 */

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
using namespace std;

const int MAX_STUDENT_COURSES = 6;

class Student : public Person {
private:
    string rollNo;
    int semester;
    double gpa;
    string enrolledCourses[MAX_STUDENT_COURSES];
    int courseCount;

public:
    Student();
    Student(string n, string c, int a, string con, string roll, int sem, double gp);

    void setRollNo(string roll);
    void setSemester(int sem);
    void setGPA(double gp);

    string getRollNo() const;
    int getSemester() const;
    double getGPA() const;

    void addCourse(string courseCode);
    string calculateGrade() const;
    void displayInfo() const;
    string getPersonType() const;
    string getUniqueID() const;
};

#endif

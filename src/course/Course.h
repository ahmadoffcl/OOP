/**
 * @file    Course.h
 * @brief   Course class for course and enrollment management
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Encapsulation, Operator Overloading, Aggregation
 */

#ifndef COURSE_H
#define COURSE_H

#include "../person/Faculty.h"
#include "../person/Student.h"
#include <iostream>
#include <string>
using namespace std;

const int MAX_COURSE_STUDENTS = 50;

class Course {
private:
    string courseCode;
    string courseName;
    int creditHours;
    Faculty* instructor;
    int maxCapacity;
    int enrolledCount;
    Student* enrolledStudents[MAX_COURSE_STUDENTS];
    Student* waitingList[MAX_COURSE_STUDENTS];
    int waitingCount;

public:
    Course();
    Course(string code, string name, int hours, Faculty* fac, int capacity);
    Course(const Course& other);
    Course& operator=(const Course& other);

    void setCourseCode(string code);
    void setCourseName(string name);
    void setCreditHours(int hours);
    void setInstructor(Faculty* fac);
    void setMaxCapacity(int capacity);

    string getCourseCode() const;
    string getCourseName() const;
    int getCreditHours() const;
    Faculty* getInstructor() const;
    int getMaxCapacity() const;
    int getEnrolledCount() const;
    int getWaitingCount() const;
    Student* getEnrolledStudent(int index) const;
    Student* getWaitingStudent(int index) const;

    bool isStudentEnrolled(string rollNo) const;
    bool isStudentWaiting(string rollNo) const;
    void enrollStudent(Student* st);
    void addToWaitingList(Student* st);
    bool removeStudent(string rollNo);
    void displayEnrolledStudents() const;
    void displayWaitingList() const;

    bool operator==(const Course& other) const;
    Student** operator+(const Course& other) const;

    friend ostream& operator<<(ostream& out, const Course& course);
};

#endif

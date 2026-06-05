/**
 * @file    Reports.h
 * @brief   Report functions for SCMS
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Reporting, Sorting, Searching
 */

#ifndef REPORTS_H
#define REPORTS_H

#include "../person/Student.h"
#include "../library/Library.h"
#include <string>
using namespace std;

namespace Reports {
    void sortStudentsByGPA(Student* students[], int count);
    void showStudents(Student* students[], int count);
    Student* findStudentByRollNo(Student* students[], int count, string rollNo);
    void showTopStudent(Student* students[], int count);
    void generateCampusTextReport(Student* students[], int studentCount, Library& library, string fileName);
}

#endif

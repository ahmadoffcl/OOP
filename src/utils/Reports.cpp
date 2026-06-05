/**
 * @file    Reports.cpp
 * @brief   Implementation of SCMS report functions
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: std::sort, Loops, File I/O
 */

#include "Reports.h"
#include "Utils.h"
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

void Reports::sortStudentsByGPA(Student* students[], int count) {
    sort(students, students + count, [](Student* a, Student* b) {
        return a->getGPA() > b->getGPA();
    });
}

void Reports::showStudents(Student* students[], int count) {
    cout << "\n--- Students Sorted by GPA ---" << endl;

    for (int i = 0; i < count; i++) {
        cout << students[i]->getRollNo() << " - " << students[i]->getName()
             << " - GPA: " << students[i]->getGPA() << endl;
    }
}

void Reports::generateCampusTextReport(Student* students[], int studentCount, Library& library, string fileName) {
    ofstream file(fileName);

    if (!file) {
        cout << "Report file could not be created." << endl;
        return;
    }

    file << "Smart Campus Management System Report" << endl;
    file << "Date: " << Utils::getTodayDate() << endl;
    file << "Students: " << studentCount << endl;
    file << "Library Items: " << library.getItemCount() << endl;
    file << endl;
    file << "Student List" << endl;

    for (int i = 0; i < studentCount; i++) {
        file << students[i]->getRollNo() << " - " << students[i]->getName()
             << " - GPA: " << students[i]->getGPA() << endl;
    }

    file.close();
    cout << "Text report saved to " << fileName << endl;
}

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

Student* Reports::findStudentByRollNo(Student* students[], int count, string rollNo) {
    for (int i = 0; i < count; i++) {
        if (students[i] != NULL && students[i]->getRollNo() == rollNo) {
            return students[i];
        }
    }

    return NULL;
}

void Reports::showTopStudent(Student* students[], int count) {
    if (count <= 0) {
        cout << "No student data available." << endl;
        return;
    }

    Student* topStudent = students[0];

    for (int i = 1; i < count; i++) {
        if (students[i]->getGPA() > topStudent->getGPA()) {
            topStudent = students[i];
        }
    }

    cout << "\n--- Top GPA Student ---" << endl;
    cout << topStudent->getRollNo() << " - " << topStudent->getName()
         << " - GPA: " << topStudent->getGPA() << endl;
}

void Reports::generateCampusTextReport(Student* students[], int studentCount, Library& library, string fileName) {
    ofstream file(fileName);

    if (!file) {
        cout << "Report file could not be created." << endl;
        return;
    }

    file << "============================================================" << endl;
    file << "        SMART CAMPUS MANAGEMENT SYSTEM REPORT" << endl;
    file << "============================================================" << endl;
    file << "Date: " << Utils::getTodayDate() << endl;
    file << "University: HITEC University Taxila" << endl;
    file << "Course: CS-104L Object-Oriented Programming" << endl;
    file << "Group: Ahmad Ali, Umer Altaf, Muhammed Ahmad" << endl;
    file << "------------------------------------------------------------" << endl;
    file << "Total Students: " << studentCount << endl;
    file << "Library Items: " << library.getItemCount() << endl;
    file << "------------------------------------------------------------" << endl;
    file << "Student List" << endl;
    file << "------------------------------------------------------------" << endl;

    for (int i = 0; i < studentCount; i++) {
        file << students[i]->getRollNo() << " - " << students[i]->getName()
             << " - GPA: " << students[i]->getGPA() << endl;
    }

    file << "------------------------------------------------------------" << endl;
    file << "Top Student" << endl;
    file << "------------------------------------------------------------" << endl;

    if (studentCount > 0) {
        Student* topStudent = students[0];

        for (int i = 1; i < studentCount; i++) {
            if (students[i]->getGPA() > topStudent->getGPA()) {
                topStudent = students[i];
            }
        }

        file << topStudent->getRollNo() << " - " << topStudent->getName()
             << " - GPA: " << topStudent->getGPA() << endl;
    }

    file << "============================================================" << endl;
    file << "End of report" << endl;
    file << "============================================================" << endl;

    file.close();
    cout << "Text report saved to " << fileName << endl;
}

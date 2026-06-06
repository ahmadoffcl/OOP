/**
 * @file    Reports.cpp
 * @brief   Implementation of SCMS report functions
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: std::sort, std::find_if, Loops, File I/O
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
    Student** result = find_if(students, students + count, [rollNo](Student* student) {
        return student != NULL && student->getRollNo() == rollNo;
    });

    if (result == students + count) {
        return NULL;
    }

    return *result;
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

void Reports::generatePdfStyleTextReport(Student* students[], int studentCount, Library& library, string fileName) {
    ofstream file(fileName);

    if (!file) {
        cout << "PDF-style report file could not be created." << endl;
        return;
    }

    Student** sortedStudents = new Student*[studentCount];

    for (int i = 0; i < studentCount; i++) {
        sortedStudents[i] = students[i];
    }

    sort(sortedStudents, sortedStudents + studentCount, [](Student* a, Student* b) {
        return a->getGPA() > b->getGPA();
    });

    Student* topStudent = NULL;

    if (studentCount > 0) {
        Student** topResult = max_element(students, students + studentCount, [](Student* a, Student* b) {
            return a->getGPA() < b->getGPA();
        });
        topStudent = *topResult;
    }

    file << "============================================================" << endl;
    file << "                 PDF STYLE CAMPUS REPORT" << endl;
    file << "============================================================" << endl;
    file << "Project: Smart Campus Management System" << endl;
    file << "Course : CS-104L Object-Oriented Programming" << endl;
    file << "Inst   : HITEC University Taxila" << endl;
    file << "Date   : " << Utils::getTodayDate() << endl;
    file << "Group  : Ahmad Ali, Umer Altaf, Muhammed Ahmad" << endl;
    file << "------------------------------------------------------------" << endl;
    file << "Summary" << endl;
    file << "------------------------------------------------------------" << endl;
    file << "Total Students : " << studentCount << endl;
    file << "Library Items  : " << library.getItemCount() << endl;

    if (topStudent != NULL) {
        file << "Top GPA Student: " << topStudent->getName()
             << " (" << topStudent->getRollNo() << ")" << endl;
    }

    file << "------------------------------------------------------------" << endl;
    file << "Students Sorted by GPA" << endl;
    file << "------------------------------------------------------------" << endl;

    for (int i = 0; i < studentCount; i++) {
        file << i + 1 << ". " << sortedStudents[i]->getRollNo()
             << " | " << sortedStudents[i]->getName()
             << " | GPA: " << sortedStudents[i]->getGPA() << endl;
    }

    file << "------------------------------------------------------------" << endl;
    file << "Library Summary" << endl;
    file << "------------------------------------------------------------" << endl;
    file << "Library catalog item count: " << library.getItemCount() << endl;
    file << "See the program Library module for full book and journal records." << endl;
    file << "------------------------------------------------------------" << endl;
    file << "OOP Concepts Highlight" << endl;
    file << "------------------------------------------------------------" << endl;
    file << "Classes, inheritance, polymorphism, arrays, file handling," << endl;
    file << "exception handling, operator overloading, copy constructor," << endl;
    file << "copy assignment, static members, and memory management." << endl;
    file << "============================================================" << endl;
    file << "End of PDF-style report" << endl;
    file << "============================================================" << endl;

    delete[] sortedStudents;
    file.close();

    cout << "PDF-style text report saved to " << fileName << endl;
}

/**
 * @file    Reports.cpp
 * @brief   Implementation of SCMS report functions
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: std::sort, std::find_if, Dynamic Arrays, File I/O
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

    if (count == 0) {
        cout << "No student data available." << endl;
    }

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << students[i]->getRollNo()
             << " | " << students[i]->getName()
             << " | Semester: " << students[i]->getSemester()
             << " | GPA: " << students[i]->getGPA() << endl;
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

void Reports::showCampusSummary(PersonManager& personManager, CourseManager& courseManager,
                                Library& library, FinanceManager& financeManager,
                                HostelManager& hostelManager) {
    Student* students[MAX_PEOPLE];
    int studentCount = personManager.getStudents(students, MAX_PEOPLE);

    cout << "Date: " << Utils::getTodayDate() << endl;
    Utils::printSmallLine();
    cout << "Total People: " << personManager.getPersonCount() << endl;
    cout << "Total Students: " << studentCount << endl;
    cout << "Saved Courses: " << courseManager.getCourseCount() << endl;
    cout << "Enrollment Records: " << courseManager.getEnrollmentCount() << endl;
    cout << "Library Items: " << library.getItemCount() << endl;
    cout << "Issued Records: " << library.getIssuedCount() << endl;
    cout << "Currently Issued Items: " << library.getActiveIssuedCount() << endl;
    cout << "Overdue Library Records: " << library.getOverdueRecordCount() << endl;
    cout << "Fee Records: " << financeManager.getRecordCount() << endl;
    cout << "Total Fee Paid: " << financeManager.getTotalPaid() << endl;
    cout << "Total Fee Balance: " << financeManager.getTotalBalance() << endl;
    cout << "Hostel Rooms: " << hostelManager.getRoomCount() << endl;
    cout << "Hostel Occupants: " << hostelManager.getTotalOccupants() << endl;
}

void Reports::showUtilityInfo() {
    cout << "Today Date: " << Utils::getTodayDate() << endl;
    Utils::printSmallLine();
    cout << "Utils::printLine() prints a long separator." << endl;
    cout << "Utils::printSmallLine() prints a short separator." << endl;
    cout << "Utils::checkPositiveInt(-5) returns "
         << Utils::checkPositiveInt(-5) << endl;
    cout << "Utils::checkPositiveInt(10) returns "
         << Utils::checkPositiveInt(10) << endl;
}

void Reports::generateCampusTextReport(PersonManager& personManager, CourseManager& courseManager,
                                       Library& library, FinanceManager& financeManager,
                                       HostelManager& hostelManager, string fileName) {
    ofstream file(fileName);

    if (!file) {
        cout << "Report file could not be created." << endl;
        return;
    }

    Student* students[MAX_PEOPLE];
    int studentCount = personManager.getStudents(students, MAX_PEOPLE);
    Student** sortedStudents = new Student*[studentCount];

    for (int i = 0; i < studentCount; i++) {
        sortedStudents[i] = students[i];
    }

    sort(sortedStudents, sortedStudents + studentCount, [](Student* a, Student* b) {
        return a->getGPA() > b->getGPA();
    });

    file << "============================================================" << endl;
    file << "        SMART CAMPUS MANAGEMENT SYSTEM REPORT" << endl;
    file << "============================================================" << endl;
    file << "Date: " << Utils::getTodayDate() << endl;
    file << "University: HITEC University Taxila" << endl;
    file << "Course: CS-104L Object-Oriented Programming" << endl;
    file << "Group: Ahmad Ali, Umer Altaf, Muhammed Ahmad" << endl;
    file << "------------------------------------------------------------" << endl;
    file << "Campus Summary" << endl;
    file << "------------------------------------------------------------" << endl;
    file << "Total People: " << personManager.getPersonCount() << endl;
    file << "Total Students: " << studentCount << endl;
    file << "Saved Courses: " << courseManager.getCourseCount() << endl;
    file << "Enrollment Records: " << courseManager.getEnrollmentCount() << endl;
    file << "Library Items: " << library.getItemCount() << endl;
    file << "Issued Records: " << library.getIssuedCount() << endl;
    file << "Currently Issued Items: " << library.getActiveIssuedCount() << endl;
    file << "Overdue Library Records: " << library.getOverdueRecordCount() << endl;
    file << "Fee Records: " << financeManager.getRecordCount() << endl;
    file << "Total Fee Paid: " << financeManager.getTotalPaid() << endl;
    file << "Total Fee Balance: " << financeManager.getTotalBalance() << endl;
    file << "Total Library Fine: " << financeManager.getTotalLibraryFine() << endl;
    file << "Hostel Rooms: " << hostelManager.getRoomCount() << endl;
    file << "Hostel Occupants: " << hostelManager.getTotalOccupants() << endl;

    file << "------------------------------------------------------------" << endl;
    file << "Students Sorted by GPA" << endl;
    file << "------------------------------------------------------------" << endl;

    for (int i = 0; i < studentCount; i++) {
        file << i + 1 << ". " << sortedStudents[i]->getRollNo()
             << " | " << sortedStudents[i]->getName()
             << " | Semester: " << sortedStudents[i]->getSemester()
             << " | GPA: " << sortedStudents[i]->getGPA() << endl;
    }

    file << "------------------------------------------------------------" << endl;
    file << "Courses" << endl;
    file << "------------------------------------------------------------" << endl;

    if (courseManager.getCourseCount() == 0) {
        file << "No courses saved." << endl;
    }

    for (int i = 0; i < courseManager.getCourseCount(); i++) {
        Course* course = courseManager.getCourse(i);

        if (course != NULL) {
            file << course->getCourseCode() << " | " << course->getCourseName()
                 << " | Enrolled: " << course->getEnrolledCount()
                 << "/" << course->getMaxCapacity()
                 << " | Waiting: " << course->getWaitingCount() << endl;
        }
    }

    file << "------------------------------------------------------------" << endl;
    file << "Finance Records" << endl;
    file << "------------------------------------------------------------" << endl;

    if (financeManager.getRecordCount() == 0) {
        file << "No fee records saved." << endl;
    }

    for (int i = 0; i < financeManager.getRecordCount(); i++) {
        FeeRecord* record = financeManager.getRecord(i);
        Student* student = NULL;

        if (record != NULL) {
            student = record->getStudent();
        }

        if (record != NULL && student != NULL) {
            file << student->getRollNo() << " | " << student->getName()
                 << " | Paid: " << record->getTotalPaid()
                 << " | Balance: " << record->getBalance() << endl;
        }
    }

    file << "------------------------------------------------------------" << endl;
    file << "Library and Hostel Summary" << endl;
    file << "------------------------------------------------------------" << endl;
    file << "Use Module 3 for full book/journal catalog and issued records." << endl;
    file << "Use Module 5 for room-wise hostel occupancy report." << endl;
    file << "============================================================" << endl;
    file << "End of report" << endl;
    file << "============================================================" << endl;

    delete[] sortedStudents;
    file.close();
    cout << "Consolidated text report saved to " << fileName << endl;
}

void Reports::generatePdfStyleTextReport(PersonManager& personManager, CourseManager& courseManager,
                                         Library& library, FinanceManager& financeManager,
                                         HostelManager& hostelManager, string fileName) {
    ofstream file(fileName);

    if (!file) {
        cout << "PDF-style report file could not be created." << endl;
        return;
    }

    Student* students[MAX_PEOPLE];
    int studentCount = personManager.getStudents(students, MAX_PEOPLE);
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
    file << "Complete System Summary" << endl;
    file << "------------------------------------------------------------" << endl;
    file << "People Records      : " << personManager.getPersonCount() << endl;
    file << "Student Records     : " << studentCount << endl;
    file << "Course Records      : " << courseManager.getCourseCount() << endl;
    file << "Enrollment Records  : " << courseManager.getEnrollmentCount() << endl;
    file << "Library Items       : " << library.getItemCount() << endl;
    file << "Issued Records      : " << library.getIssuedCount() << endl;
    file << "Active Issued Items : " << library.getActiveIssuedCount() << endl;
    file << "Overdue Records     : " << library.getOverdueRecordCount() << endl;
    file << "Fee Records         : " << financeManager.getRecordCount() << endl;
    file << "Total Paid          : " << financeManager.getTotalPaid() << endl;
    file << "Total Balance       : " << financeManager.getTotalBalance() << endl;
    file << "Hostel Rooms        : " << hostelManager.getRoomCount() << endl;
    file << "Hostel Occupants    : " << hostelManager.getTotalOccupants() << endl;

    if (topStudent != NULL) {
        file << "Top GPA Student     : " << topStudent->getName()
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
    file << "Module Coverage" << endl;
    file << "------------------------------------------------------------" << endl;
    file << "1. Person records: saved people, students, faculty, staff." << endl;
    file << "2. Courses: saved courses, enrollments, waiting lists." << endl;
    file << "3. Library: catalog, issued records, overdue tracking." << endl;
    file << "4. Finance: fee records, payments, fines, invoices." << endl;
    file << "5. Hostel: saved rooms and allocations." << endl;
    file << "6. Reports: sorting, searching, file output, utilities." << endl;
    file << "------------------------------------------------------------" << endl;
    file << "OOP Concepts Highlight" << endl;
    file << "------------------------------------------------------------" << endl;
    file << "Classes, inheritance, polymorphism, arrays, file handling," << endl;
    file << "exception handling, operator overloading, copy constructor," << endl;
    file << "copy assignment, static members, dynamic arrays, sorting," << endl;
    file << "std::find_if searching, and memory management." << endl;
    file << "============================================================" << endl;
    file << "End of PDF-style report" << endl;
    file << "============================================================" << endl;

    delete[] sortedStudents;
    file.close();

    cout << "Consolidated PDF-style text report saved to " << fileName << endl;
}

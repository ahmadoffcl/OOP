/**
 * @file    main.cpp
 * @brief   Main menu for Smart Campus Management System starter
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Objects, Runtime Polymorphism, Exception Handling
 */

#include "person/Person.h"
#include "person/Student.h"
#include "person/GradStudent.h"
#include "person/Faculty.h"
#include "person/Staff.h"
#include "course/Course.h"
#include "course/Enrollment.h"
#include "library/Book.h"
#include "library/Journal.h"
#include "library/Library.h"
#include "finance/FeeRecord.h"
#include "finance/Invoice.h"
#include "hostel/HostelManager.h"
#include "utils/Exceptions.h"
#include "utils/Reports.h"
#include "utils/Utils.h"
#include <iostream>
#include <limits>
using namespace std;

int readChoice() {
    int choice;
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }

    return choice;
}

void showPeopleDemo(Person* people[], int totalPeople) {
    cout << "\n--- Person Module Demo ---" << endl;
    for (int i = 0; i < totalPeople; i++) {
        people[i]->displayInfo();
    }
}

void showCourseDemo(Course& oopCourse) {
    cout << "\n--- Course Module Demo ---" << endl;
    cout << oopCourse;
}

void showEnrollmentDemo(Student& s1, GradStudent& s2, Course& oopCourse) {
    cout << "\n--- Enrollment and Exception Demo ---" << endl;

    try {
        oopCourse.enrollStudent(&s1);
        cout << s1.getName() << " enrolled successfully." << endl;

        oopCourse.enrollStudent(&s2);
        cout << s2.getName() << " enrolled successfully." << endl;
    } catch (CapacityExceededException& e) {
        cout << "Error: " << e.what() << endl;
        cout << "Second student was sent to waiting list." << endl;
    }

    Enrollment e1(&s1, &oopCourse, "05-06-2026");
    e1.setGrade(s1.calculateGrade());
    e1.displayEnrollment();
}

void showLibraryDemo(Library& library) {
    cout << "\n--- Library Module Demo ---" << endl;

    if (library.getItemCount() == 0) {
        library.loadCatalog("data/library_catalog.txt");

        if (library.getItemCount() == 0) {
            library.addItem(new Book("B001", "C++ Basics", "Deitel", 2020, "978-0000000001", "Programming", 3));
            library.addItem(new Journal("J001", "OOP Lab Journal", "HITEC CS", 2025, "ISSN-1111", 1, 1));
        }
    }

    library.showAllItems();

    LibraryItem* found = library.searchByTitle("C++ Basics");
    if (found != NULL) {
        cout << "\nSearch result found:" << endl;
        found->displayItem();
    }

    library.issueItem("25-CS-067", "B001");

    try {
        library.returnItem("25-CS-067", "B001", 9);
    } catch (OverdueException& e) {
        cout << "Fine Error: " << e.what() << endl;
    }

    library.saveCatalog("data/library_catalog_saved.txt");
}

void showFinanceDemo(Student& s1) {
    cout << "\n--- Finance Module Demo ---" << endl;

    FeeRecord fee(&s1, 65000, 20000, 500);
    fee.displayFeeRecord();

    fee -= 25000;
    cout << "\nAfter payment of 25000:" << endl;
    fee.displayFeeRecord();

    FeeRecord copiedFee = fee;
    cout << "\nCopied fee record:" << endl;
    copiedFee.displayFeeRecord();

    FeeRecord assignedFee;
    assignedFee = fee;
    cout << "\nAssigned fee record:" << endl;
    assignedFee.displayFeeRecord();

    string invoiceItems[3] = {"Semester Fee", "Hostel Fee", "Library Fine"};
    Invoice inv(Utils::getTodayDate(), invoiceItems, 3, fee.getBalance());
    cout << inv;

    Invoice copiedInvoice = inv;
    cout << "\nCopied invoice using copy constructor:" << endl;
    cout << copiedInvoice;
}

void showHostelDemo(Student& s1, GradStudent& s2, Student& s3) {
    cout << "\n--- Hostel Module Demo ---" << endl;

    HostelManager manager;
    manager.showServiceName();
    manager.allocateRoom(&s1);
    manager.allocateRoom(&s2);
    manager.allocateRoom(&s3);
    manager.generateReport();
    manager.vacateRoom(s1.getRollNo());
}

void showReportsDemo(Student* students[], int studentCount, Library& library) {
    cout << "\n--- Reports Module Demo ---" << endl;

    Reports::sortStudentsByGPA(students, studentCount);
    Reports::showStudents(students, studentCount);
    Reports::generateCampusTextReport(students, studentCount, library, "data/campus_report.txt");
}

int main() {
    Student s1("Ahmad Ali", "11111-1111111-1", 19, "0300-0000000", "25-CS-067", 2, 3.4);
    GradStudent s2("Umer Altaf", "22222-2222222-2", 19, "0311-0000000", "25-CS-057", 2, 3.8, "Campus Management");
    Student s3("Muhammed Ahmad", "55555-5555555-5", 19, "0344-0000000", "25-CS-252", 2, 3.2);
    Faculty f1("Sir Usman", "33333-3333333-3", 35, "0322-0000000", "F-101", "Computer Science", "Lecturer");
    Staff staff1("Office Staff", "44444-4444444-4", 30, "0333-0000000", "S-11", "Clerk", 45000);

    f1.assignCourse("CS-104L");

    Course oopCourse("CS-104L", "Object Oriented Programming Lab", 1, &f1, 1);
    Library library;

    Person* people[5];
    people[0] = &s1;
    people[1] = &s2;
    people[2] = &s3;
    people[3] = &f1;
    people[4] = &staff1;

    Student* students[3];
    students[0] = &s1;
    students[1] = &s2;
    students[2] = &s3;

    int choice;

    do {
        cout << "\n====================================" << endl;
        cout << " Smart Campus Management System" << endl;
        cout << "====================================" << endl;
        cout << "1. Show Person Module" << endl;
        cout << "2. Show Course Module" << endl;
        cout << "3. Show Enrollment Demo" << endl;
        cout << "4. Show Library Demo" << endl;
        cout << "5. Show Finance Demo" << endl;
        cout << "6. Show Hostel Demo" << endl;
        cout << "7. Show Reports Demo" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        choice = readChoice();

        if (choice == 1) {
            showPeopleDemo(people, 5);
        } else if (choice == 2) {
            showCourseDemo(oopCourse);
        } else if (choice == 3) {
            showEnrollmentDemo(s1, s2, oopCourse);
        } else if (choice == 4) {
            showLibraryDemo(library);
        } else if (choice == 5) {
            showFinanceDemo(s1);
        } else if (choice == 6) {
            showHostelDemo(s1, s2, s3);
        } else if (choice == 7) {
            showReportsDemo(students, 3, library);
        } else if (choice == 0) {
            cout << "Program closed." << endl;
        } else {
            cout << "Wrong choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

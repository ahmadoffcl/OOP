/**
 * @file    main.cpp
 * @brief   Main menu for Smart Campus Management System
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

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return choice;
}

void printTitle(string title) {
    cout << endl;
    Utils::printLine();
    cout << " " << title << endl;
    Utils::printLine();
}

void printBackOption() {
    cout << "0. Back to Home" << endl;
    cout << "Enter choice: ";
}

void loadLibraryIfNeeded(Library& library) {
    if (library.getItemCount() == 0) {
        library.loadCatalog("data/library_catalog.txt");

        if (library.getItemCount() == 0) {
            library.addItem(new Book("B001", "C++ Basics", "Deitel", 2020, "978-0000000001", "Programming", 3));
            library.addItem(new Journal("J001", "OOP Lab Journal", "HITEC CS", 2025, "ISSN-1111", 1, 1));
        }
    }
}

void showPeopleDemo(Person* people[], int totalPeople) {
    printTitle("PERSON RECORDS");

    for (int i = 0; i < totalPeople; i++) {
        people[i]->displayInfo();
    }
}

void showStudentList(Student* students[], int totalStudents) {
    printTitle("STUDENT LIST");

    for (int i = 0; i < totalStudents; i++) {
        cout << students[i]->getRollNo() << " | " << students[i]->getName()
             << " | Semester " << students[i]->getSemester()
             << " | GPA " << students[i]->getGPA() << endl;
    }
}

void personMenu(Person* people[], int totalPeople, Student* students[], int totalStudents) {
    int choice;

    do {
        printTitle("PERSON MODULE");
        cout << "1. Show all people" << endl;
        cout << "2. Show student list" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            showPeopleDemo(people, totalPeople);
        } else if (choice == 2) {
            showStudentList(students, totalStudents);
        } else if (choice == 0) {
            cout << "Returning to Home..." << endl;
        } else {
            cout << "Wrong choice. Try again." << endl;
        }
    } while (choice != 0);
}

void showCourseDemo(Course& oopCourse) {
    printTitle("COURSE DETAILS");
    cout << oopCourse;
}

void showCourseRosterDemo(Course& oopCourse) {
    printTitle("COURSE ROSTER");
    oopCourse.displayEnrolledStudents();
    oopCourse.displayWaitingList();
}

void showEnrollmentDemo(Student& s1, GradStudent& s2, Course& oopCourse, bool& enrollmentDone) {
    printTitle("ENROLLMENT DEMO");

    if (!enrollmentDone) {
        try {
            oopCourse.enrollStudent(&s1);
            cout << s1.getName() << " enrolled successfully." << endl;

            oopCourse.enrollStudent(&s2);
            cout << s2.getName() << " enrolled successfully." << endl;
        } catch (CapacityExceededException& e) {
            cout << "Error: " << e.what() << endl;
            cout << "Second student was sent to waiting list." << endl;
        }

        enrollmentDone = true;
    } else {
        cout << "Enrollment demo already completed in this run." << endl;
    }

    Enrollment e1(&s1, &oopCourse, "05-06-2026");
    e1.setGrade(s1.calculateGrade());
    e1.displayEnrollment();
}

void showCourseCompareDemo(Course& oopCourse, Faculty& faculty) {
    printTitle("COURSE COMPARISON DEMO");

    Course sameCourse("CS-104L", "Object Oriented Programming Lab", 1, &faculty, 1);
    Course otherCourse("CS-105", "Discrete Structures", 3, &faculty, 40);

    if (oopCourse == sameCourse) {
        cout << "CS-104L and sameCourse are equal by course code." << endl;
    }

    if (!(oopCourse == otherCourse)) {
        cout << "CS-104L and CS-105 are not equal." << endl;
    }
}

void showWaitingListMergeDemo(Student& s1, GradStudent& s2, Student& s3, Faculty& faculty) {
    printTitle("WAITING LIST MERGE DEMO");

    Course c1("CS-201", "Data Structures", 3, &faculty, 2);
    Course c2("CS-202", "Computer Organization", 3, &faculty, 2);

    c1.addToWaitingList(&s1);
    c1.addToWaitingList(&s2);
    c2.addToWaitingList(&s3);

    Student** merged = c1 + c2;
    int total = c1.getWaitingCount() + c2.getWaitingCount();

    cout << "Merged waiting list:" << endl;
    for (int i = 0; i < total; i++) {
        cout << i + 1 << ". " << merged[i]->getName()
             << " (" << merged[i]->getRollNo() << ")" << endl;
    }

    delete[] merged;
}

void courseMenu(Student& s1, GradStudent& s2, Student& s3, Faculty& faculty, Course& oopCourse) {
    int choice;
    bool enrollmentDone = false;

    do {
        printTitle("COURSE AND ENROLLMENT MODULE");
        cout << "1. Show course details" << endl;
        cout << "2. Run enrollment demo" << endl;
        cout << "3. Show enrolled and waiting students" << endl;
        cout << "4. Compare courses using ==" << endl;
        cout << "5. Merge waiting lists using +" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            showCourseDemo(oopCourse);
        } else if (choice == 2) {
            showEnrollmentDemo(s1, s2, oopCourse, enrollmentDone);
        } else if (choice == 3) {
            showCourseRosterDemo(oopCourse);
        } else if (choice == 4) {
            showCourseCompareDemo(oopCourse, faculty);
        } else if (choice == 5) {
            showWaitingListMergeDemo(s1, s2, s3, faculty);
        } else if (choice == 0) {
            cout << "Returning to Home..." << endl;
        } else {
            cout << "Wrong choice. Try again." << endl;
        }
    } while (choice != 0);
}

void showLibraryCatalog(Library& library) {
    loadLibraryIfNeeded(library);
    printTitle("LIBRARY CATALOG");
    library.showAllItems();
}

void showLibrarySearch(Library& library) {
    loadLibraryIfNeeded(library);
    printTitle("LIBRARY SEARCH");

    string title;
    cout << "Enter title to search (press Enter for C++ Basics): ";
    getline(cin, title);

    if (title == "") {
        title = "C++ Basics";
    }

    LibraryItem* found = library.searchByTitle(title);
    if (found != NULL) {
        cout << "Search title: " << title << endl;
        found->displayItem();
    } else {
        cout << "Item not found." << endl;
    }
}

void showLibraryIssue(Library& library) {
    loadLibraryIfNeeded(library);
    printTitle("ISSUE ITEM DEMO");

    library.issueItem("25-CS-067", "B001");
}

void showLibraryReturn(Library& library) {
    loadLibraryIfNeeded(library);
    printTitle("RETURN ITEM DEMO");

    try {
        library.returnItem("25-CS-067", "B001", 9);
    } catch (OverdueException& e) {
        cout << "Fine Error: " << e.what() << endl;
    }
}

void libraryMenu(Library& library) {
    int choice;

    do {
        printTitle("LIBRARY MODULE");
        cout << "1. Load catalog from file" << endl;
        cout << "2. Show catalog" << endl;
        cout << "3. Search by title" << endl;
        cout << "4. Issue item B001 to 25-CS-067" << endl;
        cout << "5. Return item B001 with overdue fine" << endl;
        cout << "6. Show issued records" << endl;
        cout << "7. Save catalog to file" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            library.loadCatalog("data/library_catalog.txt");
            cout << "Catalog loaded. Total items: " << library.getItemCount() << endl;
        } else if (choice == 2) {
            showLibraryCatalog(library);
        } else if (choice == 3) {
            showLibrarySearch(library);
        } else if (choice == 4) {
            showLibraryIssue(library);
        } else if (choice == 5) {
            showLibraryReturn(library);
        } else if (choice == 6) {
            library.displayIssuedRecords();
        } else if (choice == 7) {
            loadLibraryIfNeeded(library);
            library.saveCatalog("data/library_catalog_saved.txt");
            cout << "Catalog saved to data/library_catalog_saved.txt" << endl;
        } else if (choice == 0) {
            cout << "Returning to Home..." << endl;
        } else {
            cout << "Wrong choice. Try again." << endl;
        }
    } while (choice != 0);
}

void showFeeRecordDemo(Student& s1) {
    printTitle("FEE RECORD DEMO");

    FeeRecord fee(&s1, 65000, 20000, 500);
    fee.displayFeeRecord();

    fee -= 25000;
    cout << "\nAfter payment of 25000:" << endl;
    fee.displayFeeRecord();
    fee.displayPayments();
}

void showFeeCopyDemo(Student& s1) {
    printTitle("FEE COPY CONSTRUCTOR AND ASSIGNMENT DEMO");

    FeeRecord fee(&s1, 65000, 20000, 500);
    fee -= 25000;
    fee -= 10000;

    cout << "\nOriginal fee record:" << endl;
    fee.displayFeeRecord();
    fee.displayPayments();

    FeeRecord copiedFee(fee);
    cout << "\nCopied fee record:" << endl;
    copiedFee.displayFeeRecord();
    copiedFee.displayPayments();

    FeeRecord assignedFee;
    assignedFee = fee;
    cout << "\nAssigned fee record:" << endl;
    assignedFee.displayFeeRecord();
    assignedFee.displayPayments();
}

void showInvoiceDemo(Student& s1) {
    printTitle("INVOICE DEMO");

    cout << "Invoice counter before creating invoices: "
         << Invoice::getInvoiceCounter() << endl;

    FeeRecord fee(&s1, 65000, 20000, 500);
    fee -= 25000;

    string invoiceItems[3] = {"Semester Fee", "Hostel Fee", "Library Fine"};
    Invoice inv(Utils::getTodayDate(), invoiceItems, 3, fee.getBalance());
    cout << "\nOriginal invoice:" << endl;
    cout << inv;

    Invoice copiedInvoice = inv;
    cout << "\nCopied invoice using copy constructor:" << endl;
    cout << copiedInvoice;

    Invoice assignedInvoice;
    assignedInvoice = inv;
    cout << "\nAssigned invoice using copy assignment:" << endl;
    cout << assignedInvoice;

    cout << "\nInvoice counter after creating invoices: "
         << Invoice::getInvoiceCounter() << endl;
}

void financeMenu(Student& s1) {
    int choice;

    do {
        printTitle("FEE AND FINANCE MODULE");
        cout << "1. Show fee record and payment" << endl;
        cout << "2. Show fee copy constructor and assignment" << endl;
        cout << "3. Show invoice, copies, and static counter" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            showFeeRecordDemo(s1);
        } else if (choice == 2) {
            showFeeCopyDemo(s1);
        } else if (choice == 3) {
            showInvoiceDemo(s1);
        } else if (choice == 0) {
            cout << "Returning to Home..." << endl;
        } else {
            cout << "Wrong choice. Try again." << endl;
        }
    } while (choice != 0);
}

void hostelMenu(Student& s1, GradStudent& s2, Student& s3) {
    HostelManager manager;
    int choice;
    bool allocated = false;

    do {
        printTitle("HOSTEL MODULE");
        cout << "1. Show hostel service name" << endl;
        cout << "2. Allocate sample students" << endl;
        cout << "3. Try duplicate allocation" << endl;
        cout << "4. Show hostel summary" << endl;
        cout << "5. Show occupancy report" << endl;
        cout << "6. Vacate Ahmad Ali room" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            manager.showServiceName();
        } else if (choice == 2) {
            if (!allocated) {
                manager.allocateRoom(&s1);
                manager.allocateRoom(&s2);
                manager.allocateRoom(&s3);
                allocated = true;
            } else {
                cout << "Students are already allocated in this module visit." << endl;
            }
        } else if (choice == 3) {
            manager.allocateRoom(&s1);
        } else if (choice == 4) {
            manager.showSummary();
        } else if (choice == 5) {
            manager.generateReport();
        } else if (choice == 6) {
            manager.vacateRoom(s1.getRollNo());
        } else if (choice == 0) {
            cout << "Returning to Home..." << endl;
        } else {
            cout << "Wrong choice. Try again." << endl;
        }
    } while (choice != 0);
}

void reportsMenu(Student* students[], int studentCount, Library& library) {
    int choice;

    do {
        printTitle("REPORTS MODULE");
        cout << "1. Sort and show students by GPA" << endl;
        cout << "2. Find student by roll number" << endl;
        cout << "3. Show top GPA student" << endl;
        cout << "4. Generate campus text report" << endl;
        cout << "5. Generate PDF-style text report" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            Reports::sortStudentsByGPA(students, studentCount);
            Reports::showStudents(students, studentCount);
        } else if (choice == 2) {
            string rollNo;
            cout << "Enter roll no (press Enter for 25-CS-067): ";
            getline(cin, rollNo);

            if (rollNo == "") {
                rollNo = "25-CS-067";
            }

            Student* found = Reports::findStudentByRollNo(students, studentCount, rollNo);

            if (found != NULL) {
                cout << "Student found:" << endl;
                cout << found->getRollNo() << " - " << found->getName()
                     << " - GPA: " << found->getGPA() << endl;
            } else {
                cout << "Student not found." << endl;
            }
        } else if (choice == 3) {
            Reports::showTopStudent(students, studentCount);
        } else if (choice == 4) {
            loadLibraryIfNeeded(library);
            Reports::generateCampusTextReport(students, studentCount, library, "data/campus_report.txt");
        } else if (choice == 5) {
            loadLibraryIfNeeded(library);
            Reports::generatePdfStyleTextReport(students, studentCount, library, "data/campus_pdf_report.txt");
        } else if (choice == 0) {
            cout << "Returning to Home..." << endl;
        } else {
            cout << "Wrong choice. Try again." << endl;
        }
    } while (choice != 0);
}

void showHomeMenu() {
    printTitle("SMART CAMPUS MANAGEMENT SYSTEM");
    cout << "Group: Ahmad Ali, Umer Altaf, Muhammed Ahmad" << endl;
    cout << "Course: CS-104L Object-Oriented Programming" << endl;
    Utils::printLine();
    cout << "1. Person Module" << endl;
    cout << "2. Course and Enrollment Module" << endl;
    cout << "3. Library Module" << endl;
    cout << "4. Fee and Finance Module" << endl;
    cout << "5. Hostel Module" << endl;
    cout << "6. Reports Module" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter choice: ";
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
        showHomeMenu();
        choice = readChoice();

        if (choice == 1) {
            personMenu(people, 5, students, 3);
        } else if (choice == 2) {
            courseMenu(s1, s2, s3, f1, oopCourse);
        } else if (choice == 3) {
            libraryMenu(library);
        } else if (choice == 4) {
            financeMenu(s1);
        } else if (choice == 5) {
            hostelMenu(s1, s2, s3);
        } else if (choice == 6) {
            reportsMenu(students, 3, library);
        } else if (choice == 0) {
            printTitle("PROGRAM CLOSED");
        } else {
            cout << "Wrong choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

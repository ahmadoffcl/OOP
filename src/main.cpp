/**
 * @file    main.cpp
 * @brief   Main menu for Smart Campus Management System
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-07
 *
 * OOP Concepts: Objects, Runtime Polymorphism, Exception Handling
 */

#include "person/Person.h"
#include "person/Student.h"
#include "person/GradStudent.h"
#include "person/Faculty.h"
#include "person/Staff.h"
#include "person/PersonManager.h"
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
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    cout << "\033[2J\033[H";
#endif
}

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

void pauseScreen() {
    string temp;
    cout << "\nPress Enter to continue...";
    getline(cin, temp);
}

string readText(string label, string defaultValue = "") {
    string value;
    cout << label;
    getline(cin, value);

    if (value == "" && defaultValue != "") {
        return defaultValue;
    }

    return value;
}

int readInt(string label, int defaultValue) {
    string value = readText(label);

    if (value == "") {
        return defaultValue;
    }

    stringstream ss(value);
    int number;
    ss >> number;

    if (ss.fail()) {
        cout << "Wrong number. Default value used." << endl;
        return defaultValue;
    }

    return number;
}

double readDouble(string label, double defaultValue) {
    string value = readText(label);

    if (value == "") {
        return defaultValue;
    }

    stringstream ss(value);
    double number;
    ss >> number;

    if (ss.fail()) {
        cout << "Wrong number. Default value used." << endl;
        return defaultValue;
    }

    return number;
}

void showPageTitle(string title) {
    clearScreen();
    Utils::printLine();
    cout << " " << title << endl;
    Utils::printLine();
}

void printTitle(string title) {
    showPageTitle(title);
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

void showAllPeople(PersonManager& personManager) {
    printTitle("SAVED PERSON RECORDS");

    if (personManager.getPersonCount() == 0) {
        cout << "No saved person records found." << endl;
        return;
    }

    for (int i = 0; i < personManager.getPersonCount(); i++) {
        Person* person = personManager.getPerson(i);
        if (person != NULL) {
            person->displayInfo();
            cout << "Type: " << person->getPersonType() << endl;
            cout << "Unique ID: " << person->getUniqueID() << endl;
        }
    }
}

void showStudentList(PersonManager& personManager) {
    printTitle("SAVED STUDENTS");

    Student* students[MAX_PEOPLE];
    int totalStudents = personManager.getStudents(students, MAX_PEOPLE);

    if (totalStudents == 0) {
        cout << "No saved student records found." << endl;
        return;
    }

    for (int i = 0; i < totalStudents; i++) {
        cout << i + 1 << ". " << students[i]->getRollNo() << " | " << students[i]->getName()
             << " | Semester " << students[i]->getSemester()
             << " | GPA " << students[i]->getGPA()
             << " | Grade " << students[i]->calculateGrade() << endl;
    }
}

void addStudentPage(PersonManager& personManager) {
    printTitle("ADD STUDENT");

    string name = readText("Name: ");
    string cnic = readText("CNIC: ");
    int age = readInt("Age: ", 18);
    string contact = readText("Contact: ");
    string rollNo = readText("Roll No: ");
    int semester = readInt("Semester: ", 2);
    double gpa = readDouble("GPA: ", 0.0);

    if (name == "" || rollNo == "") {
        cout << "Name and roll number are required." << endl;
        return;
    }

    if (personManager.addPerson(new Student(name, cnic, age, contact, rollNo, semester, gpa))) {
        cout << "Student added. Use option 9 to save records." << endl;
    }
}

void addGradStudentPage(PersonManager& personManager) {
    printTitle("ADD GRAD STUDENT");

    string name = readText("Name: ");
    string cnic = readText("CNIC: ");
    int age = readInt("Age: ", 18);
    string contact = readText("Contact: ");
    string rollNo = readText("Roll No: ");
    int semester = readInt("Semester: ", 2);
    double gpa = readDouble("GPA: ", 0.0);
    string thesis = readText("Thesis Title: ");

    if (name == "" || rollNo == "") {
        cout << "Name and roll number are required." << endl;
        return;
    }

    if (personManager.addPerson(new GradStudent(name, cnic, age, contact, rollNo, semester, gpa, thesis))) {
        cout << "Grad student added. Use option 9 to save records." << endl;
    }
}

void addFacultyPage(PersonManager& personManager) {
    printTitle("ADD FACULTY");

    string name = readText("Name: ");
    string cnic = readText("CNIC: ");
    int age = readInt("Age: ", 30);
    string contact = readText("Contact: ");
    string employeeID = readText("Employee ID: ");
    string department = readText("Department: ");
    string designation = readText("Designation: ");

    if (name == "" || employeeID == "") {
        cout << "Name and employee ID are required." << endl;
        return;
    }

    if (personManager.addPerson(new Faculty(name, cnic, age, contact, employeeID, department, designation))) {
        cout << "Faculty added. Use option 9 to save records." << endl;
    }
}

void addStaffPage(PersonManager& personManager) {
    printTitle("ADD STAFF");

    string name = readText("Name: ");
    string cnic = readText("CNIC: ");
    int age = readInt("Age: ", 25);
    string contact = readText("Contact: ");
    string staffID = readText("Staff ID: ");
    string role = readText("Role: ");
    double salary = readDouble("Salary: ", 0);

    if (name == "" || staffID == "") {
        cout << "Name and staff ID are required." << endl;
        return;
    }

    if (personManager.addPerson(new Staff(name, cnic, age, contact, staffID, role, salary))) {
        cout << "Staff added. Use option 9 to save records." << endl;
    }
}

void addCourseToStudentPage(PersonManager& personManager) {
    printTitle("ADD COURSE TO STUDENT");

    string rollNo = readText("Student Roll No: ");
    string courseCode = readText("Course Code: ");

    Person* person = personManager.findByID(rollNo);
    Student* student = dynamic_cast<Student*>(person);

    if (student == NULL) {
        cout << "Student not found." << endl;
        return;
    }

    if (courseCode == "") {
        cout << "Course code is required." << endl;
        return;
    }

    student->addCourse(courseCode);
    cout << "Course added to student for this session." << endl;
}

void deletePersonPage(PersonManager& personManager) {
    printTitle("DELETE PERSON RECORD");

    string id = readText("Enter Roll No / Employee ID / Staff ID: ");

    if (personManager.deleteByID(id)) {
        cout << "Record deleted. Use option 9 to save records." << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

void personMenu(PersonManager& personManager) {
    int choice;

    do {
        showPageTitle("PERSON MODULE");
        cout << "1. Show all saved people" << endl;
        cout << "2. Show saved students" << endl;
        cout << "3. Add Student" << endl;
        cout << "4. Add Grad Student" << endl;
        cout << "5. Add Faculty" << endl;
        cout << "6. Add Staff" << endl;
        cout << "7. Add course to student" << endl;
        cout << "8. Delete person by ID" << endl;
        cout << "9. Save records" << endl;
        cout << "10. Reload records" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            showAllPeople(personManager);
            pauseScreen();
        } else if (choice == 2) {
            showStudentList(personManager);
            pauseScreen();
        } else if (choice == 3) {
            addStudentPage(personManager);
            pauseScreen();
        } else if (choice == 4) {
            addGradStudentPage(personManager);
            pauseScreen();
        } else if (choice == 5) {
            addFacultyPage(personManager);
            pauseScreen();
        } else if (choice == 6) {
            addStaffPage(personManager);
            pauseScreen();
        } else if (choice == 7) {
            addCourseToStudentPage(personManager);
            pauseScreen();
        } else if (choice == 8) {
            deletePersonPage(personManager);
            pauseScreen();
        } else if (choice == 9) {
            printTitle("SAVE PERSON RECORDS");
            personManager.saveToFile();
            cout << "Records saved to data/person_records.txt" << endl;
            pauseScreen();
        } else if (choice == 10) {
            printTitle("RELOAD PERSON RECORDS");
            personManager.loadFromFile();
            cout << "Records reloaded from data/person_records.txt" << endl;
            pauseScreen();
        } else if (choice != 0) {
            printTitle("WRONG CHOICE");
            cout << "Wrong choice. Try again." << endl;
            pauseScreen();
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

void showEnrollmentDemo(Student& s1, Student& s2, Course& oopCourse, bool& enrollmentDone) {
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

    Enrollment e1(&s1, &oopCourse, Utils::getTodayDate());
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

void showWaitingListMergeDemo(Student& s1, Student& s2, Student& s3, Faculty& faculty) {
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

void courseMenu(PersonManager& personManager) {
    Student* s1 = personManager.getStudentAt(0);
    Student* s2 = personManager.getStudentAt(1);
    Student* s3 = personManager.getStudentAt(2);
    Faculty* faculty = personManager.getFirstFaculty();

    if (s1 == NULL || s2 == NULL || s3 == NULL || faculty == NULL) {
        printTitle("COURSE MODULE");
        cout << "Add at least 3 students and 1 faculty in Person Module first." << endl;
        pauseScreen();
        return;
    }

    Course oopCourse("CS-104L", "Object Oriented Programming Lab", 1, faculty, 1);
    int choice;
    bool enrollmentDone = false;

    do {
        showPageTitle("COURSE AND ENROLLMENT MODULE");
        cout << "1. Show course details" << endl;
        cout << "2. Run enrollment demo" << endl;
        cout << "3. Show enrolled and waiting students" << endl;
        cout << "4. Compare courses using ==" << endl;
        cout << "5. Merge waiting lists using +" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            showCourseDemo(oopCourse);
            pauseScreen();
        } else if (choice == 2) {
            showEnrollmentDemo(*s1, *s2, oopCourse, enrollmentDone);
            pauseScreen();
        } else if (choice == 3) {
            showCourseRosterDemo(oopCourse);
            pauseScreen();
        } else if (choice == 4) {
            showCourseCompareDemo(oopCourse, *faculty);
            pauseScreen();
        } else if (choice == 5) {
            showWaitingListMergeDemo(*s1, *s2, *s3, *faculty);
            pauseScreen();
        } else if (choice != 0) {
            printTitle("WRONG CHOICE");
            cout << "Wrong choice. Try again." << endl;
            pauseScreen();
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
        showPageTitle("LIBRARY MODULE");
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
            printTitle("LOAD LIBRARY CATALOG");
            library.loadCatalog("data/library_catalog.txt");
            cout << "Catalog loaded. Total items: " << library.getItemCount() << endl;
            pauseScreen();
        } else if (choice == 2) {
            showLibraryCatalog(library);
            pauseScreen();
        } else if (choice == 3) {
            showLibrarySearch(library);
            pauseScreen();
        } else if (choice == 4) {
            showLibraryIssue(library);
            pauseScreen();
        } else if (choice == 5) {
            showLibraryReturn(library);
            pauseScreen();
        } else if (choice == 6) {
            printTitle("ISSUED RECORDS");
            library.displayIssuedRecords();
            pauseScreen();
        } else if (choice == 7) {
            printTitle("SAVE LIBRARY CATALOG");
            loadLibraryIfNeeded(library);
            library.saveCatalog("data/library_catalog_saved.txt");
            cout << "Catalog saved to data/library_catalog_saved.txt" << endl;
            pauseScreen();
        } else if (choice != 0) {
            printTitle("WRONG CHOICE");
            cout << "Wrong choice. Try again." << endl;
            pauseScreen();
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

void financeMenu(PersonManager& personManager) {
    Student* s1 = personManager.getFirstStudent();

    if (s1 == NULL) {
        printTitle("FEE AND FINANCE MODULE");
        cout << "Add at least 1 student in Person Module first." << endl;
        pauseScreen();
        return;
    }

    int choice;

    do {
        showPageTitle("FEE AND FINANCE MODULE");
        cout << "1. Show fee record and payment" << endl;
        cout << "2. Show fee copy constructor and assignment" << endl;
        cout << "3. Show invoice, copies, and static counter" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            showFeeRecordDemo(*s1);
            pauseScreen();
        } else if (choice == 2) {
            showFeeCopyDemo(*s1);
            pauseScreen();
        } else if (choice == 3) {
            showInvoiceDemo(*s1);
            pauseScreen();
        } else if (choice != 0) {
            printTitle("WRONG CHOICE");
            cout << "Wrong choice. Try again." << endl;
            pauseScreen();
        }
    } while (choice != 0);
}

void hostelMenu(PersonManager& personManager) {
    Student* s1 = personManager.getStudentAt(0);
    Student* s2 = personManager.getStudentAt(1);
    Student* s3 = personManager.getStudentAt(2);

    if (s1 == NULL || s2 == NULL || s3 == NULL) {
        printTitle("HOSTEL MODULE");
        cout << "Add at least 3 students in Person Module first." << endl;
        pauseScreen();
        return;
    }

    HostelManager manager;
    int choice;
    bool allocated = false;

    do {
        showPageTitle("HOSTEL MODULE");
        cout << "1. Show hostel service name" << endl;
        cout << "2. Allocate sample students" << endl;
        cout << "3. Try duplicate allocation" << endl;
        cout << "4. Show hostel summary" << endl;
        cout << "5. Show occupancy report" << endl;
        cout << "6. Vacate first student room" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            printTitle("HOSTEL SERVICE");
            manager.showServiceName();
            pauseScreen();
        } else if (choice == 2) {
            printTitle("ALLOCATE SAMPLE STUDENTS");
            if (!allocated) {
                manager.allocateRoom(s1);
                manager.allocateRoom(s2);
                manager.allocateRoom(s3);
                allocated = true;
            } else {
                cout << "Students are already allocated in this module visit." << endl;
            }
            pauseScreen();
        } else if (choice == 3) {
            printTitle("DUPLICATE ALLOCATION CHECK");
            manager.allocateRoom(s1);
            pauseScreen();
        } else if (choice == 4) {
            printTitle("HOSTEL SUMMARY");
            manager.showSummary();
            pauseScreen();
        } else if (choice == 5) {
            printTitle("HOSTEL OCCUPANCY REPORT");
            manager.generateReport();
            pauseScreen();
        } else if (choice == 6) {
            printTitle("VACATE ROOM");
            manager.vacateRoom(s1->getRollNo());
            pauseScreen();
        } else if (choice != 0) {
            printTitle("WRONG CHOICE");
            cout << "Wrong choice. Try again." << endl;
            pauseScreen();
        }
    } while (choice != 0);
}

void reportsMenu(PersonManager& personManager, Library& library) {
    Student* students[MAX_PEOPLE];
    int studentCount = personManager.getStudents(students, MAX_PEOPLE);

    if (studentCount == 0) {
        printTitle("REPORTS MODULE");
        cout << "Add at least 1 student in Person Module first." << endl;
        pauseScreen();
        return;
    }

    int choice;

    do {
        showPageTitle("REPORTS MODULE");
        cout << "1. Sort and show students by GPA" << endl;
        cout << "2. Find student by roll number" << endl;
        cout << "3. Show top GPA student" << endl;
        cout << "4. Generate campus text report" << endl;
        cout << "5. Generate PDF-style text report" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            printTitle("STUDENTS SORTED BY GPA");
            Reports::sortStudentsByGPA(students, studentCount);
            Reports::showStudents(students, studentCount);
            pauseScreen();
        } else if (choice == 2) {
            printTitle("FIND STUDENT");
            string rollNo = readText("Enter roll no (press Enter for 25-CS-067): ", "25-CS-067");
            Student* found = Reports::findStudentByRollNo(students, studentCount, rollNo);

            if (found != NULL) {
                cout << "Student found:" << endl;
                cout << found->getRollNo() << " - " << found->getName()
                     << " - GPA: " << found->getGPA() << endl;
            } else {
                cout << "Student not found." << endl;
            }
            pauseScreen();
        } else if (choice == 3) {
            printTitle("TOP GPA STUDENT");
            Reports::showTopStudent(students, studentCount);
            pauseScreen();
        } else if (choice == 4) {
            printTitle("GENERATE CAMPUS TEXT REPORT");
            loadLibraryIfNeeded(library);
            Reports::generateCampusTextReport(students, studentCount, library, "data/campus_report.txt");
            pauseScreen();
        } else if (choice == 5) {
            printTitle("GENERATE PDF-STYLE TEXT REPORT");
            loadLibraryIfNeeded(library);
            Reports::generatePdfStyleTextReport(students, studentCount, library, "data/campus_pdf_report.txt");
            pauseScreen();
        } else if (choice != 0) {
            printTitle("WRONG CHOICE");
            cout << "Wrong choice. Try again." << endl;
            pauseScreen();
        }
    } while (choice != 0);
}

void showHomeMenu() {
    showPageTitle("SMART CAMPUS MANAGEMENT SYSTEM");
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
    PersonManager personManager("data/person_records.txt");
    personManager.loadFromFile();
    Library library;
    int choice;

    do {
        showHomeMenu();
        choice = readChoice();

        if (choice == 1) {
            personMenu(personManager);
        } else if (choice == 2) {
            courseMenu(personManager);
        } else if (choice == 3) {
            libraryMenu(library);
        } else if (choice == 4) {
            financeMenu(personManager);
        } else if (choice == 5) {
            hostelMenu(personManager);
        } else if (choice == 6) {
            reportsMenu(personManager, library);
        } else if (choice == 0) {
            printTitle("PROGRAM CLOSED");
        } else {
            printTitle("WRONG CHOICE");
            cout << "Wrong choice. Try again." << endl;
            pauseScreen();
        }
    } while (choice != 0);

    return 0;
}

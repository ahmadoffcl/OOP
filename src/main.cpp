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
#include "course/CourseManager.h"
#include "library/Book.h"
#include "library/Journal.h"
#include "library/Library.h"
#include "finance/FeeRecord.h"
#include "finance/Invoice.h"
#include "finance/FinanceManager.h"
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
        library.loadIssuedRecords("data/library_issued.txt");

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

int showFacultyChoices(PersonManager& personManager) {
    int count = 0;
    cout << "Saved Faculty:" << endl;

    for (int i = 0; i < personManager.getPersonCount(); i++) {
        Faculty* faculty = dynamic_cast<Faculty*>(personManager.getPerson(i));

        if (faculty != NULL) {
            count++;
            cout << count << ". " << faculty->getEmployeeID()
                 << " | " << faculty->getName()
                 << " | " << faculty->getDepartment() << endl;
        }
    }

    if (count == 0) {
        cout << "No faculty saved." << endl;
    }

    return count;
}

void showCourseListPage(CourseManager& courseManager) {
    printTitle("SAVED COURSES");
    courseManager.showAllCourses();
}

void addCoursePage(CourseManager& courseManager, PersonManager& personManager) {
    printTitle("ADD COURSE");

    if (personManager.getFirstFaculty() == NULL) {
        cout << "Add at least 1 faculty in Person Module first." << endl;
        return;
    }

    showFacultyChoices(personManager);
    Utils::printSmallLine();

    string code = readText("Course Code: ");
    string name = readText("Course Name: ");
    int hours = readInt("Credit Hours: ", 3);
    int capacity = readInt("Max Capacity: ", 30);
    string facultyID = readText("Instructor Employee ID: ");

    if (code == "" || name == "" || facultyID == "") {
        cout << "Course code, name, and instructor ID are required." << endl;
        return;
    }

    Faculty* faculty = dynamic_cast<Faculty*>(personManager.findByID(facultyID));
    if (faculty == NULL) {
        cout << "Faculty not found." << endl;
        return;
    }

    if (hours <= 0 || capacity <= 0) {
        cout << "Credit hours and capacity must be positive." << endl;
        return;
    }

    if (courseManager.addCourse(Course(code, name, hours, faculty, capacity))) {
        faculty->assignCourse(code);
        cout << "Course added. Use option 10 to save records." << endl;
    }
}

void searchCoursePage(CourseManager& courseManager) {
    printTitle("SEARCH COURSE");

    string code = readText("Course Code: ");
    Course* course = courseManager.findCourseByCode(code);

    if (course == NULL) {
        cout << "Course not found." << endl;
        return;
    }

    cout << *course;
}

void enrollStudentPage(CourseManager& courseManager, PersonManager& personManager) {
    printTitle("ENROLL STUDENT");

    Student* students[MAX_PEOPLE];
    int totalStudents = personManager.getStudents(students, MAX_PEOPLE);

    if (totalStudents == 0) {
        cout << "Add students in Person Module first." << endl;
        return;
    }

    if (courseManager.getCourseCount() == 0) {
        cout << "Add at least 1 course first." << endl;
        return;
    }

    cout << "Saved Students:" << endl;
    for (int i = 0; i < totalStudents; i++) {
        cout << i + 1 << ". " << students[i]->getRollNo()
             << " | " << students[i]->getName() << endl;
    }

    Utils::printSmallLine();
    cout << "Saved Courses:" << endl;
    courseManager.showAllCourses();
    Utils::printSmallLine();

    string rollNo = readText("Student Roll No: ");
    string courseCode = readText("Course Code: ");

    if (rollNo == "" || courseCode == "") {
        cout << "Roll number and course code are required." << endl;
        return;
    }

    if (courseManager.enrollStudent(rollNo, courseCode, personManager)) {
        cout << "Use option 10 to save records." << endl;
    }
}

void showCourseRosterPage(CourseManager& courseManager) {
    printTitle("COURSE ROSTER");

    string code = readText("Course Code: ");
    Course* course = courseManager.findCourseByCode(code);

    if (course == NULL) {
        cout << "Course not found." << endl;
        return;
    }

    cout << *course;
    course->displayEnrolledStudents();
    course->displayWaitingList();
}

void dropStudentPage(CourseManager& courseManager) {
    printTitle("DROP STUDENT FROM COURSE");

    string courseCode = readText("Course Code: ");
    string rollNo = readText("Student Roll No: ");

    if (courseCode == "" || rollNo == "") {
        cout << "Course code and roll number are required." << endl;
        return;
    }

    if (courseManager.dropStudent(rollNo, courseCode)) {
        cout << "Use option 10 to save records." << endl;
    }
}

void compareCoursesPage(CourseManager& courseManager) {
    printTitle("COMPARE COURSES USING ==");

    string code1 = readText("First Course Code: ");
    string code2 = readText("Second Course Code: ");

    Course* first = courseManager.findCourseByCode(code1);
    Course* second = courseManager.findCourseByCode(code2);

    if (first == NULL || second == NULL) {
        cout << "One or both courses were not found." << endl;
        return;
    }

    if (*first == *second) {
        cout << "Both courses are equal because course code is same." << endl;
    } else {
        cout << "Courses are not equal because course codes are different." << endl;
    }
}

void mergeWaitingListsPage(CourseManager& courseManager) {
    printTitle("MERGE WAITING LISTS USING +");

    string code1 = readText("First Course Code: ");
    string code2 = readText("Second Course Code: ");

    Course* first = courseManager.findCourseByCode(code1);
    Course* second = courseManager.findCourseByCode(code2);

    if (first == NULL || second == NULL) {
        cout << "One or both courses were not found." << endl;
        return;
    }

    Student** merged = *first + *second;
    int total = first->getWaitingCount() + second->getWaitingCount();

    if (total == 0) {
        cout << "No students in both waiting lists." << endl;
    } else {
        cout << "Merged Waiting List:" << endl;
        for (int i = 0; i < total; i++) {
            if (merged[i] != NULL) {
                cout << i + 1 << ". " << merged[i]->getName()
                     << " (" << merged[i]->getRollNo() << ")" << endl;
            }
        }
    }

    delete[] merged;
}

void showEnrollmentRecordsPage(CourseManager& courseManager) {
    printTitle("ENROLLMENT RECORDS");
    courseManager.rebuildEnrollmentRecords();
    courseManager.showEnrollmentRecords();
}

void courseMenu(CourseManager& courseManager, PersonManager& personManager) {
    int choice;

    do {
        showPageTitle("COURSE AND ENROLLMENT MODULE");
        cout << "1. Show all courses" << endl;
        cout << "2. Add course" << endl;
        cout << "3. Search course by code" << endl;
        cout << "4. Enroll student in course" << endl;
        cout << "5. Show course roster" << endl;
        cout << "6. Drop student from course" << endl;
        cout << "7. Compare two courses using ==" << endl;
        cout << "8. Merge waiting lists using +" << endl;
        cout << "9. Show enrollment records" << endl;
        cout << "10. Save course/enrollment records" << endl;
        cout << "11. Reload course/enrollment records" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            showCourseListPage(courseManager);
            pauseScreen();
        } else if (choice == 2) {
            addCoursePage(courseManager, personManager);
            pauseScreen();
        } else if (choice == 3) {
            searchCoursePage(courseManager);
            pauseScreen();
        } else if (choice == 4) {
            enrollStudentPage(courseManager, personManager);
            pauseScreen();
        } else if (choice == 5) {
            showCourseRosterPage(courseManager);
            pauseScreen();
        } else if (choice == 6) {
            dropStudentPage(courseManager);
            pauseScreen();
        } else if (choice == 7) {
            compareCoursesPage(courseManager);
            pauseScreen();
        } else if (choice == 8) {
            mergeWaitingListsPage(courseManager);
            pauseScreen();
        } else if (choice == 9) {
            showEnrollmentRecordsPage(courseManager);
            pauseScreen();
        } else if (choice == 10) {
            printTitle("SAVE COURSE AND ENROLLMENT RECORDS");
            courseManager.saveAll();
            cout << "Records saved to data/courses.txt and data/enrollments.txt" << endl;
            pauseScreen();
        } else if (choice == 11) {
            printTitle("RELOAD COURSE AND ENROLLMENT RECORDS");
            courseManager.loadAll(personManager);
            cout << "Records reloaded from data/courses.txt and data/enrollments.txt" << endl;
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

void addBookPage(Library& library) {
    loadLibraryIfNeeded(library);
    printTitle("ADD BOOK");

    string itemID = readText("Item ID: ");
    string title = readText("Title: ");
    string author = readText("Author: ");
    int year = readInt("Publication Year: ", 2026);
    string isbn = readText("ISBN: ");
    string genre = readText("Genre: ");
    int copies = readInt("Copies Available: ", 1);

    if (itemID == "" || title == "") {
        cout << "Item ID and title are required." << endl;
        return;
    }

    if (copies < 0) {
        copies = 0;
    }

    if (library.addItem(new Book(itemID, title, author, year, isbn, genre, copies))) {
        cout << "Book added. Use option 10 to save records." << endl;
    }
}

void addJournalPage(Library& library) {
    loadLibraryIfNeeded(library);
    printTitle("ADD JOURNAL");

    string itemID = readText("Item ID: ");
    string title = readText("Title: ");
    string author = readText("Author: ");
    int year = readInt("Publication Year: ", 2026);
    string issn = readText("ISSN: ");
    int volume = readInt("Volume: ", 1);
    int issueNumber = readInt("Issue Number: ", 1);

    if (itemID == "" || title == "") {
        cout << "Item ID and title are required." << endl;
        return;
    }

    if (volume < 0) {
        volume = 0;
    }

    if (issueNumber < 0) {
        issueNumber = 0;
    }

    if (library.addItem(new Journal(itemID, title, author, year, issn, volume, issueNumber))) {
        cout << "Journal added. Use option 10 to save records." << endl;
    }
}

void searchLibraryByTitlePage(Library& library) {
    loadLibraryIfNeeded(library);
    printTitle("SEARCH LIBRARY BY TITLE");

    string title = readText("Title: ");

    if (title == "") {
        cout << "Title is required." << endl;
        return;
    }

    LibraryItem* found = library.searchByTitle(title);
    if (found != NULL) {
        found->displayItem();
    } else {
        cout << "Item not found." << endl;
    }
}

void searchLibraryByIDPage(Library& library) {
    loadLibraryIfNeeded(library);
    printTitle("SEARCH LIBRARY BY ID");

    string itemID = readText("Item ID: ");

    if (itemID == "") {
        cout << "Item ID is required." << endl;
        return;
    }

    LibraryItem* found = library.searchByID(itemID);
    if (found != NULL) {
        found->displayItem();
    } else {
        cout << "Item not found." << endl;
    }
}

int showLibraryStudents(PersonManager& personManager) {
    Student* students[MAX_PEOPLE];
    int totalStudents = personManager.getStudents(students, MAX_PEOPLE);

    cout << "Saved Students:" << endl;
    if (totalStudents == 0) {
        cout << "No saved students." << endl;
    }

    for (int i = 0; i < totalStudents; i++) {
        cout << i + 1 << ". " << students[i]->getRollNo()
             << " | " << students[i]->getName() << endl;
    }

    return totalStudents;
}

void issueLibraryItemPage(Library& library, PersonManager& personManager) {
    loadLibraryIfNeeded(library);
    printTitle("ISSUE LIBRARY ITEM");

    if (showLibraryStudents(personManager) == 0) {
        cout << "Add students in Person Module first." << endl;
        return;
    }

    Utils::printSmallLine();
    library.showAllItems();
    Utils::printSmallLine();

    string rollNo = readText("Student Roll No: ");
    string itemID = readText("Item ID: ");

    Student* student = dynamic_cast<Student*>(personManager.findByID(rollNo));
    if (student == NULL) {
        cout << "Student not found." << endl;
        return;
    }

    if (itemID == "") {
        cout << "Item ID is required." << endl;
        return;
    }

    if (library.issueItem(rollNo, itemID)) {
        cout << "Use option 10 to save records." << endl;
    }
}

void returnLibraryItemPage(Library& library, PersonManager& personManager) {
    loadLibraryIfNeeded(library);
    printTitle("RETURN LIBRARY ITEM");

    if (showLibraryStudents(personManager) == 0) {
        cout << "Add students in Person Module first." << endl;
        return;
    }

    Utils::printSmallLine();
    library.displayIssuedRecords();
    Utils::printSmallLine();

    string rollNo = readText("Student Roll No: ");
    string itemID = readText("Item ID: ");
    int daysLate = readInt("Days Late: ", 0);

    Student* student = dynamic_cast<Student*>(personManager.findByID(rollNo));
    if (student == NULL) {
        cout << "Student not found." << endl;
        return;
    }

    if (itemID == "") {
        cout << "Item ID is required." << endl;
        return;
    }

    if (daysLate < 0) {
        daysLate = 0;
    }

    bool returned = false;
    try {
        returned = library.returnItem(rollNo, itemID, daysLate);
    } catch (OverdueException& e) {
        cout << "Fine Error: " << e.what() << endl;
        returned = true;
    }

    if (returned) {
        cout << "Use option 10 to save records." << endl;
    }
}

void deleteLibraryItemPage(Library& library) {
    loadLibraryIfNeeded(library);
    printTitle("DELETE LIBRARY ITEM");

    string itemID = readText("Item ID: ");

    if (itemID == "") {
        cout << "Item ID is required." << endl;
        return;
    }

    if (library.deleteItemByID(itemID)) {
        cout << "Item deleted. Use option 10 to save records." << endl;
    } else {
        cout << "Item not deleted." << endl;
    }
}

void saveLibraryRecordsPage(Library& library) {
    loadLibraryIfNeeded(library);
    printTitle("SAVE LIBRARY RECORDS");

    library.saveCatalog("data/library_catalog.txt");
    library.saveIssuedRecords("data/library_issued.txt");
    cout << "Records saved to data/library_catalog.txt and data/library_issued.txt" << endl;
}

void reloadLibraryRecordsPage(Library& library) {
    printTitle("RELOAD LIBRARY RECORDS");

    library.loadCatalog("data/library_catalog.txt");
    library.loadIssuedRecords("data/library_issued.txt");
    cout << "Catalog items: " << library.getItemCount() << endl;
    cout << "Issued records: " << library.getIssuedCount() << endl;
}

void libraryMenu(Library& library, PersonManager& personManager) {
    int choice;

    do {
        showPageTitle("LIBRARY MODULE");
        cout << "1. Show catalog" << endl;
        cout << "2. Add Book" << endl;
        cout << "3. Add Journal" << endl;
        cout << "4. Search by title" << endl;
        cout << "5. Search by item ID" << endl;
        cout << "6. Issue item" << endl;
        cout << "7. Return item" << endl;
        cout << "8. Show issued records" << endl;
        cout << "9. Delete item by ID" << endl;
        cout << "10. Save library records" << endl;
        cout << "11. Reload library records" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            showLibraryCatalog(library);
            pauseScreen();
        } else if (choice == 2) {
            addBookPage(library);
            pauseScreen();
        } else if (choice == 3) {
            addJournalPage(library);
            pauseScreen();
        } else if (choice == 4) {
            searchLibraryByTitlePage(library);
            pauseScreen();
        } else if (choice == 5) {
            searchLibraryByIDPage(library);
            pauseScreen();
        } else if (choice == 6) {
            issueLibraryItemPage(library, personManager);
            pauseScreen();
        } else if (choice == 7) {
            returnLibraryItemPage(library, personManager);
            pauseScreen();
        } else if (choice == 8) {
            printTitle("ISSUED RECORDS");
            loadLibraryIfNeeded(library);
            library.displayIssuedRecords();
            pauseScreen();
        } else if (choice == 9) {
            deleteLibraryItemPage(library);
            pauseScreen();
        } else if (choice == 10) {
            saveLibraryRecordsPage(library);
            pauseScreen();
        } else if (choice == 11) {
            reloadLibraryRecordsPage(library);
            pauseScreen();
        } else if (choice != 0) {
            printTitle("WRONG CHOICE");
            cout << "Wrong choice. Try again." << endl;
            pauseScreen();
        }
    } while (choice != 0);
}

int showFinanceStudents(PersonManager& personManager) {
    Student* students[MAX_PEOPLE];
    int totalStudents = personManager.getStudents(students, MAX_PEOPLE);

    cout << "Saved Students:" << endl;
    if (totalStudents == 0) {
        cout << "No saved students." << endl;
    }

    for (int i = 0; i < totalStudents; i++) {
        cout << i + 1 << ". " << students[i]->getRollNo()
             << " | " << students[i]->getName() << endl;
    }

    return totalStudents;
}

string moneyLine(string label, double amount) {
    stringstream ss;
    ss << label << ": Rs. " << amount;
    return ss.str();
}

void showAllFeeRecordsPage(FinanceManager& financeManager) {
    printTitle("SAVED FEE RECORDS");
    financeManager.showAllRecords();
}

void addFeeRecordPage(FinanceManager& financeManager, PersonManager& personManager) {
    printTitle("ADD FEE RECORD");

    if (showFinanceStudents(personManager) == 0) {
        cout << "Add at least 1 student in Person Module first." << endl;
        return;
    }

    Utils::printSmallLine();
    string rollNo = readText("Student Roll No: ");
    double semesterFee = readDouble("Semester Fee: ", 65000);
    double hostelFee = readDouble("Hostel Fee: ", 0);
    double libraryFine = readDouble("Library Fine: ", 0);

    Student* student = dynamic_cast<Student*>(personManager.findByID(rollNo));
    if (student == NULL) {
        cout << "Student not found." << endl;
        return;
    }

    if (semesterFee < 0) {
        semesterFee = 0;
    }

    if (hostelFee < 0) {
        hostelFee = 0;
    }

    if (libraryFine < 0) {
        libraryFine = 0;
    }

    if (financeManager.addRecord(student, semesterFee, hostelFee, libraryFine)) {
        cout << "Fee record added. Use option 9 to save records." << endl;
    }
}

void searchFeeRecordPage(FinanceManager& financeManager) {
    printTitle("SEARCH FEE RECORD");

    string rollNo = readText("Student Roll No: ");
    FeeRecord* record = financeManager.findRecordByRollNo(rollNo);

    if (record == NULL) {
        cout << "Fee record not found." << endl;
        return;
    }

    record->displayFeeRecord();
}

void recordPaymentPage(FinanceManager& financeManager) {
    printTitle("RECORD PAYMENT USING -=");

    string rollNo = readText("Student Roll No: ");
    double amount = readDouble("Payment Amount: ", 0);

    if (financeManager.recordPayment(rollNo, amount)) {
        cout << "Payment recorded. Use option 9 to save records." << endl;
        FeeRecord* record = financeManager.findRecordByRollNo(rollNo);
        if (record != NULL) {
            record->displayFeeRecord();
        }
    }
}

void addLibraryFinePage(FinanceManager& financeManager) {
    printTitle("ADD LIBRARY FINE");

    string rollNo = readText("Student Roll No: ");
    double amount = readDouble("Fine Amount: ", 0);

    if (financeManager.addFine(rollNo, amount)) {
        cout << "Fine added. Use option 9 to save records." << endl;
        FeeRecord* record = financeManager.findRecordByRollNo(rollNo);
        if (record != NULL) {
            record->displayFeeRecord();
        }
    }
}

void showPaymentHistoryPage(FinanceManager& financeManager) {
    printTitle("PAYMENT HISTORY");

    string rollNo = readText("Student Roll No: ");
    FeeRecord* record = financeManager.findRecordByRollNo(rollNo);

    if (record == NULL) {
        cout << "Fee record not found." << endl;
        return;
    }

    record->displayPayments();
}

void generateInvoicePage(FinanceManager& financeManager) {
    printTitle("GENERATE INVOICE");

    string rollNo = readText("Student Roll No: ");
    FeeRecord* record = financeManager.findRecordByRollNo(rollNo);

    if (record == NULL) {
        cout << "Fee record not found." << endl;
        return;
    }

    cout << "Invoice counter before: " << Invoice::getInvoiceCounter() << endl;

    string invoiceItems[5];
    invoiceItems[0] = moneyLine("Semester Fee", record->getSemesterFee());
    invoiceItems[1] = moneyLine("Hostel Fee", record->getHostelFee());
    invoiceItems[2] = moneyLine("Library Fine", record->getLibraryFine());
    invoiceItems[3] = moneyLine("Total Paid", record->getTotalPaid());
    invoiceItems[4] = moneyLine("Balance Due", record->getBalance());

    Invoice invoice(Utils::getTodayDate(), invoiceItems, 5, record->getBalance());
    cout << invoice;

    Invoice copiedInvoice = invoice;
    cout << "\nCopied invoice:" << endl;
    cout << copiedInvoice;

    Invoice assignedInvoice;
    assignedInvoice = invoice;
    cout << "\nAssigned invoice:" << endl;
    cout << assignedInvoice;

    cout << "\nInvoice counter after: " << Invoice::getInvoiceCounter() << endl;
}

void showFeeCopyPage(FinanceManager& financeManager) {
    printTitle("FEE COPY CONSTRUCTOR AND ASSIGNMENT");

    string rollNo = readText("Student Roll No: ");
    FeeRecord* record = financeManager.findRecordByRollNo(rollNo);

    if (record == NULL) {
        cout << "Fee record not found." << endl;
        return;
    }

    cout << "\nOriginal fee record:" << endl;
    record->displayFeeRecord();
    record->displayPayments();

    FeeRecord copiedFee(*record);
    cout << "\nCopied fee record:" << endl;
    copiedFee.displayFeeRecord();
    copiedFee.displayPayments();

    FeeRecord assignedFee;
    assignedFee = *record;
    cout << "\nAssigned fee record:" << endl;
    assignedFee.displayFeeRecord();
    assignedFee.displayPayments();
}

void saveFinanceRecordsPage(FinanceManager& financeManager) {
    printTitle("SAVE FINANCE RECORDS");

    financeManager.saveToFile();
    cout << "Records saved to data/fee_records.txt" << endl;
}

void reloadFinanceRecordsPage(FinanceManager& financeManager, PersonManager& personManager) {
    printTitle("RELOAD FINANCE RECORDS");

    financeManager.loadFromFile(personManager);
    cout << "Records reloaded from data/fee_records.txt" << endl;
    cout << "Total records: " << financeManager.getRecordCount() << endl;
}

void financeMenu(FinanceManager& financeManager, PersonManager& personManager) {
    int choice;

    do {
        showPageTitle("FEE AND FINANCE MODULE");
        cout << "1. Show all fee records" << endl;
        cout << "2. Add fee record" << endl;
        cout << "3. Search fee record by roll no" << endl;
        cout << "4. Record payment using -=" << endl;
        cout << "5. Add library fine" << endl;
        cout << "6. Show payment history" << endl;
        cout << "7. Generate invoice" << endl;
        cout << "8. Show FeeRecord copy constructor/assignment" << endl;
        cout << "9. Save finance records" << endl;
        cout << "10. Reload finance records" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            showAllFeeRecordsPage(financeManager);
            pauseScreen();
        } else if (choice == 2) {
            addFeeRecordPage(financeManager, personManager);
            pauseScreen();
        } else if (choice == 3) {
            searchFeeRecordPage(financeManager);
            pauseScreen();
        } else if (choice == 4) {
            recordPaymentPage(financeManager);
            pauseScreen();
        } else if (choice == 5) {
            addLibraryFinePage(financeManager);
            pauseScreen();
        } else if (choice == 6) {
            showPaymentHistoryPage(financeManager);
            pauseScreen();
        } else if (choice == 7) {
            generateInvoicePage(financeManager);
            pauseScreen();
        } else if (choice == 8) {
            showFeeCopyPage(financeManager);
            pauseScreen();
        } else if (choice == 9) {
            saveFinanceRecordsPage(financeManager);
            pauseScreen();
        } else if (choice == 10) {
            reloadFinanceRecordsPage(financeManager, personManager);
            pauseScreen();
        } else if (choice != 0) {
            printTitle("WRONG CHOICE");
            cout << "Wrong choice. Try again." << endl;
            pauseScreen();
        }
    } while (choice != 0);
}

int showHostelStudents(PersonManager& personManager) {
    Student* students[MAX_PEOPLE];
    int totalStudents = personManager.getStudents(students, MAX_PEOPLE);

    cout << "Saved Students:" << endl;
    if (totalStudents == 0) {
        cout << "No saved students." << endl;
    }

    for (int i = 0; i < totalStudents; i++) {
        cout << i + 1 << ". " << students[i]->getRollNo()
             << " | " << students[i]->getName() << endl;
    }

    return totalStudents;
}

void showAllHostelRoomsPage(HostelManager& hostelManager) {
    printTitle("HOSTEL ROOMS");
    hostelManager.showAllRooms();
}

void addHostelRoomPage(HostelManager& hostelManager) {
    printTitle("ADD HOSTEL ROOM");

    int roomNumber = readInt("Room Number: ", 0);
    string type = readText("Room Type (single/double/triple): ", "triple");
    int floor = readInt("Floor: ", 1);

    if (hostelManager.addRoom(roomNumber, type, floor)) {
        cout << "Room added. Use option 11 to save records." << endl;
    }
}

void searchHostelRoomPage(HostelManager& hostelManager) {
    printTitle("SEARCH HOSTEL ROOM");

    int roomNumber = readInt("Room Number: ", 0);
    Room* room = hostelManager.findRoomByNumber(roomNumber);

    if (room == NULL) {
        cout << "Room not found." << endl;
        return;
    }

    room->displayRoom();
}

void allocateHostelRoomPage(HostelManager& hostelManager, PersonManager& personManager) {
    printTitle("ALLOCATE STUDENT TO ROOM");

    if (showHostelStudents(personManager) == 0) {
        cout << "Add students in Person Module first." << endl;
        return;
    }

    Utils::printSmallLine();
    string rollNo = readText("Student Roll No: ");
    int roomNumber = readInt("Room Number: ", 0);

    Student* student = dynamic_cast<Student*>(personManager.findByID(rollNo));
    if (student == NULL) {
        cout << "Student not found." << endl;
        return;
    }

    hostelManager.allocateRoomToNumber(student, roomNumber);
    cout << "Use option 11 to save records." << endl;
}

void autoAllocateHostelRoomPage(HostelManager& hostelManager, PersonManager& personManager) {
    printTitle("AUTO ALLOCATE STUDENT");

    if (showHostelStudents(personManager) == 0) {
        cout << "Add students in Person Module first." << endl;
        return;
    }

    Utils::printSmallLine();
    string rollNo = readText("Student Roll No: ");

    Student* student = dynamic_cast<Student*>(personManager.findByID(rollNo));
    if (student == NULL) {
        cout << "Student not found." << endl;
        return;
    }

    hostelManager.allocateRoom(student);
    cout << "Use option 11 to save records." << endl;
}

void vacateHostelRoomPage(HostelManager& hostelManager) {
    printTitle("VACATE HOSTEL ROOM");

    string rollNo = readText("Student Roll No: ");
    hostelManager.vacateRoom(rollNo);
    cout << "Use option 11 to save records." << endl;
}

void showStudentHostelRoomPage(HostelManager& hostelManager) {
    printTitle("STUDENT HOSTEL ROOM");

    string rollNo = readText("Student Roll No: ");
    hostelManager.showStudentRoom(rollNo);
}

void deleteHostelRoomPage(HostelManager& hostelManager) {
    printTitle("DELETE HOSTEL ROOM");

    int roomNumber = readInt("Room Number: ", 0);

    if (hostelManager.deleteRoom(roomNumber)) {
        cout << "Room deleted. Use option 11 to save records." << endl;
    }
}

void saveHostelRecordsPage(HostelManager& hostelManager) {
    printTitle("SAVE HOSTEL RECORDS");

    hostelManager.saveToFile();
    cout << "Records saved to data/hostel_rooms.txt and data/hostel_allocations.txt" << endl;
}

void reloadHostelRecordsPage(HostelManager& hostelManager, PersonManager& personManager) {
    printTitle("RELOAD HOSTEL RECORDS");

    hostelManager.loadFromFile(personManager);
    cout << "Records reloaded from hostel files." << endl;
    cout << "Total rooms: " << hostelManager.getRoomCount() << endl;
}

void hostelMenu(HostelManager& hostelManager, PersonManager& personManager) {
    int choice;

    do {
        showPageTitle("HOSTEL MODULE");
        cout << "1. Show hostel service name" << endl;
        cout << "2. Show all rooms" << endl;
        cout << "3. Add room" << endl;
        cout << "4. Search room by number" << endl;
        cout << "5. Allocate student to room" << endl;
        cout << "6. Auto allocate student" << endl;
        cout << "7. Vacate student room" << endl;
        cout << "8. Show student's room" << endl;
        cout << "9. Show hostel summary" << endl;
        cout << "10. Show occupancy report" << endl;
        cout << "11. Save hostel records" << endl;
        cout << "12. Reload hostel records" << endl;
        cout << "13. Delete empty room" << endl;
        printBackOption();
        choice = readChoice();

        if (choice == 1) {
            printTitle("HOSTEL SERVICE");
            hostelManager.showServiceName();
            pauseScreen();
        } else if (choice == 2) {
            showAllHostelRoomsPage(hostelManager);
            pauseScreen();
        } else if (choice == 3) {
            addHostelRoomPage(hostelManager);
            pauseScreen();
        } else if (choice == 4) {
            searchHostelRoomPage(hostelManager);
            pauseScreen();
        } else if (choice == 5) {
            allocateHostelRoomPage(hostelManager, personManager);
            pauseScreen();
        } else if (choice == 6) {
            autoAllocateHostelRoomPage(hostelManager, personManager);
            pauseScreen();
        } else if (choice == 7) {
            vacateHostelRoomPage(hostelManager);
            pauseScreen();
        } else if (choice == 8) {
            showStudentHostelRoomPage(hostelManager);
            pauseScreen();
        } else if (choice == 9) {
            printTitle("HOSTEL SUMMARY");
            hostelManager.showSummary();
            pauseScreen();
        } else if (choice == 10) {
            printTitle("HOSTEL OCCUPANCY REPORT");
            hostelManager.generateReport();
            pauseScreen();
        } else if (choice == 11) {
            saveHostelRecordsPage(hostelManager);
            pauseScreen();
        } else if (choice == 12) {
            reloadHostelRecordsPage(hostelManager, personManager);
            pauseScreen();
        } else if (choice == 13) {
            deleteHostelRoomPage(hostelManager);
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
    CourseManager courseManager("data/courses.txt", "data/enrollments.txt");
    courseManager.loadAll(personManager);
    FinanceManager financeManager("data/fee_records.txt");
    financeManager.loadFromFile(personManager);
    HostelManager hostelManager("data/hostel_rooms.txt", "data/hostel_allocations.txt");
    hostelManager.loadFromFile(personManager);
    Library library;
    int choice;

    do {
        showHomeMenu();
        choice = readChoice();

        if (choice == 1) {
            personMenu(personManager);
            courseManager.loadAll(personManager);
            financeManager.loadFromFile(personManager);
            hostelManager.loadFromFile(personManager);
        } else if (choice == 2) {
            courseMenu(courseManager, personManager);
        } else if (choice == 3) {
            libraryMenu(library, personManager);
        } else if (choice == 4) {
            financeMenu(financeManager, personManager);
        } else if (choice == 5) {
            hostelMenu(hostelManager, personManager);
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

/**
 * @file    PersonManager.cpp
 * @brief   Implementation of the PersonManager class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-07
 *
 * OOP Concepts: File I/O, Arrays, Runtime Polymorphism, Dynamic Memory
 */

#include "PersonManager.h"
#include "GradStudent.h"
#include "Staff.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

PersonManager::PersonManager(string file) {
    fileName = file;
    personCount = 0;

    for (int i = 0; i < MAX_PEOPLE; i++) {
        people[i] = NULL;
    }
}

PersonManager::~PersonManager() {
    clearAll();
}

void PersonManager::clearAll() {
    for (int i = 0; i < personCount; i++) {
        delete people[i];
        people[i] = NULL;
    }

    personCount = 0;
}

bool PersonManager::addPerson(Person* person) {
    if (person == NULL) {
        return false;
    }

    if (personCount >= MAX_PEOPLE) {
        delete person;
        cout << "Person storage is full." << endl;
        return false;
    }

    if (findByID(person->getUniqueID()) != NULL) {
        cout << "A record with this ID already exists." << endl;
        delete person;
        return false;
    }

    people[personCount] = person;
    personCount++;
    return true;
}

bool PersonManager::deleteByID(string id) {
    for (int i = 0; i < personCount; i++) {
        if (people[i] != NULL && people[i]->getUniqueID() == id) {
            delete people[i];

            for (int j = i; j < personCount - 1; j++) {
                people[j] = people[j + 1];
            }

            people[personCount - 1] = NULL;
            personCount--;
            return true;
        }
    }

    return false;
}

Person* PersonManager::findByID(string id) const {
    for (int i = 0; i < personCount; i++) {
        if (people[i] != NULL && people[i]->getUniqueID() == id) {
            return people[i];
        }
    }

    return NULL;
}

void PersonManager::seedDefaultData() {
    clearAll();

    addPerson(new Student("Ahmad Ali", "11111-1111111-1", 19, "0300-0000000", "25-CS-067", 2, 3.4));
    addPerson(new GradStudent("Umer Altaf", "22222-2222222-2", 19, "0311-0000000", "25-CS-057", 2, 3.8, "Campus Management"));
    addPerson(new Student("Muhammed Ahmad", "55555-5555555-5", 19, "0344-0000000", "25-CS-252", 2, 3.2));

    Faculty* faculty = new Faculty("Sir Usman", "33333-3333333-3", 35, "0322-0000000", "F-101", "Computer Science", "Lecturer");
    faculty->assignCourse("CS-104L");
    addPerson(faculty);

    addPerson(new Staff("Office Staff", "44444-4444444-4", 30, "0333-0000000", "S-11", "Clerk", 45000));
}

void PersonManager::loadFromFile() {
    ifstream file(fileName);

    if (!file) {
        seedDefaultData();
        saveToFile();
        return;
    }

    clearAll();

    string line;
    while (getline(file, line)) {
        if (line == "") {
            continue;
        }

        string part[10];
        stringstream ss(line);
        int count = 0;

        while (count < 10 && getline(ss, part[count], '|')) {
            count++;
        }

        try {
            if (count >= 8 && part[0] == "Student") {
                addPerson(new Student(part[1], part[2], stoi(part[3]), part[4], part[5], stoi(part[6]), stod(part[7])));
            } else if (count >= 9 && part[0] == "GradStudent") {
                addPerson(new GradStudent(part[1], part[2], stoi(part[3]), part[4], part[5], stoi(part[6]), stod(part[7]), part[8]));
            } else if (count >= 8 && part[0] == "Faculty") {
                addPerson(new Faculty(part[1], part[2], stoi(part[3]), part[4], part[5], part[6], part[7]));
            } else if (count >= 8 && part[0] == "Staff") {
                addPerson(new Staff(part[1], part[2], stoi(part[3]), part[4], part[5], part[6], stod(part[7])));
            }
        } catch (...) {
            cout << "Skipped wrong person record: " << line << endl;
        }
    }

    file.close();

    if (personCount == 0) {
        seedDefaultData();
        saveToFile();
    }
}

void PersonManager::saveToFile() const {
    ofstream file(fileName);

    if (!file) {
        cout << "Person file could not be opened for saving." << endl;
        return;
    }

    for (int i = 0; i < personCount; i++) {
        Student* student = dynamic_cast<Student*>(people[i]);
        GradStudent* gradStudent = dynamic_cast<GradStudent*>(people[i]);
        Faculty* faculty = dynamic_cast<Faculty*>(people[i]);
        Staff* staff = dynamic_cast<Staff*>(people[i]);

        if (gradStudent != NULL) {
            file << "GradStudent|" << gradStudent->getName() << "|" << gradStudent->getCNIC()
                 << "|" << gradStudent->getAge() << "|" << gradStudent->getContact()
                 << "|" << gradStudent->getRollNo() << "|" << gradStudent->getSemester()
                 << "|" << gradStudent->getGPA() << "|" << gradStudent->getThesisTitle() << endl;
        } else if (student != NULL) {
            file << "Student|" << student->getName() << "|" << student->getCNIC()
                 << "|" << student->getAge() << "|" << student->getContact()
                 << "|" << student->getRollNo() << "|" << student->getSemester()
                 << "|" << student->getGPA() << endl;
        } else if (faculty != NULL) {
            file << "Faculty|" << faculty->getName() << "|" << faculty->getCNIC()
                 << "|" << faculty->getAge() << "|" << faculty->getContact()
                 << "|" << faculty->getEmployeeID() << "|" << faculty->getDepartment()
                 << "|" << faculty->getDesignation() << endl;
        } else if (staff != NULL) {
            file << "Staff|" << staff->getName() << "|" << staff->getCNIC()
                 << "|" << staff->getAge() << "|" << staff->getContact()
                 << "|" << staff->getStaffID() << "|" << staff->getRole()
                 << "|" << staff->getSalary() << endl;
        }
    }

    file.close();
}

int PersonManager::getPersonCount() const {
    return personCount;
}

Person* PersonManager::getPerson(int index) const {
    if (index >= 0 && index < personCount) {
        return people[index];
    }

    return NULL;
}

int PersonManager::getStudents(Student* students[], int maxStudents) const {
    int count = 0;

    for (int i = 0; i < personCount && count < maxStudents; i++) {
        Student* student = dynamic_cast<Student*>(people[i]);
        if (student != NULL) {
            students[count] = student;
            count++;
        }
    }

    return count;
}

Student* PersonManager::getFirstStudent() const {
    return getStudentAt(0);
}

Student* PersonManager::getStudentAt(int studentIndex) const {
    int count = 0;

    for (int i = 0; i < personCount; i++) {
        Student* student = dynamic_cast<Student*>(people[i]);
        if (student != NULL) {
            if (count == studentIndex) {
                return student;
            }
            count++;
        }
    }

    return NULL;
}

Faculty* PersonManager::getFirstFaculty() const {
    for (int i = 0; i < personCount; i++) {
        Faculty* faculty = dynamic_cast<Faculty*>(people[i]);
        if (faculty != NULL) {
            return faculty;
        }
    }

    return NULL;
}

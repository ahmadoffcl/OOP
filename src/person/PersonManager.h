/**
 * @file    PersonManager.h
 * @brief   Array based manager for saved people in SCMS
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-07
 *
 * OOP Concepts: Array of Base Pointers, Runtime Polymorphism, File I/O
 */

#ifndef PERSONMANAGER_H
#define PERSONMANAGER_H

#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include <string>
using namespace std;

const int MAX_PEOPLE = 50;

class PersonManager {
private:
    Person* people[MAX_PEOPLE];
    int personCount;
    string fileName;

public:
    PersonManager(string file);
    ~PersonManager();

    void clearAll();
    bool addPerson(Person* person);
    bool deleteByID(string id);
    Person* findByID(string id) const;
    void seedDefaultData();
    void loadFromFile();
    void saveToFile() const;

    int getPersonCount() const;
    Person* getPerson(int index) const;
    int getStudents(Student* students[], int maxStudents) const;
    Student* getFirstStudent() const;
    Student* getStudentAt(int studentIndex) const;
    Faculty* getFirstFaculty() const;
};

#endif

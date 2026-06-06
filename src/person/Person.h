/**
 * @file    Person.h
 * @brief   Abstract base class for people in SCMS
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Abstract Class, Encapsulation, Runtime Polymorphism
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    string cnic;
    int age;
    string contact;

public:
    Person();
    Person(string n, string c, int a, string con);
    Person(const Person& other);
    virtual ~Person();

    void setName(string n);
    void setCNIC(string c);
    void setAge(int a);
    void setContact(string con);

    string getName() const;
    string getCNIC() const;
    int getAge() const;
    string getContact() const;

    virtual void displayInfo() const = 0;
};

#endif

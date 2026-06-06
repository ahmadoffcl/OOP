/**
 * @file    Person.cpp
 * @brief   Implementation of the Person class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Constructor, Copy Constructor, Encapsulation
 */

#include "Person.h"

Person::Person() {
    name = "No Name";
    cnic = "00000-0000000-0";
    age = 0;
    contact = "N/A";
}

Person::Person(string n, string c, int a, string con) {
    name = n;
    cnic = c;
    age = a;
    contact = con;
}

Person::Person(const Person& other) {
    name = other.name;
    cnic = other.cnic;
    age = other.age;
    contact = other.contact;
}

Person::~Person() {
}

void Person::setName(string n) {
    name = n;
}

void Person::setCNIC(string c) {
    cnic = c;
}

void Person::setAge(int a) {
    age = a;
}

void Person::setContact(string con) {
    contact = con;
}

string Person::getName() const {
    return name;
}

string Person::getCNIC() const {
    return cnic;
}

int Person::getAge() const {
    return age;
}

string Person::getContact() const {
    return contact;
}

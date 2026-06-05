/**
 * @file    FeeRecord.cpp
 * @brief   Implementation of the FeeRecord class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Copy Constructor, Copy Assignment, Operator -=
 */

#include "FeeRecord.h"
#include <iostream>
using namespace std;

FeeRecord::FeeRecord() {
    studentRef = NULL;
    semesterFee = 0;
    hostelFee = 0;
    libraryFine = 0;
    totalPaid = 0;
    balance = 0;
}

FeeRecord::FeeRecord(Student* st, double semFee, double hostFee, double fine) {
    studentRef = st;
    semesterFee = semFee;
    hostelFee = hostFee;
    libraryFine = fine;
    totalPaid = 0;
    calculateBalance();
}

FeeRecord::FeeRecord(const FeeRecord& other) {
    studentRef = other.studentRef;
    semesterFee = other.semesterFee;
    hostelFee = other.hostelFee;
    libraryFine = other.libraryFine;
    totalPaid = other.totalPaid;
    balance = other.balance;
}

FeeRecord& FeeRecord::operator=(const FeeRecord& other) {
    if (this != &other) {
        studentRef = other.studentRef;
        semesterFee = other.semesterFee;
        hostelFee = other.hostelFee;
        libraryFine = other.libraryFine;
        totalPaid = other.totalPaid;
        balance = other.balance;
    }

    return *this;
}

void FeeRecord::calculateBalance() {
    balance = semesterFee + hostelFee + libraryFine - totalPaid;
}

void FeeRecord::addLibraryFine(double fine) {
    libraryFine = libraryFine + fine;
    calculateBalance();
}

double FeeRecord::getBalance() const {
    return balance;
}

FeeRecord& FeeRecord::operator-=(double payment) {
    totalPaid = totalPaid + payment;
    calculateBalance();
    return *this;
}

void FeeRecord::displayFeeRecord() const {
    cout << "\n--- Fee Record ---" << endl;

    if (studentRef != NULL) {
        cout << "Student: " << studentRef->getName() << endl;
        cout << "Roll No: " << studentRef->getRollNo() << endl;
    }

    cout << "Semester Fee: " << semesterFee << endl;
    cout << "Hostel Fee: " << hostelFee << endl;
    cout << "Library Fine: " << libraryFine << endl;
    cout << "Total Paid: " << totalPaid << endl;
    cout << "Balance: " << balance << endl;
}

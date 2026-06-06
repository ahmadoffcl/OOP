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
    paymentCount = 0;
    payments = new double[MAX_PAYMENTS];

    for (int i = 0; i < MAX_PAYMENTS; i++) {
        payments[i] = 0;
    }
}

FeeRecord::FeeRecord(Student* st, double semFee, double hostFee, double fine) {
    studentRef = st;
    semesterFee = semFee;
    hostelFee = hostFee;
    libraryFine = fine;
    totalPaid = 0;
    paymentCount = 0;
    payments = new double[MAX_PAYMENTS];

    for (int i = 0; i < MAX_PAYMENTS; i++) {
        payments[i] = 0;
    }

    calculateBalance();
}

FeeRecord::FeeRecord(const FeeRecord& other) {
    studentRef = other.studentRef;
    semesterFee = other.semesterFee;
    hostelFee = other.hostelFee;
    libraryFine = other.libraryFine;
    totalPaid = other.totalPaid;
    balance = other.balance;
    paymentCount = other.paymentCount;
    payments = new double[MAX_PAYMENTS];

    for (int i = 0; i < MAX_PAYMENTS; i++) {
        payments[i] = other.payments[i];
    }
}

FeeRecord& FeeRecord::operator=(const FeeRecord& other) {
    if (this != &other) {
        delete[] payments;

        studentRef = other.studentRef;
        semesterFee = other.semesterFee;
        hostelFee = other.hostelFee;
        libraryFine = other.libraryFine;
        totalPaid = other.totalPaid;
        balance = other.balance;
        paymentCount = other.paymentCount;
        payments = new double[MAX_PAYMENTS];

        for (int i = 0; i < MAX_PAYMENTS; i++) {
            payments[i] = other.payments[i];
        }
    }

    return *this;
}

FeeRecord::~FeeRecord() {
    delete[] payments;
}

void FeeRecord::calculateBalance() {
    balance = semesterFee + hostelFee + libraryFine - totalPaid;
}

void FeeRecord::addLibraryFine(double fine) {
    libraryFine = libraryFine + fine;
    calculateBalance();
}

double FeeRecord::getSemesterFee() const {
    return semesterFee;
}

double FeeRecord::getHostelFee() const {
    return hostelFee;
}

double FeeRecord::getLibraryFine() const {
    return libraryFine;
}

double FeeRecord::getTotalPaid() const {
    return totalPaid;
}

double FeeRecord::getBalance() const {
    return balance;
}

int FeeRecord::getPaymentCount() const {
    return paymentCount;
}

FeeRecord& FeeRecord::operator-=(double payment) {
    if (payment <= 0) {
        cout << "Payment amount must be positive." << endl;
        return *this;
    }

    if (paymentCount < MAX_PAYMENTS) {
        payments[paymentCount] = payment;
        paymentCount++;
    } else {
        cout << "Payment history is full. Payment still recorded in total." << endl;
    }

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

void FeeRecord::displayPayments() const {
    cout << "\n--- Payment History ---" << endl;

    if (paymentCount == 0) {
        cout << "No payment made yet." << endl;
    }

    for (int i = 0; i < paymentCount; i++) {
        cout << i + 1 << ". Payment: " << payments[i] << endl;
    }
}

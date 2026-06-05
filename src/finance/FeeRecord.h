/**
 * @file    FeeRecord.h
 * @brief   Student fee record class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Copy Constructor, Copy Assignment, Operator Overloading
 */

#ifndef FEERECORD_H
#define FEERECORD_H

#include "../person/Student.h"

class FeeRecord {
private:
    Student* studentRef;
    double semesterFee;
    double hostelFee;
    double libraryFine;
    double totalPaid;
    double balance;

public:
    FeeRecord();
    FeeRecord(Student* st, double semFee, double hostFee, double fine);
    FeeRecord(const FeeRecord& other);
    FeeRecord& operator=(const FeeRecord& other);

    void calculateBalance();
    void addLibraryFine(double fine);
    double getBalance() const;

    FeeRecord& operator-=(double payment);
    void displayFeeRecord() const;
};

#endif

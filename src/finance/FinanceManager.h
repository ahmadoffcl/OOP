/**
 * @file    FinanceManager.h
 * @brief   Array based manager for student fee records
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-07
 *
 * OOP Concepts: Arrays, File I/O, Operator Overloading Usage
 */

#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include "FeeRecord.h"
#include "../person/PersonManager.h"
#include <string>
using namespace std;

const int MAX_FEE_RECORDS = 50;

class FinanceManager {
private:
    FeeRecord records[MAX_FEE_RECORDS];
    int recordCount;
    string fileName;

public:
    FinanceManager(string file);

    void clearRecords();
    void seedDefaultRecords(PersonManager& personManager);
    void loadFromFile(PersonManager& personManager);
    void saveToFile() const;

    bool addRecord(Student* student, double semesterFee, double hostelFee, double libraryFine);
    FeeRecord* findRecordByRollNo(string rollNo);
    FeeRecord* getRecord(int index);
    int getRecordCount() const;

    bool recordPayment(string rollNo, double amount);
    bool addFine(string rollNo, double amount);
    void showAllRecords() const;
};

#endif

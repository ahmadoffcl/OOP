/**
 * @file    FinanceManager.cpp
 * @brief   Implementation of FinanceManager
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-07
 *
 * OOP Concepts: File I/O, Arrays, Copy Assignment, Operator -=
 */

#include "FinanceManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

FinanceManager::FinanceManager(string file) {
    fileName = file;
    recordCount = 0;
}

void FinanceManager::clearRecords() {
    recordCount = 0;
}

void FinanceManager::seedDefaultRecords(PersonManager& personManager) {
    clearRecords();

    Student* students[MAX_PEOPLE];
    int totalStudents = personManager.getStudents(students, MAX_PEOPLE);

    for (int i = 0; i < totalStudents && i < 3; i++) {
        addRecord(students[i], 65000, 20000, 500);
    }
}

bool FinanceManager::addRecord(Student* student, double semesterFee, double hostelFee, double libraryFine) {
    if (student == NULL) {
        cout << "Student record is empty." << endl;
        return false;
    }

    if (recordCount >= MAX_FEE_RECORDS) {
        cout << "Fee record storage is full." << endl;
        return false;
    }

    if (findRecordByRollNo(student->getRollNo()) != NULL) {
        cout << "Fee record already exists for this student." << endl;
        return false;
    }

    records[recordCount] = FeeRecord(student, semesterFee, hostelFee, libraryFine);
    recordCount++;
    return true;
}

FeeRecord* FinanceManager::findRecordByRollNo(string rollNo) {
    for (int i = 0; i < recordCount; i++) {
        Student* student = records[i].getStudent();
        if (student != NULL && student->getRollNo() == rollNo) {
            return &records[i];
        }
    }

    return NULL;
}

FeeRecord* FinanceManager::getRecord(int index) {
    if (index >= 0 && index < recordCount) {
        return &records[index];
    }

    return NULL;
}

int FinanceManager::getRecordCount() const {
    return recordCount;
}

bool FinanceManager::recordPayment(string rollNo, double amount) {
    FeeRecord* record = findRecordByRollNo(rollNo);

    if (record == NULL) {
        cout << "Fee record not found." << endl;
        return false;
    }

    if (amount <= 0) {
        cout << "Payment amount must be positive." << endl;
        return false;
    }

    *record -= amount;
    return true;
}

bool FinanceManager::addFine(string rollNo, double amount) {
    FeeRecord* record = findRecordByRollNo(rollNo);

    if (record == NULL) {
        cout << "Fee record not found." << endl;
        return false;
    }

    if (amount <= 0) {
        cout << "Fine amount must be positive." << endl;
        return false;
    }

    record->addLibraryFine(amount);
    return true;
}

void FinanceManager::showAllRecords() const {
    if (recordCount == 0) {
        cout << "No fee records saved." << endl;
        return;
    }

    for (int i = 0; i < recordCount; i++) {
        records[i].displayFeeRecord();
    }
}

void FinanceManager::loadFromFile(PersonManager& personManager) {
    ifstream file(fileName);

    clearRecords();

    if (!file) {
        seedDefaultRecords(personManager);
        saveToFile();
        return;
    }

    string line;
    while (getline(file, line) && recordCount < MAX_FEE_RECORDS) {
        if (line == "") {
            continue;
        }

        string part[20];
        stringstream ss(line);
        int count = 0;

        while (count < 20 && getline(ss, part[count], '|')) {
            count++;
        }

        if (count >= 5) {
            Student* student = dynamic_cast<Student*>(personManager.findByID(part[0]));

            if (student == NULL) {
                cout << "Skipped fee record with missing student: " << line << endl;
                continue;
            }

            try {
                FeeRecord record(student, stod(part[1]), stod(part[2]), stod(part[3]));
                int paymentCount = stoi(part[4]);

                for (int i = 0; i < paymentCount && 5 + i < count; i++) {
                    record -= stod(part[5 + i]);
                }

                records[recordCount] = record;
                recordCount++;
            } catch (...) {
                cout << "Skipped wrong fee record: " << line << endl;
            }
        }
    }

    file.close();

    if (recordCount == 0) {
        seedDefaultRecords(personManager);
        saveToFile();
    }
}

void FinanceManager::saveToFile() const {
    ofstream file(fileName);

    if (!file) {
        cout << "Fee records file could not be opened for saving." << endl;
        return;
    }

    for (int i = 0; i < recordCount; i++) {
        Student* student = records[i].getStudent();

        if (student != NULL) {
            file << student->getRollNo() << "|"
                 << records[i].getSemesterFee() << "|"
                 << records[i].getHostelFee() << "|"
                 << records[i].getLibraryFine() << "|"
                 << records[i].getPaymentCount();

            for (int j = 0; j < records[i].getPaymentCount(); j++) {
                file << "|" << records[i].getPaymentAt(j);
            }

            file << endl;
        }
    }

    file.close();
}

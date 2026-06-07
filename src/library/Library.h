/**
 * @file    Library.h
 * @brief   Library catalog class using arrays
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Array of Pointers, File I/O, Destructor
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include "LibraryItem.h"
#include <string>
using namespace std;

const int MAX_LIBRARY_ITEMS = 50;
const int MAX_ISSUED_ITEMS = 50;

struct IssuedRecord {
    string rollNo;
    string itemID;
    int daysLate;
    bool returned;
};

class Library {
private:
    LibraryItem* items[MAX_LIBRARY_ITEMS];
    int itemCount;
    IssuedRecord issued[MAX_ISSUED_ITEMS];
    int issuedCount;

public:
    Library();
    ~Library();

    bool addItem(LibraryItem* item);
    bool deleteItemByID(string itemID);
    LibraryItem* searchByTitle(string title) const;
    LibraryItem* searchByID(string itemID) const;
    void showAllItems() const;
    int getItemCount() const;
    int getIssuedCount() const;

    bool isAlreadyIssued(string rollNo, string itemID) const;
    bool issueItem(string rollNo, string itemID);
    bool returnItem(string rollNo, string itemID, int daysLate);
    void displayIssuedRecords() const;

    void saveCatalog(string fileName) const;
    void loadCatalog(string fileName);
    void saveIssuedRecords(string fileName) const;
    void loadIssuedRecords(string fileName);
};

#endif

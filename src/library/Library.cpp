/**
 * @file    Library.cpp
 * @brief   Implementation of the Library class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: File I/O, Array Search, Exception Handling
 */

#include "Library.h"
#include "Book.h"
#include "Journal.h"
#include "../utils/Exceptions.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

Library::Library() {
    itemCount = 0;
    issuedCount = 0;

    for (int i = 0; i < MAX_LIBRARY_ITEMS; i++) {
        items[i] = NULL;
    }
}

Library::~Library() {
    for (int i = 0; i < itemCount; i++) {
        delete items[i];
    }
}

void Library::addItem(LibraryItem* item) {
    if (itemCount < MAX_LIBRARY_ITEMS) {
        items[itemCount] = item;
        itemCount++;
    } else {
        delete item;
        cout << "Library is full. Item was not added." << endl;
    }
}

LibraryItem* Library::searchByTitle(string searchTitle) const {
    for (int i = 0; i < itemCount; i++) {
        if (items[i]->getTitle() == searchTitle) {
            return items[i];
        }
    }
    return NULL;
}

LibraryItem* Library::searchByID(string searchID) const {
    for (int i = 0; i < itemCount; i++) {
        if (items[i]->getItemID() == searchID) {
            return items[i];
        }
    }
    return NULL;
}

void Library::showAllItems() const {
    cout << "\n--- Library Catalog ---" << endl;

    if (itemCount == 0) {
        cout << "No items in library." << endl;
    }

    for (int i = 0; i < itemCount; i++) {
        items[i]->displayItem();
    }
}

int Library::getItemCount() const {
    return itemCount;
}

int Library::getIssuedCount() const {
    return issuedCount;
}

bool Library::isAlreadyIssued(string rollNo, string itemID) const {
    for (int i = 0; i < issuedCount; i++) {
        if (issued[i].rollNo == rollNo && issued[i].itemID == itemID && issued[i].returned == false) {
            return true;
        }
    }

    return false;
}

void Library::issueItem(string rollNo, string itemID) {
    LibraryItem* item = searchByID(itemID);

    if (item == NULL) {
        cout << "Library item not found." << endl;
        return;
    }

    if (isAlreadyIssued(rollNo, itemID)) {
        cout << "This item is already issued to roll no " << rollNo << "." << endl;
        return;
    }

    if (!item->isAvailable()) {
        cout << "Item is not available right now." << endl;
        return;
    }

    if (issuedCount < MAX_ISSUED_ITEMS) {
        item->checkout();
        issued[issuedCount].rollNo = rollNo;
        issued[issuedCount].itemID = itemID;
        issued[issuedCount].daysLate = 0;
        issued[issuedCount].returned = false;
        issuedCount++;
        cout << "Issued to roll no " << rollNo << endl;
    } else {
        cout << "Issued record array is full." << endl;
    }
}

void Library::returnItem(string rollNo, string itemID, int daysLate) {
    for (int i = 0; i < issuedCount; i++) {
        if (issued[i].rollNo == rollNo && issued[i].itemID == itemID && issued[i].returned == false) {
            LibraryItem* item = searchByID(itemID);

            if (item != NULL) {
                item->checkin();
            }

            issued[i].returned = true;
            issued[i].daysLate = daysLate;

            if (daysLate > 7) {
                double fine = (daysLate - 7) * 10;
                throw OverdueException(fine);
            }

            cout << "Item returned on time." << endl;
            return;
        }
    }

    cout << "Issued record not found." << endl;
}

void Library::displayIssuedRecords() const {
    cout << "\n--- Issued Item Records ---" << endl;

    if (issuedCount == 0) {
        cout << "No issued record found." << endl;
    }

    for (int i = 0; i < issuedCount; i++) {
        cout << i + 1 << ". Roll No: " << issued[i].rollNo
             << " | Item ID: " << issued[i].itemID
             << " | Returned: ";

        if (issued[i].returned) {
            cout << "Yes";
        } else {
            cout << "No";
        }

        cout << " | Days Late: " << issued[i].daysLate << endl;
    }
}

void Library::saveCatalog(string fileName) const {
    ofstream file(fileName);

    if (!file) {
        cout << "File could not be opened for saving." << endl;
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        file << items[i]->getSaveLine() << endl;
    }

    file.close();
}

void Library::loadCatalog(string fileName) {
    ifstream file(fileName);

    if (!file) {
        cout << "Catalog file not found. Add items manually first." << endl;
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        delete items[i];
        items[i] = NULL;
    }
    itemCount = 0;

    string line;
    while (getline(file, line) && itemCount < MAX_LIBRARY_ITEMS) {
        string part[8];
        stringstream ss(line);
        int count = 0;

        while (count < 8 && getline(ss, part[count], '|')) {
            count++;
        }

        if (count >= 8 && part[0] == "Book") {
            addItem(new Book(part[1], part[2], part[3], stoi(part[4]), part[5], part[6], stoi(part[7])));
        } else if (count >= 8 && part[0] == "Journal") {
            addItem(new Journal(part[1], part[2], part[3], stoi(part[4]), part[5], stoi(part[6]), stoi(part[7])));
        }
    }

    file.close();
}

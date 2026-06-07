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

bool Library::addItem(LibraryItem* item) {
    if (item == NULL) {
        return false;
    }

    if (searchByID(item->getItemID()) != NULL) {
        cout << "Item with this ID already exists." << endl;
        delete item;
        return false;
    }

    if (itemCount < MAX_LIBRARY_ITEMS) {
        items[itemCount] = item;
        itemCount++;
        return true;
    } else {
        delete item;
        cout << "Library is full. Item was not added." << endl;
        return false;
    }
}

bool Library::deleteItemByID(string deleteID) {
    for (int i = 0; i < issuedCount; i++) {
        if (issued[i].itemID == deleteID && issued[i].returned == false) {
            cout << "Item is currently issued. Return it before deleting." << endl;
            return false;
        }
    }

    for (int i = 0; i < itemCount; i++) {
        if (items[i] != NULL && items[i]->getItemID() == deleteID) {
            delete items[i];

            for (int j = i; j < itemCount - 1; j++) {
                items[j] = items[j + 1];
            }

            items[itemCount - 1] = NULL;
            itemCount--;
            return true;
        }
    }

    return false;
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

int Library::getActiveIssuedCount() const {
    int total = 0;

    for (int i = 0; i < issuedCount; i++) {
        if (!issued[i].returned) {
            total++;
        }
    }

    return total;
}

int Library::getOverdueRecordCount() const {
    int total = 0;

    for (int i = 0; i < issuedCount; i++) {
        if (issued[i].daysLate > 7) {
            total++;
        }
    }

    return total;
}

bool Library::isAlreadyIssued(string rollNo, string itemID) const {
    for (int i = 0; i < issuedCount; i++) {
        if (issued[i].rollNo == rollNo && issued[i].itemID == itemID && issued[i].returned == false) {
            return true;
        }
    }

    return false;
}

bool Library::issueItem(string rollNo, string itemID) {
    LibraryItem* item = searchByID(itemID);

    if (item == NULL) {
        cout << "Library item not found." << endl;
        return false;
    }

    if (isAlreadyIssued(rollNo, itemID)) {
        cout << "This item is already issued to roll no " << rollNo << "." << endl;
        return false;
    }

    if (!item->isAvailable()) {
        cout << "Item is not available right now." << endl;
        return false;
    }

    if (issuedCount < MAX_ISSUED_ITEMS) {
        item->checkout();
        issued[issuedCount].rollNo = rollNo;
        issued[issuedCount].itemID = itemID;
        issued[issuedCount].daysLate = 0;
        issued[issuedCount].returned = false;
        issuedCount++;
        cout << "Issued to roll no " << rollNo << endl;
        return true;
    } else {
        cout << "Issued record array is full." << endl;
        return false;
    }
}

bool Library::returnItem(string rollNo, string itemID, int daysLate) {
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
            return true;
        }
    }

    cout << "Issued record not found." << endl;
    return false;
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

void Library::displayOverdueRecords() const {
    cout << "\n--- Overdue Library Records ---" << endl;

    int found = 0;

    for (int i = 0; i < issuedCount; i++) {
        if (issued[i].daysLate > 7) {
            double fine = (issued[i].daysLate - 7) * 10;
            cout << found + 1 << ". Roll No: " << issued[i].rollNo
                 << " | Item ID: " << issued[i].itemID
                 << " | Days Late: " << issued[i].daysLate
                 << " | Fine: " << fine << endl;
            found++;
        }
    }

    if (found == 0) {
        cout << "No overdue library records found." << endl;
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

        try {
            if (count >= 8 && part[0] == "Book") {
                addItem(new Book(part[1], part[2], part[3], stoi(part[4]), part[5], part[6], stoi(part[7])));
            } else if (count >= 8 && part[0] == "Journal") {
                addItem(new Journal(part[1], part[2], part[3], stoi(part[4]), part[5], stoi(part[6]), stoi(part[7])));
            }
        } catch (...) {
            cout << "Skipped wrong library record: " << line << endl;
        }
    }

    file.close();
}

void Library::saveIssuedRecords(string fileName) const {
    ofstream file(fileName);

    if (!file) {
        cout << "Issued records file could not be opened for saving." << endl;
        return;
    }

    for (int i = 0; i < issuedCount; i++) {
        file << issued[i].rollNo << "|" << issued[i].itemID << "|"
             << issued[i].daysLate << "|";

        if (issued[i].returned) {
            file << "1";
        } else {
            file << "0";
        }

        file << endl;
    }

    file.close();
}

void Library::loadIssuedRecords(string fileName) {
    ifstream file(fileName);

    issuedCount = 0;

    if (!file) {
        return;
    }

    string line;
    while (getline(file, line) && issuedCount < MAX_ISSUED_ITEMS) {
        if (line == "") {
            continue;
        }

        string part[4];
        stringstream ss(line);
        int count = 0;

        while (count < 4 && getline(ss, part[count], '|')) {
            count++;
        }

        if (count >= 4) {
            try {
                issued[issuedCount].rollNo = part[0];
                issued[issuedCount].itemID = part[1];
                issued[issuedCount].daysLate = stoi(part[2]);
                issued[issuedCount].returned = (part[3] == "1");
                issuedCount++;
            } catch (...) {
                cout << "Skipped wrong issued record: " << line << endl;
            }
        }
    }

    file.close();
}

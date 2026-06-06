/**
 * @file    Invoice.cpp
 * @brief   Implementation of the Invoice class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Static Member, Copy Constructor, Destructor
 */

#include "Invoice.h"

int Invoice::invoiceCounter = 0;

Invoice::Invoice() {
    invoiceCounter++;
    invoiceID = invoiceCounter;
    date = "N/A";
    itemCount = 0;
    totalAmount = 0;
    items = NULL;
}

Invoice::Invoice(string d, string itemList[], int count, double total) {
    invoiceCounter++;
    invoiceID = invoiceCounter;
    date = d;
    itemCount = count;
    totalAmount = total;
    items = new string[itemCount];

    for (int i = 0; i < itemCount; i++) {
        items[i] = itemList[i];
    }
}

Invoice::Invoice(const Invoice& other) {
    invoiceCounter++;
    invoiceID = invoiceCounter;
    date = other.date;
    itemCount = other.itemCount;
    totalAmount = other.totalAmount;

    if (itemCount > 0) {
        items = new string[itemCount];
        for (int i = 0; i < itemCount; i++) {
            items[i] = other.items[i];
        }
    } else {
        items = NULL;
    }
}

Invoice& Invoice::operator=(const Invoice& other) {
    if (this != &other) {
        delete[] items;

        date = other.date;
        itemCount = other.itemCount;
        totalAmount = other.totalAmount;

        if (itemCount > 0) {
            items = new string[itemCount];
            for (int i = 0; i < itemCount; i++) {
                items[i] = other.items[i];
            }
        } else {
            items = NULL;
        }
    }

    return *this;
}

Invoice::~Invoice() {
    delete[] items;
}

int Invoice::getInvoiceCounter() {
    return invoiceCounter;
}

int Invoice::getInvoiceID() const {
    return invoiceID;
}

ostream& operator<<(ostream& out, const Invoice& inv) {
    out << "\n--- Invoice ---" << endl;
    out << "Invoice ID: " << inv.invoiceID << endl;
    out << "Date: " << inv.date << endl;
    out << "Items:" << endl;

    for (int i = 0; i < inv.itemCount; i++) {
        out << "- " << inv.items[i] << endl;
    }

    out << "Total Amount: " << inv.totalAmount << endl;
    return out;
}

/**
 * @file    Invoice.h
 * @brief   Invoice class with static counter
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Static Member, Dynamic Memory, Destructor
 */

#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include <string>
using namespace std;

class Invoice {
private:
    static int invoiceCounter;
    int invoiceID;
    string date;
    string* items;
    int itemCount;
    double totalAmount;

public:
    Invoice();
    Invoice(string d, string itemList[], int count, double total);
    Invoice(const Invoice& other);
    Invoice& operator=(const Invoice& other);
    ~Invoice();

    static int getInvoiceCounter();
    int getInvoiceID() const;

    friend ostream& operator<<(ostream& out, const Invoice& inv);
};

#endif

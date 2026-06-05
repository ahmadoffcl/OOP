/**
 * @file    Journal.cpp
 * @brief   Implementation of the Journal class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Inheritance, Runtime Polymorphism
 */

#include "Journal.h"
#include <iostream>
using namespace std;

Journal::Journal() : LibraryItem() {
    issn = "N/A";
    volume = 0;
    issueNumber = 0;
}

Journal::Journal(string id, string t, string a, int year, string issnNo, int vol, int issue)
    : LibraryItem(id, t, a, year) {
    issn = issnNo;
    volume = vol;
    issueNumber = issue;
}

void Journal::checkout() {
    cout << "Journal reading entry added." << endl;
}

void Journal::displayItem() const {
    cout << "\nJournal ID: " << itemID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year: " << publicationYear << endl;
    cout << "ISSN: " << issn << endl;
    cout << "Volume: " << volume << endl;
    cout << "Issue: " << issueNumber << endl;
}

string Journal::getSaveLine() const {
    return "Journal|" + itemID + "|" + title + "|" + author + "|" + to_string(publicationYear)
        + "|" + issn + "|" + to_string(volume) + "|" + to_string(issueNumber);
}

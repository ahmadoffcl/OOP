/**
 * @file    Book.cpp
 * @brief   Implementation of the Book class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Inheritance, File Data Formatting
 */

#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() : LibraryItem() {
    isbn = "N/A";
    genre = "N/A";
    copiesAvailable = 0;
}

Book::Book(string id, string t, string a, int year, string isbnNo, string g, int copies)
    : LibraryItem(id, t, a, year) {
    isbn = isbnNo;
    genre = g;
    copiesAvailable = copies;
}

int Book::getCopiesAvailable() const {
    return copiesAvailable;
}

void Book::setCopiesAvailable(int copies) {
    copiesAvailable = copies;
}

void Book::checkout() {
    if (copiesAvailable > 0) {
        copiesAvailable--;
        cout << "Book issued successfully." << endl;
    } else {
        cout << "No copy available." << endl;
    }
}

void Book::displayItem() const {
    cout << "\nBook ID: " << itemID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year: " << publicationYear << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Genre: " << genre << endl;
    cout << "Copies: " << copiesAvailable << endl;
}

string Book::getSaveLine() const {
    return "Book|" + itemID + "|" + title + "|" + author + "|" + to_string(publicationYear)
        + "|" + isbn + "|" + genre + "|" + to_string(copiesAvailable);
}

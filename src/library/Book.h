/**
 * @file    Book.h
 * @brief   Book class derived from LibraryItem
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Inheritance, Runtime Polymorphism
 */

#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"
#include <string>
using namespace std;

class Book : public LibraryItem {
private:
    string isbn;
    string genre;
    int copiesAvailable;

public:
    Book();
    Book(string id, string t, string a, int year, string isbnNo, string g, int copies);

    int getCopiesAvailable() const;
    void setCopiesAvailable(int copies);

    void checkout();
    void displayItem() const;
    string getSaveLine() const;
};

#endif

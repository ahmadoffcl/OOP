/**
 * @file    LibraryItem.h
 * @brief   Abstract base class for library items
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Abstract Class, Pure Virtual Function, Encapsulation
 */

#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>
using namespace std;

class LibraryItem {
protected:
    string itemID;
    string title;
    string author;
    int publicationYear;

public:
    LibraryItem();
    LibraryItem(string id, string t, string a, int year);
    virtual ~LibraryItem();

    string getItemID() const;
    string getTitle() const;
    string getAuthor() const;
    int getPublicationYear() const;

    void setTitle(string t);
    void setAuthor(string a);
    void setPublicationYear(int year);

    virtual bool isAvailable() const = 0;
    virtual void checkout() = 0;
    virtual void checkin() = 0;
    virtual void displayItem() const = 0;
    virtual string getSaveLine() const = 0;
};

#endif

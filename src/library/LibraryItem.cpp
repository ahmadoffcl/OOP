/**
 * @file    LibraryItem.cpp
 * @brief   Implementation of the LibraryItem base class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Constructor, Destructor, Encapsulation
 */

#include "LibraryItem.h"

LibraryItem::LibraryItem() {
    itemID = "N/A";
    title = "N/A";
    author = "N/A";
    publicationYear = 0;
}

LibraryItem::LibraryItem(string id, string t, string a, int year) {
    itemID = id;
    title = t;
    author = a;
    publicationYear = year;
}

LibraryItem::~LibraryItem() {
}

string LibraryItem::getItemID() const {
    return itemID;
}

string LibraryItem::getTitle() const {
    return title;
}

string LibraryItem::getAuthor() const {
    return author;
}

int LibraryItem::getPublicationYear() const {
    return publicationYear;
}

void LibraryItem::setTitle(string t) {
    title = t;
}

void LibraryItem::setAuthor(string a) {
    author = a;
}

void LibraryItem::setPublicationYear(int year) {
    publicationYear = year;
}

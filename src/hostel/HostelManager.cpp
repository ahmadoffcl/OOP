/**
 * @file    HostelManager.cpp
 * @brief   Implementation of the HostelManager class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Multiple Inheritance, Composition, Destructor
 */

#include "HostelManager.h"
#include <iostream>
using namespace std;

HostelManager::HostelManager() : block("Boys Block A") {
    block.addRoom(Room(101, "triple", 1));
    block.addRoom(Room(102, "triple", 1));
    block.addRoom(Room(201, "triple", 2));
}

HostelManager::~HostelManager() {
}

void HostelManager::showServiceName() const {
    cout << "Hostel Accommodation Service" << endl;
}

void HostelManager::allocateRoom(Student* student) {
    if (student == NULL) {
        cout << "Student record is empty." << endl;
        return;
    }

    Room* existingRoom = block.findRoomByStudent(student->getRollNo());
    if (existingRoom != NULL) {
        cout << student->getName() << " is already allocated to room "
             << existingRoom->getRoomNumber() << endl;
        return;
    }

    for (int i = 0; i < block.getRoomCount(); i++) {
        Room* room = block.getRoom(i);

        if (room != NULL && room->hasSpace()) {
            room->addStudent(student);
            cout << student->getName() << " allocated to room " << room->getRoomNumber() << endl;
            return;
        }
    }

    cout << "No room is empty right now." << endl;
}

void HostelManager::vacateRoom(string rollNo) {
    for (int i = 0; i < block.getRoomCount(); i++) {
        Room* room = block.getRoom(i);

        if (room != NULL && room->removeStudent(rollNo)) {
            cout << "Room vacated for roll no " << rollNo << endl;
            return;
        }
    }

    cout << "Student not found in hostel." << endl;
}

void HostelManager::generateReport() const {
    cout << "\n--- Hostel Occupancy Report ---" << endl;
    showSummary();
    block.displayBlock();
}

void HostelManager::showSummary() const {
    cout << "Block Name: " << block.getBlockName() << endl;
    cout << "Total Rooms: " << block.getRoomCount() << endl;
    cout << "Total Occupants: " << block.getTotalOccupants() << endl;
}

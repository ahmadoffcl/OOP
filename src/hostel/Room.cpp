/**
 * @file    Room.cpp
 * @brief   Implementation of the Room class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Arrays, Aggregation
 */

#include "Room.h"
#include <iostream>
using namespace std;

Room::Room() {
    roomNumber = 0;
    type = "triple";
    floor = 0;
    occupantCount = 0;

    for (int i = 0; i < MAX_ROOM_OCCUPANTS; i++) {
        occupants[i] = NULL;
    }
}

Room::Room(int number, string roomType, int floorNo) {
    roomNumber = number;
    type = roomType;
    floor = floorNo;
    occupantCount = 0;

    for (int i = 0; i < MAX_ROOM_OCCUPANTS; i++) {
        occupants[i] = NULL;
    }
}

bool Room::addStudent(Student* student) {
    if (student == NULL) {
        return false;
    }

    if (!hasSpace()) {
        return false;
    }

    if (hasStudent(student->getRollNo())) {
        return false;
    }

    occupants[occupantCount] = student;
    occupantCount++;
    return true;
}

bool Room::removeStudent(string rollNo) {
    for (int i = 0; i < occupantCount; i++) {
        if (occupants[i] != NULL && occupants[i]->getRollNo() == rollNo) {
            for (int j = i; j < occupantCount - 1; j++) {
                occupants[j] = occupants[j + 1];
            }

            occupants[occupantCount - 1] = NULL;
            occupantCount--;
            return true;
        }
    }

    return false;
}

bool Room::hasStudent(string rollNo) const {
    for (int i = 0; i < occupantCount; i++) {
        if (occupants[i] != NULL && occupants[i]->getRollNo() == rollNo) {
            return true;
        }
    }

    return false;
}

bool Room::hasSpace() const {
    return occupantCount < getCapacity();
}

void Room::clearOccupants() {
    occupantCount = 0;

    for (int i = 0; i < MAX_ROOM_OCCUPANTS; i++) {
        occupants[i] = NULL;
    }
}

bool Room::isEmpty() const {
    return occupantCount == 0;
}

int Room::getOccupantCount() const {
    return occupantCount;
}

int Room::getCapacity() const {
    if (type == "single") {
        return 1;
    }

    if (type == "double") {
        return 2;
    }

    return 3;
}

int Room::getRoomNumber() const {
    return roomNumber;
}

string Room::getType() const {
    return type;
}

int Room::getFloor() const {
    return floor;
}

Student* Room::getOccupant(int index) const {
    if (index >= 0 && index < occupantCount) {
        return occupants[index];
    }

    return NULL;
}

void Room::displayRoom() const {
    cout << "\nRoom No: " << roomNumber << endl;
    cout << "Type: " << type << endl;
    cout << "Floor: " << floor << endl;
    cout << "Occupants: " << occupantCount << "/" << getCapacity() << endl;

    for (int i = 0; i < occupantCount; i++) {
        cout << "- " << occupants[i]->getName() << " (" << occupants[i]->getRollNo() << ")" << endl;
    }
}

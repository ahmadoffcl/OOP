/**
 * @file    HostelBlock.cpp
 * @brief   Implementation of the HostelBlock class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Composition, Arrays of Objects
 */

#include "HostelBlock.h"
#include <iostream>
using namespace std;

HostelBlock::HostelBlock() {
    blockName = "A";
    roomCount = 0;
}

HostelBlock::HostelBlock(string name) {
    blockName = name;
    roomCount = 0;
}

bool HostelBlock::addRoom(Room room) {
    if (roomCount >= MAX_BLOCK_ROOMS) {
        cout << "No more rooms can be added in this block." << endl;
        return false;
    }

    if (findRoomByNumber(room.getRoomNumber()) != NULL) {
        cout << "Room number already exists." << endl;
        return false;
    }

    rooms[roomCount] = room;
    roomCount++;
    return true;
}

bool HostelBlock::removeRoom(int roomNumber) {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].getRoomNumber() == roomNumber) {
            if (!rooms[i].isEmpty()) {
                cout << "Room is not empty. Vacate students first." << endl;
                return false;
            }

            for (int j = i; j < roomCount - 1; j++) {
                rooms[j] = rooms[j + 1];
            }

            roomCount--;
            return true;
        }
    }

    cout << "Room not found." << endl;
    return false;
}

void HostelBlock::clearRooms() {
    roomCount = 0;
}

Room* HostelBlock::getRoom(int index) {
    if (index >= 0 && index < roomCount) {
        return &rooms[index];
    }

    return NULL;
}

const Room* HostelBlock::getRoom(int index) const {
    if (index >= 0 && index < roomCount) {
        return &rooms[index];
    }

    return NULL;
}

int HostelBlock::getRoomCount() const {
    return roomCount;
}

int HostelBlock::getTotalOccupants() const {
    int total = 0;

    for (int i = 0; i < roomCount; i++) {
        total = total + rooms[i].getOccupantCount();
    }

    return total;
}

Room* HostelBlock::findRoomByStudent(string rollNo) {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].hasStudent(rollNo)) {
            return &rooms[i];
        }
    }

    return NULL;
}

Room* HostelBlock::findRoomByNumber(int roomNumber) {
    for (int i = 0; i < roomCount; i++) {
        if (rooms[i].getRoomNumber() == roomNumber) {
            return &rooms[i];
        }
    }

    return NULL;
}

string HostelBlock::getBlockName() const {
    return blockName;
}

void HostelBlock::displayBlock() const {
    cout << "\nHostel Block: " << blockName << endl;

    for (int i = 0; i < roomCount; i++) {
        rooms[i].displayRoom();
    }
}

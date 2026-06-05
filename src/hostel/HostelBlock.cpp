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

void HostelBlock::addRoom(Room room) {
    if (roomCount < MAX_BLOCK_ROOMS) {
        rooms[roomCount] = room;
        roomCount++;
    } else {
        cout << "No more rooms can be added in this block." << endl;
    }
}

Room* HostelBlock::getRoom(int index) {
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

string HostelBlock::getBlockName() const {
    return blockName;
}

void HostelBlock::displayBlock() const {
    cout << "\nHostel Block: " << blockName << endl;

    for (int i = 0; i < roomCount; i++) {
        rooms[i].displayRoom();
    }
}

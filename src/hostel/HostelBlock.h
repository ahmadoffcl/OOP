/**
 * @file    HostelBlock.h
 * @brief   Hostel block made of room objects
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Composition, Arrays of Objects
 */

#ifndef HOSTELBLOCK_H
#define HOSTELBLOCK_H

#include "Room.h"
#include <string>
using namespace std;

const int MAX_BLOCK_ROOMS = 5;

class HostelBlock {
private:
    string blockName;
    Room rooms[MAX_BLOCK_ROOMS];
    int roomCount;

public:
    HostelBlock();
    HostelBlock(string name);

    void addRoom(Room room);
    Room* getRoom(int index);
    int getRoomCount() const;
    int getTotalOccupants() const;
    Room* findRoomByStudent(string rollNo);
    string getBlockName() const;
    void displayBlock() const;
};

#endif

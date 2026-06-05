/**
 * @file    Room.h
 * @brief   Hostel room class
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Arrays of Objects, Aggregation
 */

#ifndef ROOM_H
#define ROOM_H

#include "../person/Student.h"
#include <string>
using namespace std;

const int MAX_ROOM_OCCUPANTS = 3;

class Room {
private:
    int roomNumber;
    string type;
    int floor;
    Student* occupants[MAX_ROOM_OCCUPANTS];
    int occupantCount;

public:
    Room();
    Room(int number, string roomType, int floorNo);

    bool addStudent(Student* student);
    bool removeStudent(string rollNo);
    bool hasSpace() const;
    int getOccupantCount() const;
    int getRoomNumber() const;

    void displayRoom() const;
};

#endif

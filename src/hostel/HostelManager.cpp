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
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

HostelManager::HostelManager() : block("Boys Block A") {
    roomFileName = "data/hostel_rooms.txt";
    allocationFileName = "data/hostel_allocations.txt";
    seedDefaultRooms();
}

HostelManager::HostelManager(string roomFile, string allocationFile) : block("Boys Block A") {
    roomFileName = roomFile;
    allocationFileName = allocationFile;
    seedDefaultRooms();
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

void HostelManager::allocateRoomToNumber(Student* student, int roomNumber) {
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

    Room* room = block.findRoomByNumber(roomNumber);
    if (room == NULL) {
        cout << "Room not found." << endl;
        return;
    }

    if (!room->hasSpace()) {
        cout << "Selected room is full." << endl;
        return;
    }

    room->addStudent(student);
    cout << student->getName() << " allocated to room " << room->getRoomNumber() << endl;
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

void HostelManager::showAllRooms() const {
    block.displayBlock();
}

void HostelManager::showStudentRoom(string rollNo) {
    Room* room = block.findRoomByStudent(rollNo);

    if (room == NULL) {
        cout << "Student not found in hostel." << endl;
        return;
    }

    cout << "Student is allocated in room " << room->getRoomNumber() << endl;
    room->displayRoom();
}

bool HostelManager::addRoom(int roomNumber, string type, int floor) {
    if (roomNumber <= 0) {
        cout << "Room number must be positive." << endl;
        return false;
    }

    if (type != "single" && type != "double" && type != "triple") {
        cout << "Room type must be single, double, or triple." << endl;
        return false;
    }

    if (floor < 0) {
        cout << "Floor cannot be negative." << endl;
        return false;
    }

    return block.addRoom(Room(roomNumber, type, floor));
}

bool HostelManager::deleteRoom(int roomNumber) {
    return block.removeRoom(roomNumber);
}

Room* HostelManager::findRoomByNumber(int roomNumber) {
    return block.findRoomByNumber(roomNumber);
}

int HostelManager::getRoomCount() const {
    return block.getRoomCount();
}

void HostelManager::seedDefaultRooms() {
    block.clearRooms();
    block.addRoom(Room(101, "triple", 1));
    block.addRoom(Room(102, "double", 1));
    block.addRoom(Room(201, "single", 2));
}

void HostelManager::loadFromFile(PersonManager& personManager) {
    block.clearRooms();

    ifstream roomFile(roomFileName);

    if (!roomFile) {
        seedDefaultRooms();
        saveToFile();
        return;
    }

    string line;
    while (getline(roomFile, line)) {
        if (line == "") {
            continue;
        }

        string part[3];
        stringstream ss(line);
        int count = 0;

        while (count < 3 && getline(ss, part[count], '|')) {
            count++;
        }

        if (count == 3) {
            try {
                addRoom(stoi(part[0]), part[1], stoi(part[2]));
            } catch (...) {
                cout << "Skipped wrong hostel room: " << line << endl;
            }
        }
    }

    roomFile.close();

    if (block.getRoomCount() == 0) {
        seedDefaultRooms();
    }

    ifstream allocationFile(allocationFileName);

    if (!allocationFile) {
        saveToFile();
        return;
    }

    while (getline(allocationFile, line)) {
        if (line == "") {
            continue;
        }

        string part[2];
        stringstream ss(line);
        int count = 0;

        while (count < 2 && getline(ss, part[count], '|')) {
            count++;
        }

        if (count == 2) {
            Student* student = dynamic_cast<Student*>(personManager.findByID(part[0]));

            if (student == NULL) {
                cout << "Skipped hostel allocation with missing student: " << line << endl;
                continue;
            }

            try {
                Room* room = block.findRoomByNumber(stoi(part[1]));

                if (room == NULL) {
                    cout << "Skipped hostel allocation with missing room: " << line << endl;
                    continue;
                }

                if (!room->addStudent(student)) {
                    cout << "Skipped hostel allocation because room is full or duplicate: " << line << endl;
                }
            } catch (...) {
                cout << "Skipped wrong hostel allocation: " << line << endl;
            }
        }
    }

    allocationFile.close();
}

void HostelManager::saveToFile() const {
    ofstream roomFile(roomFileName);

    if (!roomFile) {
        cout << "Hostel room file could not be opened for saving." << endl;
        return;
    }

    for (int i = 0; i < block.getRoomCount(); i++) {
        const Room* room = block.getRoom(i);

        if (room != NULL) {
            roomFile << room->getRoomNumber() << "|"
                     << room->getType() << "|"
                     << room->getFloor() << endl;
        }
    }

    roomFile.close();

    ofstream allocationFile(allocationFileName);

    if (!allocationFile) {
        cout << "Hostel allocation file could not be opened for saving." << endl;
        return;
    }

    for (int i = 0; i < block.getRoomCount(); i++) {
        const Room* room = block.getRoom(i);

        if (room != NULL) {
            for (int j = 0; j < room->getOccupantCount(); j++) {
                Student* student = room->getOccupant(j);

                if (student != NULL) {
                    allocationFile << student->getRollNo() << "|"
                                   << room->getRoomNumber() << endl;
                }
            }
        }
    }

    allocationFile.close();
}

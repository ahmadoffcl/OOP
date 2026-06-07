/**
 * @file    HostelManager.h
 * @brief   Hostel manager using multiple inheritance
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Multiple Inheritance, Virtual Inheritance, Composition
 */

#ifndef HOSTELMANAGER_H
#define HOSTELMANAGER_H

#include "Accommodation.h"
#include "Reportable.h"
#include "HostelBlock.h"
#include "../person/PersonManager.h"
#include <string>
using namespace std;

class HostelManager : public Accommodation, public Reportable {
private:
    HostelBlock block;
    string roomFileName;
    string allocationFileName;

public:
    HostelManager();
    HostelManager(string roomFile, string allocationFile);
    ~HostelManager();

    void showServiceName() const;
    void allocateRoom(Student* student);
    void allocateRoomToNumber(Student* student, int roomNumber);
    void vacateRoom(string rollNo);
    void generateReport() const;
    void showSummary() const;
    void showAllRooms() const;
    void showStudentRoom(string rollNo);
    bool addRoom(int roomNumber, string type, int floor);
    bool deleteRoom(int roomNumber);
    Room* findRoomByNumber(int roomNumber);
    int getRoomCount() const;
    int getTotalOccupants() const;
    void seedDefaultRooms();
    void loadFromFile(PersonManager& personManager);
    void saveToFile() const;
};

#endif

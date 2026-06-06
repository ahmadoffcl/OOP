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

class HostelManager : public Accommodation, public Reportable {
private:
    HostelBlock block;

public:
    HostelManager();
    ~HostelManager();

    void showServiceName() const;
    void allocateRoom(Student* student);
    void vacateRoom(string rollNo);
    void generateReport() const;
    void showSummary() const;
};

#endif

/**
 * @file    Accommodation.h
 * @brief   Abstract accommodation interface
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Abstract Class, Virtual Inheritance
 */

#ifndef ACCOMMODATION_H
#define ACCOMMODATION_H

#include "../person/Student.h"
#include <string>
using namespace std;

class CampusService {
public:
    virtual ~CampusService() {}
    virtual void showServiceName() const = 0;
};

class Accommodation : virtual public CampusService {
public:
    virtual void allocateRoom(Student* student) = 0;
    virtual void vacateRoom(string rollNo) = 0;
};

#endif

/**
 * @file    Reportable.h
 * @brief   Abstract reporting interface
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Abstract Class, Virtual Inheritance
 */

#ifndef REPORTABLE_H
#define REPORTABLE_H

#include "Accommodation.h"

class Reportable : virtual public CampusService {
public:
    virtual void generateReport() const = 0;
};

#endif

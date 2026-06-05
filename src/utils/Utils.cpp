/**
 * @file    Utils.cpp
 * @brief   Implementation of small helper functions
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Utility Functions
 */

#include "Utils.h"
#include <iostream>
using namespace std;

string Utils::getTodayDate() {
    return "05-06-2026";
}

void Utils::printLine() {
    cout << "------------------------------------------------------------" << endl;
}

int Utils::checkPositiveInt(int value) {
    if (value < 0) {
        return 0;
    }

    return value;
}

/**
 * @file    Utils.h
 * @brief   Small helper functions for SCMS
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Utility Functions, Input Validation
 */

#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

namespace Utils {
    string getTodayDate();
    void printLine();
    int checkPositiveInt(int value);
}

#endif

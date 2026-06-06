/**
 * @file    Exceptions.h
 * @brief   Custom exceptions used in SCMS
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-05
 *
 * OOP Concepts: Exception Handling, Custom Exception Classes
 */

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>
using namespace std;

class CapacityExceededException : public exception {
private:
    string message;

public:
    CapacityExceededException() {
        message = "Course capacity is full. Student cannot be enrolled.";
    }

    const char* what() const noexcept {
        return message.c_str();
    }
};

class OverdueException : public exception {
private:
    string message;

public:
    OverdueException(double fineAmount) {
        message = "Library item is overdue. Fine is Rs. " + to_string(fineAmount);
    }

    const char* what() const noexcept {
        return message.c_str();
    }
};

#endif

/**
 * @file    CourseManager.h
 * @brief   Array based manager for courses and enrollments
 * @author  Ahmad Ali (25-CS-067), Umer Altaf (25-CS-057), Muhammed Ahmad (25-CS-252)
 * @course  CS-104L: Object-Oriented Programming
 * @inst    HITEC University Taxila
 * @date    2026-06-07
 *
 * OOP Concepts: Encapsulation, Arrays, File I/O, Association
 */

#ifndef COURSEMANAGER_H
#define COURSEMANAGER_H

#include "Course.h"
#include "Enrollment.h"
#include "../person/PersonManager.h"
#include <string>
using namespace std;

const int MAX_COURSES = 30;
const int MAX_ENROLLMENTS = 100;

class CourseManager {
private:
    Course courses[MAX_COURSES];
    Enrollment enrollments[MAX_ENROLLMENTS];
    int courseCount;
    int enrollmentCount;
    string courseFileName;
    string enrollmentFileName;

public:
    CourseManager(string courseFile, string enrollmentFile);

    void clearCourses();
    void seedDefaultCourse(PersonManager& personManager);
    void loadCourses(PersonManager& personManager);
    void saveCourses() const;
    void loadEnrollments(PersonManager& personManager);
    void saveEnrollments() const;
    void loadAll(PersonManager& personManager);
    void saveAll() const;

    bool addCourse(Course course);
    Course* findCourseByCode(string code);
    Course* getCourse(int index);
    int getCourseCount() const;
    int getEnrollmentCount() const;

    bool enrollStudent(string rollNo, string courseCode, PersonManager& personManager);
    bool dropStudent(string rollNo, string courseCode);
    void rebuildEnrollmentRecords();
    void showAllCourses() const;
    void showEnrollmentRecords() const;
};

#endif

# Module 2 Status - Course and Enrollment

Status: Complete and tested as a real saved course/enrollment module.

## Required Classes

- `Course`
- `Enrollment`
- `CourseManager`

## Course Data Members

- courseCode
- courseName
- creditHours
- instructor (`Faculty*`)
- maxCapacity
- enrolledCount
- enrolledStudents array
- waitingList array
- waitingCount

## Enrollment Data Members

- student (`Student*`)
- course (`Course*`)
- enrollmentDate
- grade
- status (`Enrolled` or `Waiting`)

## CourseManager Data Members

- `Course courses[MAX_COURSES]`
- `Enrollment enrollments[MAX_ENROLLMENTS]`
- courseCount
- enrollmentCount
- courseFileName
- enrollmentFileName

## Saved Files

- `data/courses.txt`
- `data/enrollments.txt`

Course format:

```text
courseCode|courseName|creditHours|instructorID|maxCapacity
```

Enrollment format:

```text
rollNo|courseCode|enrollmentDate|grade|status
```

## Required Operations

- `Course::operator==` compares courses by course code.
- `Course::operator<<` prints course details.
- `Course::operator+` merges two waiting lists and returns a dynamic `Student**` array.
- `Course::enrollStudent()` enrolls students until capacity is full.
- `CapacityExceededException` is thrown when capacity is full and the student is added to the waiting list.
- `Course::removeStudent()` drops a student from enrolled or waiting list arrays.
- `CourseManager::addCourse()` adds a real course from keyboard input.
- `CourseManager::loadAll()` loads courses first, then reconnects enrollment records using roll number and course code.
- `CourseManager::saveAll()` saves course and enrollment records to text files.
- Bad saved rows are skipped with a simple message.

## Course Module Menu

```text
1. Show all courses
2. Add course
3. Search course by code
4. Enroll student in course
5. Show course roster
6. Drop student from course
7. Compare two courses using ==
8. Merge waiting lists using +
9. Show enrollment records
10. Save course/enrollment records
11. Reload course/enrollment records
0. Back to Home
```

## OOP Concepts Covered

- Encapsulation
- Getter and setter functions
- Operator overloading
- Friend function
- Aggregation through `Faculty* instructor`
- Association through `Enrollment`
- Array-based collection in `Course` and `CourseManager`
- File I/O using `fstream`
- Custom exception handling

## Where It Is Tested

Run:

```text
Home -> 2. Course and Enrollment Module -> 2. Add course
Home -> 2. Course and Enrollment Module -> 4. Enroll student in course
Home -> 2. Course and Enrollment Module -> 5. Show course roster
Home -> 2. Course and Enrollment Module -> 6. Drop student from course
Home -> 2. Course and Enrollment Module -> 7. Compare two courses using ==
Home -> 2. Course and Enrollment Module -> 8. Merge waiting lists using +
Home -> 2. Course and Enrollment Module -> 9. Show enrollment records
Home -> 2. Course and Enrollment Module -> 10. Save course/enrollment records
Home -> 2. Course and Enrollment Module -> 11. Reload course/enrollment records
```

Expected result:

- Saved courses display from `data/courses.txt`.
- Added course remains after save and reload.
- Student enrollment uses saved roll number and saved course code.
- Full course sends extra student to waiting list.
- Roster shows enrolled and waiting students.
- Drop removes the selected student from roster.
- Compare and merge demonstrate overloaded operators.

# Module 2 Status - Course and Enrollment

Status: Complete and tested.

## Required Classes

- `Course`
- `Enrollment`

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

## Required Operations

- `Course::operator==` compares courses by course code.
- `Course::operator<<` prints course details.
- `Course::operator+` merges two waiting lists.
- `Course::enrollStudent()` prevents enrollment beyond capacity.
- `CapacityExceededException` is thrown when capacity is full.
- `Course::displayEnrolledStudents()` prints enrolled students.
- `Course::displayWaitingList()` prints waiting students.
- Duplicate enrolled/waiting students are checked.

## OOP Concepts Covered

- Encapsulation
- Getter and setter functions
- Operator overloading
- Friend function
- Aggregation through `Faculty* instructor`
- Association through `Enrollment`
- Array-based collection
- Custom exception handling

## Where It Is Tested

Run:

```text
Home -> 2. Course and Enrollment Module -> 1. Show course details
Home -> 2. Course and Enrollment Module -> 2. Run enrollment demo
Home -> 2. Course and Enrollment Module -> 3. Show enrolled and waiting students
Home -> 2. Course and Enrollment Module -> 4. Compare courses using ==
Home -> 2. Course and Enrollment Module -> 5. Merge waiting lists using +
```

Expected result:

- First student enrolls.
- Second student goes to waiting list because capacity is 1.
- Course comparison prints equal/not equal results.
- Waiting list merge prints three sample students.

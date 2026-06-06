# Module 1 Status - Person Hierarchy

Status: Complete and tested.

## Required Classes

- `Person`: abstract base class
- `Student`: derived from `Person`
- `GradStudent`: derived from `Student`
- `Faculty`: derived from `Person`
- `Staff`: derived from `Person`

## Required Data Members

- `Person`: name, CNIC, age, contact
- `Student`: rollNo, semester, GPA, enrolledCourses array
- `Faculty`: employeeID, department, designation, assignedCourses array
- `Staff`: staffID, role, salary

## Required Functions

- `displayInfo()` is pure virtual in `Person`
- `displayInfo()` is overridden in Student, GradStudent, Faculty, and Staff
- `Student::calculateGrade()` is implemented
- Getters and setters are implemented

## OOP Concepts Covered

- Abstract class
- Pure virtual function
- Single inheritance
- Multi-level inheritance
- Runtime polymorphism
- Encapsulation
- Arrays
- Constructors and destructor

## Where It Is Tested

Run:

```text
Home -> 1. Person Module -> 1. Show all people
Home -> 1. Person Module -> 2. Show student list
```

Expected result:

- All people display correctly.
- `Person*` array calls each derived class `displayInfo()` function.

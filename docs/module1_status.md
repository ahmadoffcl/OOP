# Module 1 Status - Person Hierarchy

Status: Complete and tested with saved record management.

## Required Classes

- `Person`: abstract base class
- `Student`: derived from `Person`
- `GradStudent`: derived from `Student`
- `Faculty`: derived from `Person`
- `Staff`: derived from `Person`
- `PersonManager`: manages saved people using a `Person*` array

## Required Data Members

- `Person`: name, CNIC, age, contact
- `Student`: rollNo, semester, GPA, enrolledCourses array
- `Faculty`: employeeID, department, designation, assignedCourses array
- `Staff`: staffID, role, salary

## Required Functions

- `displayInfo()` is pure virtual in `Person`
- `displayInfo()` is overridden in Student, GradStudent, Faculty, and Staff
- `getPersonType()` is pure virtual in `Person`
- `getUniqueID()` is pure virtual in `Person`
- `Student::calculateGrade()` is implemented
- Getters and setters are implemented

## PersonManager Features

- Uses a simple `Person* people[MAX_PEOPLE]` array.
- Loads records from `data/person_records.txt`.
- Saves records to `data/person_records.txt`.
- Seeds default records if the file is missing or empty.
- Adds Student, GradStudent, Faculty, and Staff records.
- Deletes records by roll number, employee ID, or staff ID.
- Adds a course code to a saved student for the current session.
- Deletes dynamic `Person` objects in the destructor.

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
Home -> 1. Person Module -> 3. Add Student
Home -> 1. Person Module -> 4. Add Grad Student
Home -> 1. Person Module -> 5. Add Faculty
Home -> 1. Person Module -> 6. Add Staff
Home -> 1. Person Module -> 7. Add course to student
Home -> 1. Person Module -> 8. Delete person by ID
Home -> 1. Person Module -> 9. Save records
Home -> 1. Person Module -> 10. Reload records
```

Expected result:

- All people display correctly.
- `Person*` array calls each derived class `displayInfo()` function.
- New records can be saved, reloaded, and deleted.
- Course code added to a student appears in `displayInfo()` during that session.

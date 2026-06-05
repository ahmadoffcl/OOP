# OOP Concepts Checklist

This file maps the assignment checklist to files in this project. Read the code before viva and edit the wording in your own style.

| # | Concept | Where it is used |
|---|---------|------------------|
| 1 | Classes and objects | All classes in `src/` and objects in `main.cpp` |
| 2 | Encapsulation | Private data with getters/setters in `Student`, `Course`, `FeeRecord`, etc. |
| 3 | Constructors | Default and parameter constructors in most classes |
| 4 | Destructors | `Library`, `Invoice`, `HostelManager` |
| 5 | Single inheritance | `Student : Person` |
| 6 | Multi-level inheritance | `GradStudent : Student : Person` |
| 7 | Multiple inheritance | `HostelManager : Accommodation, Reportable` |
| 8 | Virtual inheritance | `Accommodation` and `Reportable` virtually inherit `CampusService` |
| 9 | Abstract classes | `Person`, `LibraryItem`, `Accommodation`, `Reportable` |
| 10 | Runtime polymorphism | `Person* people[]` calls different `displayInfo()` methods |
| 11 | Operator overloading | `Course ==`, `Course <<`, `Course +`, `FeeRecord -=` |
| 12 | Friend functions | `operator<<` for `Course` and `Invoice` |
| 13 | Static members | `Invoice::invoiceCounter` |
| 14 | Copy constructor | `Person`, `Course`, `FeeRecord`, `Invoice` |
| 15 | Copy assignment | `FeeRecord::operator=`, `Invoice::operator=` |
| 16 | Search functions | `Library::searchByTitle()` and `Library::searchByID()` |
| 17 | Array-based collections | Library item array, room array, course enrolled student array |
| 18 | Arrays of objects | `Room rooms[MAX_BLOCK_ROOMS]` in `HostelBlock` |
| 19 | Exception handling | `try/catch` in `main.cpp`, custom exceptions in `Exceptions.h` |
| 20 | File I/O | `Library::saveCatalog()`, `Library::loadCatalog()`, report file output |
| 21 | Reports and utilities | `Reports.h/.cpp`, `Utils.h/.cpp` |
| 22 | Memory management | `new Book`, `new Journal`, `delete` in `Library`, `new[]/delete[]` in `Invoice` |
| 23 | Sorting and searching | `Reports::sortStudentsByGPA()`, `Library::searchByTitle()` |
| 24 | Composition | `HostelManager` contains a `HostelBlock` object |
| 25 | Aggregation | `Course` keeps `Faculty* instructor`, `Room` keeps `Student* occupants[]` |

## Things to personalize

- Add your own sample students.
- Add at least one new menu option yourself so you can explain the change.
- Make your own UML image from these relationships.

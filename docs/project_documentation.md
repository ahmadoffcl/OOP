# Smart Campus Management System Documentation

## Group Members

- Ahmad Ali | Reg No: 25-CS-067
- Umer Altaf | Reg No: 25-CS-057
- Muhammed Ahmad | Reg No: 25-CS-252

## Project Purpose

The Smart Campus Management System is a simple command-line C++ project for managing basic university operations. It is written in a beginner-friendly style using classes, inheritance, arrays, file handling, exception handling, and operator overloading.

## Folder Structure

- `src/person`: Person, Student, GradStudent, Faculty, Staff, PersonManager
- `src/course`: Course and Enrollment
- `src/library`: LibraryItem, Book, Journal, Library
- `src/finance`: FeeRecord and Invoice
- `src/hostel`: Room, HostelBlock, HostelManager, interfaces
- `src/utils`: Exceptions, Reports, Utils
- `data`: text files used by the program
- `docs`: notes, viva questions, diagram source, and checklists

## Main Menu

1. Person module
2. Course and Enrollment module
3. Library module
4. Fee and Finance module
5. Hostel module
6. Reports module
0. Exit

Each module opens its own submenu as a separate screen. The console is cleared before each menu or action page. Option `0` inside any module returns to the home menu. This keeps the output cleaner and makes the console interface easier to use.

## Phase 1 Summary

Phase 1 covers the person and course modules. `Person` is an abstract base class. `Student`, `GradStudent`, `Faculty`, and `Staff` inherit from it. `PersonManager` stores saved people in a simple array, loads/saves `data/person_records.txt`, and supports add/delete/search actions. Course enrollment uses a capacity exception and operator overloading.

Detailed status files:

- `docs/module1_status.md`
- `docs/module2_status.md`
- `docs/module3_status.md`
- `docs/module4_status.md`
- `docs/module5_status.md`
- `docs/module6_status.md`

## Phase 2 Summary

Phase 2 covers library and finance. The Library class stores `LibraryItem*` pointers, loads catalog data from `data/library_catalog.txt`, searches items, issues items, handles overdue fines, and saves output. Finance uses `FeeRecord`, `Invoice`, deep copy, copy constructor, copy assignment, static invoice counter, and destructor.

## Phase 3 Summary

Phase 3 covers hostel and reports. HostelManager uses multiple inheritance and composition. Reports sort students by GPA and write `data/campus_report.txt`.

## Build and Run

```powershell
cd D:\HITEC-OOP-SCMS-25-CS-067
.\build.bat
.\scms.exe
```

Or:

```powershell
.\run.bat
```

The compiler is installed at:

```text
D:\tools\w64devkit\bin\g++.exe
```

## Important Note

The code is intentionally simple. Read and edit it before viva so every group member can explain it.

# Smart Campus Management System (SCMS)

![Build SCMS](https://github.com/ahmadoffcl/OOP/actions/workflows/build.yml/badge.svg)

## Project Information

- Course: CS-104L Object-Oriented Programming
- University: HITEC University Taxila
- Language: C++
- Interface: Command Prompt / Console
- GitHub Repository: https://github.com/ahmadoffcl/OOP

## Group Members

| Name | Registration No |
|------|-----------------|
| Ahmad Ali | 25-CS-067 |
| Umer Altaf | 25-CS-057 |
| Muhammed Ahmad | 25-CS-252 |

Note: The project brief mentions individual/team of 2. Confirm with the instructor if a 3-member group is allowed.

## Project Overview

Smart Campus Management System is a beginner-friendly C++ console project for managing common university records. It uses simple arrays, classes, inheritance, polymorphism, file handling, exception handling, operator overloading, static members, copy constructors, copy assignment, composition, and multiple inheritance.

The program uses a clean screen-based menu system. Every module opens as its own page, every action clears the previous screen, and every module has `0. Back to Home`.

## Quick Links

| Item | Location |
|------|----------|
| Source code | `src/` |
| Saved data files | `data/` |
| UML class diagram | `docs/class_diagram.png` |
| Project report PDF | `docs/project_report.pdf` |
| Manual test plan | `docs/manual_test_plan.md` |
| Test output logs | `docs/test_outputs/` |
| Viva questions | `docs/viva_questions_full.md` |
| GitHub Actions workflow | `.github/workflows/build.yml` |

## Current Submission Status

The project is ready for final review and submission:

- All 6 required modules are implemented.
- Demo-only flows have been replaced with real keyboard-input actions.
- Records are saved in text files under `data/`.
- Build script and run script are included.
- GitHub Actions workflow is included.
- Class diagram, report PDF, screenshots, test outputs, viva questions, and documentation are included.
- The repository has been pushed to GitHub.

## UML Class Diagram

The diagram below shows the main classes and relationships used in the project, including inheritance, composition, aggregation, and manager classes.

![UML Class Diagram](docs/class_diagram.png)

## Modules

1. Person Hierarchy
   - `Person`, `Student`, `GradStudent`, `Faculty`, `Staff`
   - Add, view, delete, save, reload, and course assignment for saved people

2. Course and Enrollment Management
   - `Course`, `Enrollment`, `CourseManager`
   - Add/search courses, enroll/drop students, waiting list, save/reload, operator overloads

3. Library System
   - `LibraryItem`, `Book`, `Journal`, `Library`
   - Add/search/delete catalog items, issue/return items, overdue fine, saved issued records

4. Fee and Finance Management
   - `FeeRecord`, `Invoice`, `FinanceManager`
   - Add/search fee records, payments using `-=`, fines, invoice generation, copy semantics, static counter

5. Hostel Management
   - `Accommodation`, `Reportable`, `Room`, `HostelBlock`, `HostelManager`
   - Saved rooms, saved allocations, add/search/delete room, allocate/vacate student, occupancy report

6. Reporting and Utilities
   - `Reports`, `Utils`
   - Complete campus summary, GPA sorting, roll-number search, overdue library records, consolidated text report, PDF-style text report, date/helper functions

## Build and Run

Windows PowerShell:

```powershell
cd D:\HITEC-OOP-SCMS-25-CS-067
.\build.bat
.\scms.exe
```

Or run directly:

```powershell
.\run.bat
```

GitHub Actions/Linux compile command:

```bash
g++ -std=c++17 -Wall -Wextra src/main.cpp src/person/*.cpp src/course/*.cpp src/library/*.cpp src/finance/*.cpp src/hostel/*.cpp src/utils/*.cpp -o scms
./scms
```

## How to Use the App

Run `scms.exe`, select a module from the home screen, perform the needed action, then press Enter to return to that module menu. Use `0. Back to Home` from any module.

Main menu:

```text
1. Person Module
2. Course and Enrollment Module
3. Library Module
4. Fee and Finance Module
5. Hostel Module
6. Reports Module
0. Exit
```

## Data Files

| File | Purpose |
|------|---------|
| `data/person_records.txt` | Saved students, faculty, and staff |
| `data/courses.txt` | Saved course records |
| `data/enrollments.txt` | Saved enrollment/waiting-list records |
| `data/library_catalog.txt` | Saved books and journals |
| `data/library_issued.txt` | Saved issued/returned library records |
| `data/fee_records.txt` | Saved student fee records |
| `data/hostel_rooms.txt` | Saved hostel room records |
| `data/hostel_allocations.txt` | Saved hostel student allocations |
| `data/campus_report.txt` | Generated consolidated campus report |
| `data/campus_pdf_report.txt` | Generated PDF-style text report |

## OOP Concepts Covered

| Concept | Example |
|---------|---------|
| Abstract class | `Person`, `LibraryItem`, `Accommodation`, `Reportable` |
| Pure virtual function | `displayInfo()`, `checkout()`, `allocateRoom()` |
| Single inheritance | `Student : Person` |
| Multi-level inheritance | `GradStudent : Student : Person` |
| Multiple inheritance | `HostelManager : Accommodation, Reportable` |
| Virtual inheritance | `Accommodation` and `Reportable` virtually inherit `CampusService` |
| Runtime polymorphism | `Person* people[]`, `LibraryItem* items[]` |
| Encapsulation | Private data with getters/setters |
| Arrays of objects | `Course courses[]`, `Room rooms[]`, `FeeRecord records[]` |
| Arrays of pointers | `Person*`, `Student*`, `LibraryItem*` arrays |
| Operator overloading | `Course ==`, `Course <<`, `Course +`, `FeeRecord -=` |
| Friend function | `operator<<` for `Course` and `Invoice` |
| Custom exceptions | `CapacityExceededException`, `OverdueException` |
| Static member | `Invoice::invoiceCounter` |
| Copy constructor/assignment | `Course`, `FeeRecord`, `Invoice` |
| File I/O | All main modules save/load text files |
| Sorting/searching | `std::sort`, `std::find_if`, loop searches |
| Dynamic memory | `new`, `delete`, `new[]`, `delete[]` |
| Composition | `HostelManager` owns `HostelBlock`, `HostelBlock` owns `Room` array |
| Aggregation | `Course` stores `Faculty*`, `Room` stores `Student*` |

## Documentation and Deliverables

| Deliverable | File |
|-------------|------|
| Project report | `docs/project_report.pdf` |
| UML class diagram | `docs/class_diagram.png` |
| Screenshot-style outputs | `docs/screenshots/` |
| Captured console outputs | `docs/test_outputs/` |
| Manual test checklist | `docs/manual_test_plan.md` |
| Latest test evidence | `docs/testing_log.md` |
| Viva questions and answers | `docs/viva_questions_full.md` |
| OOP concept mapping | `docs/oop_concepts_checklist.md` |
| GitHub Actions workflow | `.github/workflows/build.yml` |

## Final Submission Notes

- GitHub URL is already included: https://github.com/ahmadoffcl/OOP
- `docs/project_report.pdf` includes the final GitHub URL.
- `docs/class_diagram.png` is included and rendered in this README.
- CI build workflow is included for compile/smoke-test evidence.
- The project is intentionally written in simple C++ so it can be explained in viva.

## Final Review Checklist

- Run `.\build.bat`.
- Run `.\scms.exe` and test each module using `docs/manual_test_plan.md`.
- Read `docs/viva_questions_full.md`.
- Open `docs/project_report.pdf` and `docs/class_diagram.png`.

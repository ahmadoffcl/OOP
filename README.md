# Smart Campus Management System (SCMS)

## Project Info
- Group Members:
  - Ahmad Ali | Reg No: 25-CS-067
  - Umer Altaf | Reg No: 25-CS-057
  - Muhammed Ahmad | Reg No: 25-CS-252
- Course: CS-104L Object-Oriented Programming
- University: HITEC University Taxila

Note: The project brief mentions individual/team of 2. Confirm with the instructor if a 3-member group is allowed.

## Current Status
This is a learning starter for the SCMS project. It currently includes a simple command-line program for all main modules:

- Person hierarchy: `Person`, `Student`, `GradStudent`, `Faculty`, `Staff`
- Course and enrollment management: `Course`, `Enrollment`
- Basic exception handling with `CapacityExceededException`
- Library starter: `LibraryItem`, `Book`, `Journal`, `Library`
- Finance starter: `FeeRecord`, `Invoice`
- Hostel starter: `Accommodation`, `Reportable`, `Room`, `HostelBlock`, `HostelManager`
- Reports starter: `Reports` and `Utils`
- Simple arrays, constructors, getters/setters, inheritance, polymorphism, file handling, and operator overloading
- Clean console interface with separate module screens and `0. Back to Home` options

You should still complete and personalize the project before submission:

- Replace sample names, CNICs, fees, and roll numbers with your own values
- Add more menu input instead of only fixed demo data
- Improve file loading/saving after you understand the starter code
- Review `docs/class_diagram.png`
- Review and improve `docs/project_report.pdf` with your own screenshots

## How to Compile

### Windows PowerShell with g++
```powershell
.\build.bat
.\scms.exe
```

Or:

```powershell
.\run.bat
```

### Windows PowerShell with the included D: drive compiler
```powershell
$env:PATH = "D:\tools\w64devkit\bin;$env:PATH"
.\build.bat
.\scms.exe
```

### Linux or GitHub Actions style
```bash
g++ -std=c++17 -Wall -Wextra src/main.cpp src/person/*.cpp src/course/*.cpp src/library/*.cpp src/finance/*.cpp src/hostel/*.cpp src/utils/*.cpp -o scms
./scms
```

## OOP Concepts Already Demonstrated

1. Classes and objects: all C++ classes in `src/`
2. Encapsulation: private data with public getters and setters
3. Constructors: default and parameterized constructors
4. Copy constructor: `Person` and `Course`
5. Single inheritance: `Student : Person`
6. Multi-level inheritance: `GradStudent : Student : Person`
7. Abstract class: `Person`
8. Pure virtual function: `displayInfo()`
9. Runtime polymorphism: `Person* people[]` in `main.cpp`
10. Operator overloading: `Course ==`, `Course <<`, `Course +`
11. Friend function: `operator<<` for `Course`
12. Custom exception: `CapacityExceededException`
13. Aggregation: `Course` stores a `Faculty*`
14. Array-based collections: course arrays, people arrays, library arrays, hostel room arrays
15. File I/O: `Library::saveCatalog`, `Library::loadCatalog`, campus text report
16. Static members: `Invoice::invoiceCounter`
17. Copy assignment: `FeeRecord` and `Invoice`
18. Multiple inheritance: `HostelManager`
19. Virtual inheritance: `Accommodation` and `Reportable`
20. Composition: `HostelManager` contains `HostelBlock`

## Remaining Work Checklist

- Add real user input for adding students/courses/books
- Add more checks for wrong input
- Add more records in `data/students.txt`
- Add your own comments explaining each OOP concept
- Add `docs/class_diagram.png`
- Add `docs/project_report.pdf`
- Follow `docs/manual_test_plan.md` after installing g++

## Interface Flow

The home menu opens each module separately. Inside a module, select the task you want, then use `0` to go back home. This keeps the output cleaner instead of printing the home menu directly under every result.

## Documentation Files

- `docs/project_documentation.md`: project overview and module explanation
- `docs/module1_status.md`: Person hierarchy completion status
- `docs/module2_status.md`: Course and Enrollment completion status
- `docs/oop_concepts_checklist.md`: where each OOP concept is used
- `docs/viva_questions_full.md`: viva questions and short answers
- `docs/phase2_status.md`: Library and Finance phase status
- `docs/manual_test_plan.md`: manual testing steps
- `docs/testing_log.md`: latest test evidence
- `docs/remaining_work.md`: what is left before final submission
- `docs/class_diagram.mmd`: class diagram source
- `docs/class_diagram.png`: generated class diagram image
- `docs/project_report.pdf`: generated report draft

## Important
Do not submit this starter without understanding and changing it. Your viva will test whether you can explain and modify your own code.

# Manual Test Plan

After installing `g++`, run:

```powershell
cd D:\HITEC-OOP-SCMS-25-CS-067
.\build.bat
.\scms.exe
```

On this computer, a portable compiler is installed here:

```text
D:\tools\w64devkit\bin\g++.exe
```

You can also run:

```powershell
cd D:\HITEC-OOP-SCMS-25-CS-067
.\run.bat
```

Then test menu choices:

| Choice | Expected result |
|--------|-----------------|
| 1 then 1 | Shows all saved student, grad student, faculty, and staff information |
| 1 then 2 | Shows saved student list |
| 1 then 3 | Adds a new student from keyboard input |
| 1 then 4 | Adds a new grad student from keyboard input |
| 1 then 5 | Adds a new faculty record from keyboard input |
| 1 then 6 | Adds a new staff record from keyboard input |
| 1 then 7 | Adds a course code to a saved student |
| 1 then 8 | Deletes a person by roll no, employee ID, or staff ID |
| 1 then 9 | Saves records to `data/person_records.txt` |
| 1 then 10 | Reloads records from `data/person_records.txt` |
| 2 then 1 | Shows all saved courses from `data/courses.txt` |
| 2 then 2 | Adds a new course from keyboard input using a saved faculty employee ID |
| 2 then 3 | Searches a saved course by course code |
| 2 then 4 | Enrolls a saved student by roll number into a saved course |
| 2 then 5 | Shows selected course roster with enrolled and waiting students |
| 2 then 6 | Drops a student from enrolled or waiting list |
| 2 then 7 | Compares two courses using `==` |
| 2 then 8 | Merges two course waiting lists using `+` |
| 2 then 9 | Shows saved enrollment records with status |
| 2 then 10 | Saves courses and enrollments to text files |
| 2 then 11 | Reloads courses and enrollments from text files |
| 3 then 1 | Shows library catalog from `data/library_catalog.txt` |
| 3 then 2 | Adds a book from keyboard input |
| 3 then 3 | Adds a journal from keyboard input |
| 3 then 4 | Searches library catalog by title |
| 3 then 5 | Searches library catalog by item ID |
| 3 then 6 | Issues a saved item to a saved student roll number |
| 3 then 7 | Returns an issued item and shows overdue fine when late |
| 3 then 8 | Shows issued item records |
| 3 then 9 | Deletes a library item by item ID |
| 3 then 10 | Saves catalog and issued records |
| 3 then 11 | Reloads catalog and issued records |
| 4 then 1 | Shows all saved fee records |
| 4 then 2 | Adds a fee record for a saved student |
| 4 then 3 | Searches a fee record by roll number |
| 4 then 4 | Records payment using overloaded `-=` |
| 4 then 5 | Adds library fine to a fee record |
| 4 then 6 | Shows payment history |
| 4 then 7 | Generates invoice and shows static counter |
| 4 then 8 | Shows FeeRecord copy constructor and assignment |
| 4 then 9 | Saves finance records |
| 4 then 10 | Reloads finance records |
| 5 then 1 | Shows hostel service name |
| 5 then 2 | Shows all saved hostel rooms and current occupants |
| 5 then 3 | Adds a hostel room from keyboard input |
| 5 then 4 | Searches a room by room number |
| 5 then 5 | Allocates a saved student to a selected room |
| 5 then 6 | Auto-allocates a saved student to the first available room |
| 5 then 7 | Vacates a student room by roll number |
| 5 then 8 | Shows which room a student is in |
| 5 then 9 | Shows hostel summary |
| 5 then 10 | Prints occupancy report |
| 5 then 11 | Saves hostel room/allocation records |
| 5 then 12 | Reloads hostel room/allocation records |
| 5 then 13 | Deletes an empty room |
| 6 then 1 | Shows complete campus summary from all managers |
| 6 then 2 | Sorts students by GPA |
| 6 then 3 | Finds student by roll number |
| 6 then 4 | Shows top GPA student |
| 6 then 5 | Shows overdue library records |
| 6 then 6 | Writes consolidated `data/campus_report.txt` |
| 6 then 7 | Writes consolidated `data/campus_pdf_report.txt` |
| 6 then 8 | Shows utility/date helper examples |
| module 0 | Returns to home menu |
| 0 | Exits the program |

After each action page, press Enter to return to the current module menu.

Also test a wrong input:

- Type a letter like `abc`.
- Program should not freeze.
- It should print `Wrong choice. Try again.`

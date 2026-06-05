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
| 1 then 1 | Shows student, grad student, faculty, and staff information |
| 1 then 2 | Shows compact student list |
| 2 then 1 | Shows OOP course information |
| 2 then 2 | Enrolls first student and sends second to waiting list because capacity is 1 |
| 2 then 3 | Shows enrolled and waiting students |
| 2 then 4 | Compares courses using `==` |
| 2 then 5 | Merges waiting lists using `+` |
| 3 then 1 | Loads library catalog from `data/library_catalog.txt` |
| 3 then 2 | Shows library catalog |
| 3 then 3 | Searches C++ book by title |
| 3 then 4 | Issues item `B001` to `25-CS-067` |
| 3 then 5 | Returns item `B001` with overdue fine |
| 3 then 6 | Shows issued item records |
| 3 then 7 | Saves library catalog |
| 4 then 1 | Shows fee record, payment using `-=`, and payment history |
| 4 then 2 | Shows fee copy constructor and assignment with copied payment history |
| 4 then 3 | Shows invoice, copied invoice, assigned invoice, and static counter |
| 5 then 1 | Shows hostel service name |
| 5 then 2 | Allocates students to hostel rooms |
| 5 then 3 | Tries duplicate allocation and blocks it |
| 5 then 4 | Shows hostel summary |
| 5 then 5 | Prints occupancy report |
| 5 then 6 | Vacates Ahmad Ali room |
| 6 then 1 | Sorts students by GPA |
| 6 then 2 | Finds student by roll number |
| 6 then 3 | Shows top GPA student |
| 6 then 4 | Writes `data/campus_report.txt` |
| 6 then 5 | Writes `data/campus_pdf_report.txt` |
| module 0 | Returns to home menu |
| 0 | Exits the program |

Also test a wrong input:

- Type a letter like `abc`.
- Program should not freeze.
- It should print `Wrong choice. Try again.`

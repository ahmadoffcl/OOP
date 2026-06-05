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
| 1 | Shows student, grad student, faculty, and staff information |
| 2 | Shows OOP course information |
| 3 | Enrolls first student and sends second to waiting list because capacity is 1 |
| 4 | Shows library items, searches C++ book, issues and returns with overdue fine |
| 5 | Shows fee record, payment using `-=`, copied fee record, and invoice |
| 6 | Allocates students to hostel rooms and prints occupancy report |
| 7 | Sorts students by GPA and writes `data/campus_report.txt` |
| 0 | Exits the program |

Also test a wrong input:

- Type a letter like `abc`.
- Program should not freeze.
- It should print `Wrong choice. Try again.`

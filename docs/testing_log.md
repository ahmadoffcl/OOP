# Testing Log

Date: 2026-06-05

## Compiler

Compiler installed:

```text
D:\tools\w64devkit\bin\g++.exe
```

Compiler version:

```text
g++.exe (GCC) 16.1.0
```

## Build Test

Command:

```powershell
.\build.bat
```

Result:

```text
Build successful.
Run with: scms.exe
```

## Menu Smoke Test

Test input:

```text
1
1
2
0
2
1
2
3
4
5
0
3
1
2
3
C++ Basics
4
5
6
7
0
4
1
2
3
0
5
1
2
3
4
5
6
0
6
1
2
0
0
```

Result:

- Person module printed records and compact student list.
- Course module printed course details, enrollment exception, enrolled/waiting students, course comparison, and waiting list merge.
- Library module loaded/showed library items, searched title, issued book `B001`, returned with overdue fine, displayed issued records, and saved catalog.
- Finance module showed fee payment, payment history, fee copy, fee assignment, invoice copy, invoice assignment, and static counter.
- Hostel module printed service name, allocated students, blocked duplicate allocation, showed summary, printed occupancy report, and vacated one student.
- Reports module sorted students by GPA and wrote `data/campus_report.txt`.
- Every module used `0. Back to Home`.
- Home option `0` exited program.

## Wrong Input Test

Input:

```text
abc
0
```

Result:

- Program did not freeze.
- Program printed wrong choice message.
- Program exited after `0`.

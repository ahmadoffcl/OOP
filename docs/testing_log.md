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
2
3
4
5
6
7
0
```

Result:

- Option 1 printed person records.
- Option 2 printed course information.
- Option 3 enrolled one student and showed capacity exception.
- Option 4 loaded/showed library items and showed overdue fine.
- Option 4 also issued book `B001` to `25-CS-067`.
- Option 5 showed fee payment, fee copy, fee assignment, invoice, and invoice copy.
- Option 6 allocated students to hostel room.
- Option 7 sorted students by GPA and wrote `data/campus_report.txt`.
- Option 0 exited program.

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

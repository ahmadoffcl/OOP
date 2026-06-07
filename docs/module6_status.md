# Module 6 Status - Reporting and Utilities

Status: Complete, real system-wide reporting, and tested.

## Required Files

- `Reports.h`
- `Reports.cpp`
- `Utils.h`
- `Utils.cpp`

## Required Operations

- Show a complete campus summary using data from all managers.
- Sort students by GPA with `std::sort`.
- Search student by roll number with `std::find_if`.
- Show top GPA student.
- Show overdue library records.
- Generate a consolidated campus text report.
- Generate a consolidated PDF-style text report.
- Use helper functions for date, formatting, and validation.
- Use dynamic array copy with `new[]` and `delete[]` in report generation.
- Use loops for report output.

## Menu Options

```text
1. Show complete campus summary
2. Sort and show students by GPA
3. Find student by roll number
4. Show top GPA student
5. Show overdue library records
6. Generate consolidated text report
7. Generate consolidated PDF-style report
8. Show utility/date helper info
0. Back to Home
```

## Report Output

The report files are written to:

```text
data/campus_report.txt
data/campus_pdf_report.txt
```

The consolidated reports include:

- Project heading
- Date
- University/course/group information
- Total people and students
- Course and enrollment counts
- Library item, issued, active issued, and overdue counts
- Fee record totals, paid amount, balance, and library fine total
- Hostel room and occupant counts
- Students sorted by GPA
- Course summary
- Finance summary
- Module coverage
- OOP concepts highlight

## OOP/Programming Concepts Covered

- Reporting functions
- Utility helper functions
- Sorting with `std::sort`
- Searching with `std::find_if`
- File output with `ofstream`
- Memory management with `new[]` and `delete[]`
- Array traversal
- Cross-module data reading

## Where It Is Tested

Run:

```text
Home -> 6. Reports Module -> 1. Show complete campus summary
Home -> 6. Reports Module -> 2. Sort and show students by GPA
Home -> 6. Reports Module -> 3. Find student by roll number
Home -> 6. Reports Module -> 4. Show top GPA student
Home -> 6. Reports Module -> 5. Show overdue library records
Home -> 6. Reports Module -> 6. Generate consolidated text report
Home -> 6. Reports Module -> 7. Generate consolidated PDF-style report
Home -> 6. Reports Module -> 8. Show utility/date helper info
```

Expected result:

- Campus summary shows counts from all main modules.
- Students display in GPA order.
- Roll number search finds `25-CS-067`.
- Top GPA student displays.
- Overdue library records are shown or a clear empty message is printed.
- `data/campus_report.txt` is generated.
- `data/campus_pdf_report.txt` is generated.
- Utility/date helper page displays date and validation examples.

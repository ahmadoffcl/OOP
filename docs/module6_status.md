# Module 6 Status - Reporting and Utilities

Status: Complete and tested.

## Required Files

- `Reports.h`
- `Reports.cpp`
- `Utils.h`
- `Utils.cpp`

## Required Operations

- Sort students by GPA.
- Search student by roll number.
- Show top GPA student.
- Generate consolidated campus text report.
- Generate PDF-style text report.
- Use helper functions for date and formatting.
- Use `std::sort` with custom comparator.
- Use `std::find_if` for roll number search.
- Use dynamic array copy with `new[]` and `delete[]` inside PDF-style report generation.
- Use loops for report output.

## Report Output

The report is written to:

```text
data/campus_report.txt
data/campus_pdf_report.txt
```

It includes:

- Project heading
- Date
- University/course/group information
- Total student count
- Library item count
- Student list
- Top student by GPA
- Sorted student section in PDF-style text report
- OOP concepts highlight in PDF-style text report

## OOP/Programming Concepts Covered

- Reporting functions
- Utility helper functions
- Sorting with `std::sort`
- Searching with `std::find_if`
- File output with `ofstream`
- Memory management with `new[]` and `delete[]`
- Array traversal

## Where It Is Tested

Run:

```text
Home -> 6. Reports Module -> 1. Sort and show students by GPA
Home -> 6. Reports Module -> 2. Find student by roll number
Home -> 6. Reports Module -> 3. Show top GPA student
Home -> 6. Reports Module -> 4. Generate campus text report
Home -> 6. Reports Module -> 5. Generate PDF-style text report
```

Expected result:

- Students display in GPA order.
- Roll number search finds `25-CS-067`.
- Top student displays.
- `data/campus_report.txt` is generated.
- `data/campus_pdf_report.txt` is generated.

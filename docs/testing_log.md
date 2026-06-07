# Testing Log

Date: 2026-06-07

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
The full scripted input now includes blank lines after each action page.
Those blank lines press Enter for the new screen-based pause.
See `.github/workflows/build.yml` for the exact CI smoke-test sequence.
```

Result:

- Person module printed records and compact student list.
- Module 1 CRUD test added a student, displayed it, saved, reloaded, deleted it, saved again, and reloaded again.
- Module 1 course assignment test added `CS-200` to `25-CS-067` for the session and displayed it.
- Module 2 course manager added `CS-220`, searched it, enrolled two students, sent a third student to waiting list using `CapacityExceededException`, showed roster, compared courses, merged waiting lists, displayed enrollment records, dropped a waiting student, saved records, reloaded records, and verified `CS-220` remained after reload.
- Library module loaded/showed library items, searched title, issued book `B001`, returned with overdue fine, displayed issued records, and saved catalog.
- Finance module showed fee payment, payment history, fee copy, fee assignment, invoice copy, invoice assignment, and static counter.
- Hostel module printed service name, allocated students, blocked duplicate allocation, showed summary, printed occupancy report, and vacated one student.
- Reports module sorted students by GPA, searched by roll number, showed top GPA student, wrote `data/campus_report.txt`, and wrote `data/campus_pdf_report.txt`.
- Every module used `0. Back to Home`.
- Every action page waited for Enter before showing the next menu.
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

## Report Deliverable Check

Command:

```powershell
python tools\generate_deliverables.py
```

Result:

- `docs/class_diagram.png` regenerated.
- `docs/screenshots/module1_person.png` regenerated.
- `docs/screenshots/module1_crud_test.png` regenerated.
- `docs/screenshots/module1_add_course_test.png` regenerated.
- `docs/screenshots/module2_course.png` regenerated from the real Module 2 course/enrollment flow.
- `docs/screenshots/module3_library.png` regenerated.
- `docs/screenshots/module4_finance.png` regenerated.
- `docs/screenshots/module5_hostel.png` regenerated.
- `docs/screenshots/module6_reports.png` regenerated.
- `docs/screenshots/wrong_input.png` regenerated.
- `docs/project_report.pdf` regenerated.

The generated PDF was checked and contains:

- GitHub Workflow section.
- OOP Concepts Implementation section.
- Testing Summary section.
- Output screenshot pages.
- GitHub URL placeholder that must be replaced after pushing to GitHub.

## GitHub Actions Workflow Check

The workflow file `.github/workflows/build.yml` includes:

- `g++ -std=c++17 -Wall -Wextra` compile command.
- Automated menu smoke test through all six modules.
- File checks for `data/campus_report.txt` and `data/campus_pdf_report.txt`.

## GitHub URL Helper Check

Command:

```powershell
python tools\finalize_github_url.py --dry-run https://github.com/test-user/HITEC-OOP-SCMS-25-CS-067
```

Result:

- Dry run passed.
- No fake URL was written to README or PDF.

Command:

```powershell
python tools\generate_deliverables.py --github-url "add public repository link after pushing"
```

Result:

- PDF regenerated successfully with the placeholder GitHub URL.

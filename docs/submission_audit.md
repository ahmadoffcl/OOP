# Submission Audit

Date: 2026-06-07

## Local Work Done

- D drive project folder: `D:\HITEC-OOP-SCMS-25-CS-067`
- Portable compiler available: `D:\tools\w64devkit\bin\g++.exe`
- Build script: `build.bat`
- Run script: `run.bat`
- All six assignment modules are implemented in `src/`
- Required source folder structure is present
- `.gitignore` ignores build artifacts and generated runtime files
- Header guards are present in header files
- File header comments are present in source/header files
- UML image exists at `docs/class_diagram.png`
- Report draft exists at `docs/project_report.pdf`
- Test output logs exist in `docs/test_outputs/`
- Screenshot-style output images exist in `docs/screenshots/`
- Viva questions exist in `docs/viva_questions_full.md`
- GitHub URL finalization helper exists at `tools/finalize_github_url.py`
- GitHub Actions build workflow exists at `.github/workflows/build.yml`
- The workflow compiles the project, runs a menu smoke test, and checks generated report files.

## Verified Locally

- `build.bat` compiles successfully with `g++ -std=c++17 -Wall -Wextra`
- Home menu opens all six modules
- Each module has `0. Back to Home`
- Wrong text input does not freeze the program
- Module 2 real course/enrollment flow works: add course, search, enroll, waiting list, roster, drop, save, reload, compare, and merge waiting lists
- Library add/search/issue/duplicate block/return/overdue/delete/save/reload flow works
- Finance add/search/payment/fine/history/invoice/save/reload flow works, with deep copy, destructor-backed dynamic array design, and static counter demonstrated
- Hostel add/search/delete room, allocate, duplicate allocation check, save/reload, report, and vacate flow work
- Reports sorting, searching, top student, text report generation, and PDF-style text report generation work

## Still Needed Before Portal Submission

- Confirm with instructor that 3 group members are allowed, because the PDF says individual/team of 2.
- Create a public GitHub repository named `HITEC-OOP-SCMS-25-CS-067`.
- Push the local repository to GitHub.
- Put the final public GitHub URL in `README.md` and the project report.
- Share the repository URL through the course portal.
- Every group member should read and understand the code before viva.

## Note About Commit Count

The PDF has two different commit-history hints: one place says at least 2 commits, while the marking table mentions commit history with `20+`. This local repository has multiple meaningful commits, one for each major phase/module, but it does not have 20+ commits. Ask the lab instructor if that marking note is strict.

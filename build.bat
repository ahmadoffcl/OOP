@echo off
set "COMPILER=D:\tools\w64devkit\bin\g++.exe"
set "COMPILER_DIR=D:\tools\w64devkit\bin"

if exist "%COMPILER%" (
    set "PATH=%COMPILER_DIR%;%PATH%"
    set "GPP=%COMPILER%"
) else (
    set "GPP=g++"
)

"%GPP%" -std=c++17 -Wall -Wextra ^
src\main.cpp ^
src\person\Person.cpp src\person\Student.cpp src\person\GradStudent.cpp src\person\Faculty.cpp src\person\Staff.cpp ^
src\course\Course.cpp src\course\Enrollment.cpp ^
src\library\LibraryItem.cpp src\library\Book.cpp src\library\Journal.cpp src\library\Library.cpp ^
src\finance\FeeRecord.cpp src\finance\Invoice.cpp ^
src\hostel\Room.cpp src\hostel\HostelBlock.cpp src\hostel\HostelManager.cpp ^
src\utils\Utils.cpp src\utils\Reports.cpp ^
-o scms.exe

if %errorlevel% equ 0 (
    echo Build successful.
    echo Run with: scms.exe
) else (
    echo Build failed. Check D:\tools\w64devkit or install g++ and add it to PATH.
)

@echo off
call build.bat
if %errorlevel% equ 0 (
    scms.exe
)

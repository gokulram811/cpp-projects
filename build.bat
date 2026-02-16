@echo off
setlocal enabledelayedexpansion

:: Create build directory if it doesn't exist
if not exist build mkdir build

echo 🚀 Starting Build Process...

:: Clean up previous executable to avoid file-in-use errors
if exist MathMaster.exe del MathMaster.exe

echo 📦 Compiling Modules...
:: Calculus and Vector libraries are header-only, so we compile main.cpp 
:: while including the header search paths.

clang++ -std=c++20 -I./include main.cpp -o MathMaster.exe

:: Check if the compilation was successful
if %errorlevel% neq 0 (
    echo.
    echo ❌ [ERROR] Build failed! Please check for syntax errors in your .hpp files.
) else (
    echo.
    echo ✅ [SUCCESS] Build complete! 
    echo 🕹️  Run the tool by typing: MathMaster.exe
)

pause
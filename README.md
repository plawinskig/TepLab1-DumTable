# TepLab1

This repository contains a simple C++ console application built with Visual Studio using the `TepLab1.sln` solution file.

## Project Structure

- `TepLab1/` - Visual Studio project folder
  - `main.cpp` - application entry point
  - `table.cpp`, `table.hpp` - table class implementation
  - `print_table.cpp`, `print_table.hpp` - printing utility functions
  - `alloc_dealloc_tables.cpp`, `alloc_dealloc_tables.hpp` - dynamic allocation utilities

## Requirements

- Microsoft Visual Studio on Windows
- C++ toolset / MSVC

## Build and Run

### Option 1: Open in Visual Studio

1. Open `TepLab1.sln` in Visual Studio.
2. Set the desired configuration (Debug or Release).
3. Build the solution.
4. Run the project from Visual Studio.

### Option 2: Build from the command line

1. Open a Developer Command Prompt for Visual Studio.
2. Change to the repository root, for example:

```powershell
cd <path-to-repository-root>
```

3. Build the solution with MSBuild:

```powershell
msbuild TepLab1.sln /p:Configuration=Debug
```

4. Run the generated executable. For the default x64 Debug build, it will be located in:

```powershell
x64\Debug\TepLab1.exe
```

or for Release builds:

```powershell
x64\Release\TepLab1.exe
```

If you build for a different platform, replace `x64` with the target platform folder used by MSBuild/Visual Studio.

## What it does

The program demonstrates:

- dynamic allocation of 2D arrays
- deallocation of dynamic memory
- creation and manipulation of `Table` objects
- cloning and modifying table instances
- printing table contents to the console

## Notes

- If you use a different Visual Studio version, make sure the project is compatible with your installed toolset.
- Clean and rebuild the solution if you change source files.
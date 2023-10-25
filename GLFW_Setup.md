# GLFW Setup Guide for OpenGL C++ Teaching Resource

This guide provides detailed instructions on how to set up GLFW (Graphics Library Framework) for your OpenGL project.

## Steps to Include GLFW in Your Project

### Step 1: Download GLFW

1. Go to the [GLFW website](https://www.glfw.org/download.html) and download the latest version.

### Step 2: Extract and Include Files

1. Extract the downloaded package.
2. You will find include files in the `include` directory and library files in the `lib` directory.

### Step 3: Add to Your Project

1. Copy the include files into your project's include directory.
2. Copy the library files (`.lib` for Windows) into your project's library directory.

### Step 4: Link Libraries

In your project settings:

1. Add the include directory to your compiler's include directories.
2. Add the library directory to your linker's library directories.
3. Link against `glfw3.lib` (for Windows).

### Step 5: Use GLFW in Your Code

To use GLFW, include it like any other header:

```cpp
#include <GLFW/glfw3.h>

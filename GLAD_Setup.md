
### GLAD_Setup.md

```markdown
# GLAD Setup Guide for OpenGL C++ Teaching Resource

This guide provides detailed instructions on how to set up GLAD (OpenGL Loader-Generator) for your OpenGL project.

## Steps to Include GLAD in Your Project

### Step 1: Generate GLAD Loader

1. Go to [GLAD's web service](https://glad.dav1d.de/) and generate a loader based on your requirements.

### Step 2: Download and Include Files

1. Download the generated package and extract it.
2. You will find include files in the `include` directory and source files in the `src` directory.

### Step 3: Add to Your Project

1. Copy the include files into your project's include directory.
2. Copy the source files into your project's source directory.

### Step 4: Link Libraries

No additional linking is required for GLAD as it will be compiled into your project.

### Step 5: Use GLAD in Your Code

To use GLAD, include it before any other OpenGL headers:

```cpp
#include <glad/glad.h>

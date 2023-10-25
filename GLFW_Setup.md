# GLFW Setup Guide for OpenGL C++ Teaching Resource

## Steps to Include GLFW in Your Project

### Step 1: Download GLFW

1. Go to the [GLFW website](https://www.glfw.org/download.html) and download the latest version.

### Step 2: Extract and Include Files

1. Extract the downloaded package.
2. You will find include files in the `include` directory and library files in the `lib` directory.

### Step 3: Add to Your Project

1. Copy the include files into your project's include directory.
2. Copy the library files (`.lib` for Windows) into your project's library directory.

   For a more in-depth guide on adding include and library files in Visual Studio, please refer to this [official guide](https://docs.microsoft.com/en-us/cpp/build/working-with-project-properties?view=msvc-160).

### Step 4: Link Libraries

In your project settings:

1. Add the include directory to your compiler's include directories.
2. Add the library directory to your linker's library directories.
3. Link against `glfw3.lib` (for Windows).

   For a detailed video tutorial on how to link libraries in Visual Studio 2019 or above, please refer to this [official Microsoft video](#) (Link TBD).

### Step 5: Use GLFW in Your Code

To use GLFW, include it like any other header:

```cpp
#include <GLFW/glfw3.h>

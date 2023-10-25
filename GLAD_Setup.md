# GLAD Setup Guide for OpenGL C++ Teaching Resource

This guide provides detailed instructions on how to set up GLAD for the OpenGL C++ teaching resource.

## Steps to Include GLAD in Your Project

### Step 1: Download GLAD

1. Go to [GLAD's website](https://glad.dav1d.de/).
2. Configure the loader to match your OpenGL version. Generally, you can leave most options at their defaults.
3. Click "Generate" to download the loader package.

### Step 2: Extract and Include Files

1. Extract the downloaded package.
2. Locate `glad.c`, `glad.h`, and `khrplatform.h`.
3. Include `glad.c` in your project. This contains the implementation for the loader.
4. Add `glad.h` and `khrplatform.h` to your project's include directory or place them directly in your source folder.

### Step 3: Link GLAD in Your Code

In your `main.cpp` or any file where you initialize OpenGL, include GLAD before any OpenGL headers:

```cpp
#include <glad/glad.h>

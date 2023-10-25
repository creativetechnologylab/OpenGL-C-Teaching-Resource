# GLM Setup Guide for OpenGL C++ Teaching Resource

This guide provides detailed instructions on how to include GLM (OpenGL Mathematics) in your project. Since GLM is a header-only library, you won't need to link against a compiled library, making the process simpler than for other dependencies.

## Steps to Include GLM in Your Project

### Step 1: Download GLM

1. Go to the [GLM GitHub repository](https://github.com/g-truc/glm) or download it directly from the [official website](https://github.com/g-truc/glm/releases).
2. Download the latest version of GLM.

### Step 2: Extract and Include Files

1. Extract the downloaded package.
2. You'll find a folder named `glm` containing all the header files.

### Step 3: Add to Your Project

1. Copy the `glm` folder into your project's include directory, or anywhere you prefer as long as the compiler can find it.
2. Alternatively, you can globally set the path to the `glm` folder in your IDE or build system so that it can be accessed by multiple projects.

### Step 4: Use GLM in Your Code

To use GLM in your code, include it like any other header:

```cpp
#include <glm/glm.hpp>

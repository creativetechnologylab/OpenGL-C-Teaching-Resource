# GLFW Setup Guide for OpenGL C++ Teaching Resource

This guide provides detailed instructions on how to set up GLFW (Graphics Library Framework) for your OpenGL project when using Visual Studio.

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

#### Creating a Library Directory

1. **Create a new folder** in your project directory to hold the library files. You could name it something like `libs`.
2. **Copy the library files** (e.g., `glfw3.lib`) into this newly created `libs` directory.

#### Updating Project Properties

1. **Right-click on your project** in the Solution Explorer and choose **Properties**.
2. Navigate to the **Linker** tab:

    - Under **General**, find the **Additional Library Directories** field and add the path to your `libs` directory where the `.lib` files are stored.
    - Under **Input**, find the **Additional Dependencies** field and add the name of the library file you want to link against (e.g., `glfw3.lib`).

#### Save and Apply Changes

1. Click **Apply** and then **OK** to save all the changes you've made in the **Properties** window.

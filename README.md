### README for OpenGL C++ Teaching Resource

#### Introduction

This teaching resource is designed to help students understand how to create an OpenGL application using C++. The example provided sets up a simple rendering pipeline to draw a colored square on the screen. It makes use of libraries like GLFW for window management, GLAD for OpenGL function loading, and GLM for mathematical calculations.

#### Prerequisites

- C++ Compiler (e.g., GCC, MSVC)
For detailed instructions on installing each library, please follow the links below:
1. **GLFW**: [Download](https://www.glfw.org/download.html) and install.
2. **GLAD**: For an in-depth guide on setting up GLAD, please refer to [GLAD_Setup.md](GLAD_Setup.md).
3. **GLM**: Clone or [download](https://github.com/g-truc/glm) and include it in your project.


**OS**: This guide assumes you are using Windows 11. For other OS, the setup might differ slightly.

#### Directory Structure

- `main.cpp`: The main C++ source file that contains all the OpenGL logic.
- `ShaderUtils.h` and `ShaderUtils.cpp`: Utilities for loading and compiling shaders.
- `vertex.glsl`: The vertex shader file.
- `fragment.glsl`: The fragment shader file.

## Step-by-Step Setup

### 1. Install Required Libraries

For detailed instructions on installing each library, please follow the links below:

1. **GLFW**: For an in-depth guide on setting up and linking GLFW, please refer to [GLFW_Setup.md](GLFW_Setup.md).
2. **GLAD**: For an in-depth guide on setting up and linking GLAD, please refer to [GLAD_Setup.md](GLAD_Setup.md).
3. **GLM**: For an in-depth guide on including GLM in your project, please refer to [GLM_Setup.md](GLM_Setup.md).

##### 2. Set Up Your Project

1. Create a new C++ project in your favorite IDE or text editor.
2. Add the `main.cpp` file into the project.
3. Add `ShaderUtils.h` and `ShaderUtils.cpp` into the project.
4. Place `vertex.glsl` and `fragment.glsl` in the project directory.

##### 3. Link Libraries

- Link GLFW, GLAD, and any other required libraries.

##### 4. Compile and Run

Compile the project and run it. You should see a window displaying a colored square.

#### Code Explanation

The main steps in the code are as follows:

1. **Initialization**: Initialize GLFW and create a window.
2. **OpenGL Setup**: Load OpenGL functions using GLAD.
3. **Shader Setup**: Load and compile vertex and fragment shaders.
4. **Data Buffers**: Create Vertex Buffer Object (VBO) and Element Buffer Object (EBO) and upload vertex and index data.
5. **Rendering Loop**: Clear screen, draw elements, swap buffers, and poll events.

For a more detailed explanation, please refer to the inline comments in the `main.cpp` file.

#### Troubleshooting

1. **Compilation Errors**: Make sure all libraries are correctly linked.
2. **Runtime Errors**: Make sure the shader files `vertex.glsl` and `fragment.glsl` are in the correct directory.

#### Concluding Remarks

This is a simple example, but it forms the basis of almost every 2D and 3D application. Feel free to expand upon it and explore more advanced OpenGL features.
---

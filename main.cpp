// Import required libraries
#include <glad/glad.h> // Glad: Helps with OpenGL setup
#include <GLFW/glfw3.h> // GLFW: Creates the window and manages user input
#include <glm/glm.hpp>  // GLM: Helps with math calculations
#include <chrono>       // Chrono: Measures time
#include <iostream>     // Iostream: Input/Output stream

// Custom shader utilities
#include "ShaderUtils.h"

// Function that makes sure the animation runs smoothly
void WaitForNextFrame() {
	// Each frame should last for 1/60th of a second
	std::chrono::duration<double, std::milli> frameDuration(1000.0f / 60.0f);
	auto frameStart = std::chrono::high_resolution_clock::now();
	auto frameEnd = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> elapsedTime;

	// Loop until enough time has passed for the next frame
	do {
		frameEnd = std::chrono::high_resolution_clock::now();
		elapsedTime = frameEnd - frameStart;
	} while (elapsedTime < frameDuration);

	// Sleep the remaining time, if needed
	if (elapsedTime < frameDuration) {
		std::this_thread::sleep_for(frameDuration - elapsedTime);
	}
}

// Main function where we setup and initiate the render loop
int main() {
	// === Initialization ===
	// Initialize GLFW, which manages windows and user input
	if (!glfwInit()) {
		return -1; // Initialization failed
	}

	// Create a window where the visuals will appear
	GLFWwindow* window;
	const int displayWidth = 1280;
	const int displayHeight = 800;
	window = glfwCreateWindow(displayWidth, displayHeight, "openGL", NULL, NULL);

	// Check if window creation was successful
	if (!window) {
		glfwTerminate(); // End GLFW
		return -1; // Window creation failed
	}

	// Tell OpenGL to use this window
	glfwMakeContextCurrent(window);

	// Use Glad to load OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return -1; // Function pointers not loaded
	}

	// **OpenGL Workflow: A Brief Overview**
	// In OpenGL, you typically follow these steps:
	// 1. Define your shapes (vertices and optionally, indices)
	// 2. Create Vertex Buffer Objects (VBO) and upload your vertex data
	// 3. Create an Element Buffer Object (EBO) if you're using indexed data
	// 4. Create a Vertex Array Object (VAO) and specify the layout
	// 5. Create shaders to control how the shapes are processed and rendered
	// 6. Draw the shapes in the render loop

	// === Shaders ===
	// **Shader Program**
	// Shaders are tiny programs that run on the GPU. They dictate how the vertices and pixels are processed.
	// 'loadShader' is a custom function that typically compiles and links vertex and fragment shaders into a shader program.
	GLuint shaderProgram = loadShader("vertex.glsl", "fragment.glsl");

	// **Vertex Array Object (VAO)**
	// Think of a VAO as a big container that holds different kinds of data (attributes) for your vertices.
	// It keeps track of all the settings needed to fetch attributes from the buffers.
	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// **Vertex Buffer Object (VBO)**
	// A VBO is essentially a memory buffer in the GPU where we store our vertex data.
	// Consider it like a raw array that you pass to the GPU for processing.
	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// **Vertices**
	// In this array, each vertex has position and color data (x, y, r, g, b, a).
	float vertices[] = {
		-0.1f, -0.1f, 1.0f, 0.0f, 0.0f, 1.0f,
		 0.1f, -0.1f, 1.0f, 0.0f, 0.0f, 1.0f,
		 0.1f,  0.1f, 1.0f, 0.0f, 0.0f, 1.0f,
		-0.1f,  0.1f, 1.0f, 0.0f, 0.0f, 1.0f
	};
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// **Element Buffer Object (EBO)**
	// An EBO is another type of buffer object that stores indices, each pointing to a vertex in the VBO.
	// Think of EBO as a 'shortcut list' that tells OpenGL how to jump around the VBO to construct shapes.
	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	// **Indices**
	unsigned int indices[] = { 0, 1, 2, 0, 2, 3 };
	// Upload index data to the buffer
	// Arguments: target buffer type, size of data, pointer to data, usage pattern
	// These are the 'shortcuts' to vertices in the VBO.
	// Instead of duplicating vertices for shapes with shared vertices, we can just reuse them.
	// For example, two triangles share two vertices, so we use indices to specify the order of vertices for each triangle.
	// Indices to draw the two triangles that make up the square
	// An index array or element buffer stores integers that point to vertices
	// in the vertex buffer. For instance, the first three indices {0, 1, 2}
	// refer to the vertices that form the first triangle.
	// This way, instead of duplicating vertex data for shapes with overlapping
	// vertices, you can reuse existing vertices, thus saving memory and improving performance.

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// This uploads the index data to the active EBO.

	// Tell OpenGL how to interpret vertex data (positions)
	// Arguments: attribute index, size, type, normalized, stride, offset
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	// Enable the vertex attribute array
	// Arguments: attribute index to enable
	glEnableVertexAttribArray(0);
	// The attribute with index 0 is enabled, which we have designated for vertex positions.

	// Tell OpenGL how to interpret color data
	// Arguments: attribute index, size, type, normalized, stride, offset
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
	// Enable the color attribute array
	// Arguments: attribute index to enable
	glEnableVertexAttribArray(1);
	// The attribute with index 1 is enabled, which we have designated for vertex colors.

// Main loop: Continuously render frames until the user closes the window
// Goal: To display dynamic, interactive graphics content on the screen
	while (!glfwWindowShouldClose(window)) {
		// Timestamp the start of the frame for frame rate control or performance monitoring
		// Goal: To synchronize events within the application and manage frame rates
		auto frameStart = std::chrono::high_resolution_clock::now();

		// Set the background color for the screen (R, G, B, Alpha)
		// Goal: To prepare for new drawings and ensure no remnants from previous frames are left
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		// Clear the screen using the color set by glClearColor
		// Goal: To start with a clean slate for the new frame
		glClear(GL_COLOR_BUFFER_BIT);

		// Issue the drawing command to render the shape (our square in this case)
		// Arguments: 
		// 1) The type of primitive to draw (GL_TRIANGLES)
		// 2) The count of elements (6 vertices make up two triangles)
		// 3) Type of values in indices (GL_UNSIGNED_INT)
		// 4) Offset in the EBO or an index array (starting at 0)
		// Goal: Core of the rendering process; actual drawing happens here
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		// Swap the front and back buffers, making the drawn frame visible
		// Goal: To display the results of the draw calls
		glfwSwapBuffers(window);

		// Poll and handle window events like keyboard and mouse inputs
		// Goal: To make the application interactive and responsive
		glfwPollEvents();

		// Custom function for frame rate management or between-frame operations
		// Goal: To keep the application running smoothly
		WaitForNextFrame();
	}




	// Clean up resources
	glfwTerminate(); // End GLFW
	glDeleteProgram(shaderProgram); // Delete shader program

	return 0; // Program successfully executed
}

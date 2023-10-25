#pragma once
#include <string>
#include <glad/glad.h>  // Include this before other OpenGL-related includes

GLuint loadShader(const std::string& vertexPath, const std::string& fragmentPath);

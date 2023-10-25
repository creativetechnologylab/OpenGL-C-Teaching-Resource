#include "ShaderUtils.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Helper function: Read the file contents and return as a string
static std::string readFile(const std::string& filepath) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filepath << std::endl;
        return "";
    }

    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

// Function to check shader compilation status and report errors
void checkCompileErrors(GLuint shader, const std::string& type) {
    GLint success;
    GLchar infoLog[1024];
    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cerr << "Shader Compilation Error of type: " << type << "\n" << infoLog << std::endl;
        }
    }
    else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cerr << "Program Linking Error of type: " << type << "\n" << infoLog << std::endl;
        }
    }
}

GLuint loadShader(const std::string& vertexPath, const std::string& fragmentPath) {
    // 1. Retrieve the source code from the provided file paths
    std::string vertexCode = readFile(vertexPath);
    std::string fragmentCode = readFile(fragmentPath);

    if (vertexCode.empty() || fragmentCode.empty()) {
        return 0; // Early exit if shader source code is not available
    }

    const GLchar* vShaderCode = static_cast<const GLchar*>(vertexCode.c_str());
    const GLchar* fShaderCode = static_cast<const GLchar*>(fragmentCode.c_str());

    // 2. Compile the shaders
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, nullptr);
    glCompileShader(vertexShader);
    checkCompileErrors(vertexShader, "VERTEX");

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, nullptr);
    glCompileShader(fragmentShader);
    checkCompileErrors(fragmentShader, "FRAGMENT");

    // 3. Link the compiled shaders into a program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    checkCompileErrors(shaderProgram, "PROGRAM");

    // Cleanup: shaders are linked into our program; no longer necessary
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

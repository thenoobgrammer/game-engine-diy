#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>
#include <glm/glm.hpp>

std::string get_file_coontents(const char *filename);

class Shader
{
public:
    GLuint ID;
    Shader(const char *vertexFile, const char *fragmentFile);

    void Activate();
    void Delete();
    void SetMat4(const std::string &name, const glm::mat4 &mat);
};

#endif

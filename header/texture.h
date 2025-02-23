#ifndef TEXTURE_CLASS_H
#define TEXTURE_CLASS_H

#include <glad/glad.h>

class Texture
{
public:
    GLuint texture;

    Texture();
    ~Texture();

    GLuint Get();
    void BindTo(unsigned int textureUnit);
    void Load(const char *filename, GLint internalformat);
};
#endif
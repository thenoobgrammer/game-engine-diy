#include <glad/glad.h>
#include "texture.h"
#include <stb/stb_image.h>
#include <iostream>

Texture::Texture()
{
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    std::cout << "Texture Constructor Called. ID: " << texture << std::endl;
}
Texture::~Texture()
{
    glDeleteTextures(1, &texture);
    std::cout << "Texture Deleted. ID: " << texture << std::endl;
}
void Texture::Load(const char *filename, GLint internalformat)
{
    int widthImg, heightImg, numColCh;
    unsigned char *bytes = stbi_load(filename, &widthImg, &heightImg, &numColCh, 0);
    if (bytes)
    {
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, internalformat, widthImg, heightImg, 0, internalformat, GL_UNSIGNED_BYTE, bytes);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(bytes);
}

void Texture::BindTo(unsigned int textureUnit)
{
    glActiveTexture(GL_TEXTURE0 + textureUnit);
    glBindTexture(GL_TEXTURE_2D, texture);
}

GLuint Texture::Get()
{
    return texture;
}
#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <glm.hpp>

#include <string>

class Texture
{
	GLuint id;
	glm::vec2 size;

public:
	Texture(std::string path);
	glm::vec2 GetSize();
	GLuint GetId();

};

#endif // !TEXTURE_H

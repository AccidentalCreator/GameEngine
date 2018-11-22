#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <glm.hpp>
#include <memory>
#include <string>

#include "Component.h"

class Texture : public Component
{
public:
	void Start(std::string _texPath);
	glm::vec2 GetSize();
	GLuint GetId();

private:
	GLuint id;
	glm::vec2 size;

};

#endif // !TEXTURE_H

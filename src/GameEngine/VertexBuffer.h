#pragma once

#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <GL\glew.h>
#include <glm.hpp>
#include <vector>

class VertextBuffer
{
public:
	VertextBuffer();
	~VertextBuffer();

	void Add(glm::vec3 _value);
	void Add(glm::vec4 _value);
	int GetComponent();
	int GetDataSize();
	GLuint GetId();

private:
	GLuint id;
	int components;
	std::vector<GLfloat> data;
	bool dirty;
};

#endif // !VERTEXBUFFER_H

#pragma once

#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <GL\glew.h>
#include <glm.hpp>
#include <vector>

class VertexBuffer
{
public:
	VertexBuffer();
	~VertexBuffer();

	void Add(glm::vec3 _value);
	void Add(glm::vec4 _value);
	int GetComponents();
	int GetDataSize();
	GLuint GetID();

private:
	GLuint id;
	int components;
	std::vector<GLfloat> data;
	bool dirty;
};

#endif // !VERTEXBUFFER_H

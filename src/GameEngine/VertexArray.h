#pragma once

#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <string>
#include <GL\glew.h>
#include <vector>

class VertexBuffer;

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void SetBuffer(std::string _attribute, VertexBuffer *_buffer); // Should use a smart pointer???
	int GetVertexCount();
	GLuint GetId();

private:
	GLuint id;
	std::vector<VertexBuffer*> buffers;
	bool dirty;
};

#endif // !VERTEXARRAY_H

#pragma once

#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <string>
#include <GL\glew.h>
#include <memory>
#include <vector>

class VertexBuffer;

class VertexArray
{
public:
	VertexArray();
	~VertexArray();

	void SetBuffer(std::string _attribute, std::weak_ptr<VertexBuffer> _buffer);
	int GetVertexCount();
	GLuint GetID();

private:
	GLuint id;
	std::vector<std::shared_ptr<VertexBuffer>> buffers;
	bool dirty;
};

#endif // !VERTEXARRAY_H

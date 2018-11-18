#pragma once

#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <string>
#include <GL\glew.h>
#include <memory>
#include <vector>
#include <string>
#include <glm.hpp>

#include "Face.h"

class VertexBuffer;
class StaticModelCollider;

class VertexArray
{
	friend class StaticMeshCollider;
public:
	VertexArray();
	VertexArray(std::string _modelPath);
	~VertexArray();

	void SetBuffer(std::string _attribute, std::weak_ptr<VertexBuffer> _buffer);
	glm::vec3 FindRenderSize();

	int GetVertexCount();
	GLuint GetID();

private:

	GLuint id;
	std::vector<std::shared_ptr<VertexBuffer>> buffers;
	bool dirty;

	void removeWhitespace(std::string& _string, std::vector<std::string>& _output);
	void splitString(std::string& _input, char _splitter, std::vector<std::string>& _output);

	std::vector<Face> faces;
};

#endif // !VERTEXARRAY_H

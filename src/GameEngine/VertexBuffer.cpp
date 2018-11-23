#include "VertexBuffer.h"

namespace GameEngine
{

	VertexBuffer::VertexBuffer() : components(0), dirty(false)
	{
		// Creates new VBO
		glGenBuffers(1, &id);

		if (!id)
		{
			throw ("Failed to create vertex buffer");
		}

	}

	VertexBuffer::~VertexBuffer()
	{

	}

	void VertexBuffer::Add(glm::vec2 _value)
	{
		if (!components)
		{
			components = 2;
		}

		if (components != 2)
		{
			throw ("Failed to add vertex position to buffer");
		}

		data.push_back(_value.x);
		data.push_back(_value.y);
		dirty = true;
	}

	void VertexBuffer::Add(glm::vec3 _value)
	{
		if (!components)
		{
			components = 3;
		}

		if (components != 3)
		{
			throw ("Failed to add vertex position to buffer");
		}

		data.push_back(_value.x);
		data.push_back(_value.y);
		data.push_back(_value.z);
		dirty = true;
	}

	void VertexBuffer::Add(glm::vec4 _value)
	{
		if (!components)
		{
			components = 4;
		}

		if (components != 4)
		{
			throw ("Failed to add vertex position to buffer");
		}

		data.push_back(_value.x);
		data.push_back(_value.y);
		data.push_back(_value.z);
		data.push_back(_value.w);
		dirty = true;
	}

	int VertexBuffer::GetDataSize()
	{
		return data.size();
	}

	int VertexBuffer::GetComponents()
	{
		if (!components)
		{
			throw ("Failed to get vertex buffer component");
		}
		return components;
	}

	GLuint VertexBuffer::GetID()
	{
		if (dirty)
		{
			// Bind buffer to GPU
			glBindBuffer(GL_ARRAY_BUFFER, id);
			// Sends a copy of data from memory to VBO
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * data.size(), &data.at(0), GL_STATIC_DRAW);
			// Reset the state
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			dirty = false;
		}

		return id;
	}

}


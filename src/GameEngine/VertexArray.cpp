#include "VertexArray.h"
#include "VertexBuffer.h"

VertexArray::VertexArray() : dirty(false)
{
	// Create new VAO
	glGenVertexArrays(1, &id);

	if (!id)
	{
		throw std::exception();
	}

	buffers.resize(10);
}

void VertexArray::SetBuffer(std::string _attribute, std::weak_ptr<VertexBuffer> _buffer)
{
	if (_attribute == "in_Position")
	{
		buffers.at(0) = _buffer.lock();
	}
	else if (_attribute == "in_Color")
	{
		buffers.at(1) = _buffer.lock();
	}
	else
	{
		throw std::exception();
	}
	dirty = true;
}

int VertexArray::GetVertexCount()
{
	if (!buffers.at(0))
	{
		throw std::exception();
	}
	return buffers.at(0)->GetDataSize() / buffers.at(0)->GetComponents();
}

GLuint VertexArray::GetID()
{
	if (dirty)
	{
		// Bind to GPU
		glBindVertexArray(id);

		for (size_t i = 0; i < buffers.size(); i++)
		{
			if (buffers.at(i))
			{
				glBindBuffer(GL_ARRAY_BUFFER, buffers.at(i)->GetID());

				glVertexAttribPointer(i, buffers.at(i)->GetComponents(), GL_FLOAT, GL_FALSE,
					buffers.at(i)->GetComponents() * sizeof(GLfloat), (void *)0);

				glEnableVertexAttribArray(i);
			}
			else
			{
				glDisableVertexAttribArray(i);
			}
		}
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
		dirty = false;
	}
	return id;
}

VertexArray::~VertexArray()
{

}
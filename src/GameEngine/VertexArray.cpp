#include "VertexArray.h"
#include "VertexBuffer.h"

VertexArray::VertexArray()
{
	id = 0;

	// Create new VAO
	glGenVertexArrays(1, &id);

	if (!id)
	{
		throw std::exception();
	}

	// Bind to GPU
	glBindVertexArray(id);
	glBindBuffer(GL_ARRAY_BUFFER, GetVertexCount());

	// (shader, number of vertex in row, vertex data type, normalized, gap in points, data does not start at 0)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void *)0); // What does this do???

	glEnableVertexAttribArray(0);

	// Reset state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void VertexArray::SetBuffer(std::string _attribute, VertexBuffer *buffer)
{

}

int VertexArray::GetVertexCount()
{

}

VertexArray::~VertexArray()
{

}
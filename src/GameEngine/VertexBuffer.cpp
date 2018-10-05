#include "VertexBuffer.h"

VertextBuffer::VertextBuffer()
{
	id = 0;

	// Creates new VBO
	glGenBuffers(1, &id);

	if (!id)
	{
		throw std::exception();
	}

	// Bind buffer to GPU
	glBindBuffer(GL_ARRAY_BUFFER, id);

	// Sends a copy of data from memory to VBO
	glBufferData(GL_ARRAY_BUFFER, sizeof(data), &data, GL_STATIC_DRAW);

	// Reset the state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
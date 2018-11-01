#include "VertexArray.h"
#include "VertexBuffer.h"

#include <fstream>
#include <iostream>

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

VertexArray::VertexArray(std::string _modelPath) : dirty(false)
{
	glGenVertexArrays(1, &id);

	if (!id)
	{
		throw std::exception();
	}

	buffers.resize(10);
	std::ifstream file(_modelPath.c_str());

	if (!file.is_open())
	{
		throw std::exception();
	}

	std::string line;
	std::vector<std::string> splitLine;
	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;
	std::vector<glm::vec3> normals;

	std::shared_ptr<VertexBuffer> positionBuffer = NULL;
	std::shared_ptr<VertexBuffer> texCoordBuffer = NULL;
	std::shared_ptr<VertexBuffer> normalBuffer = NULL;

	while (!file.eof())
	{
		std::getline(file, line);
		if (line.length() < 1) continue;
		removeWhitespace(line, splitLine);
		if (splitLine.size() < 1) continue;

		if (splitLine.at(0) == "v")
		{
			if (!positionBuffer) positionBuffer = std::make_shared<VertexBuffer>();
			positions.push_back(glm::vec3(
				atof(splitLine.at(1).c_str()),
				atof(splitLine.at(2).c_str()),
				atof(splitLine.at(3).c_str())));
		}
		else if (splitLine.at(0) == "vt")
		{
			if (!texCoordBuffer) texCoordBuffer = std::make_shared<VertexBuffer>();

			texCoords.push_back(glm::vec2(
				atof(splitLine.at(1).c_str()),
				1.0f - atof(splitLine.at(2).c_str())));
		}
		else if (splitLine.at(0) == "vn")
		{
			if (!normalBuffer) normalBuffer = std::make_shared<VertexBuffer>();

			normals.push_back(glm::vec3(
				atof(splitLine.at(1).c_str()),
				atof(splitLine.at(2).c_str()),
				atof(splitLine.at(3).c_str())));
		}
		else if (splitLine.at(0) == "f")
		{
			std::vector<std::string> subsplit;
			splitString(splitLine.at(1), '/', subsplit);

			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
			splitString(splitLine.at(2), '/', subsplit);
			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
			splitString(splitLine.at(3), '/', subsplit);
			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));

			if (splitLine.size() < 5) continue;
			splitString(splitLine.at(3), '/', subsplit);

			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
			splitString(splitLine.at(4), '/', subsplit);
			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
			splitString(splitLine.at(1), '/', subsplit);
			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
		}
	}

	SetBuffer("in_Position", positionBuffer);
	if (texCoordBuffer) SetBuffer("in_TexCoord", texCoordBuffer);
	if (normalBuffer) SetBuffer("in_Normal", normalBuffer);
}

void VertexArray::splitString(std::string& _input, char _splitter, std::vector<std::string>& _output)
{
	std::string curr;

	_output.clear();

	for (size_t i = 0; i < _input.length(); i++)
	{
		if (_input.at(i) == _splitter)
		{
			_output.push_back(curr);
			curr = "";
		}
		else
		{
			curr += _input.at(i);
		}
	}

	if (curr.length() > 0)
	{
		_output.push_back(curr);
	}
}

void VertexArray::removeWhitespace(std::string& _input, std::vector<std::string>& _output)
{
	std::string curr;

	_output.clear();

	for (size_t i = 0; i < _input.length(); i++)
	{
		if (_input.at(i) == ' ' ||
			_input.at(i) == '\r' ||
			_input.at(i) == '\n' ||
			_input.at(i) == '\t')
		{
			if (curr.length() > 0)
			{
				_output.push_back(curr);
				curr = "";
			}
		}
		else
		{
			curr += _input.at(i);
		}
	}

	if (curr.length() > 0)
	{
		_output.push_back(curr);
	}
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
	else if (_attribute == "in_TexCoord")
	{
		buffers.at(2) = _buffer.lock();
	}
	else if (_attribute == "in_Normal")
	{
		buffers.at(3) = _buffer.lock();
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
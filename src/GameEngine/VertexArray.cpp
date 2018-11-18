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
			Face face;

			std::vector<std::string> subsplit;

			// Face V1
			splitString(splitLine.at(1), '/', subsplit);
			
			face.a.position = positions.at(atoi(subsplit.at(0).c_str()) - 1);
			face.a.texCoord = texCoords.at(atoi(subsplit.at(1).c_str()) - 1);

			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
			
			// Face V2
			splitString(splitLine.at(2), '/', subsplit);

			face.b.position = positions.at(atoi(subsplit.at(0).c_str()) - 1);
			face.b.texCoord = texCoords.at(atoi(subsplit.at(1).c_str()) - 1);

			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
			
			// Face V3
			splitString(splitLine.at(3), '/', subsplit);

			face.c.position = positions.at(atoi(subsplit.at(0).c_str()) - 1);
			face.c.texCoord = texCoords.at(atoi(subsplit.at(1).c_str()) - 1);

			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));

			faces.push_back(face); // Add face to vector

			if (splitLine.size() < 5) continue;
			
			face = Face(); // New face

			// Face V1
			splitString(splitLine.at(3), '/', subsplit);

			face.a.position = positions.at(atoi(subsplit.at(0).c_str()) - 1);
			face.a.texCoord = texCoords.at(atoi(subsplit.at(1).c_str()) - 1);

			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
			
			// Face V2
			splitString(splitLine.at(4), '/', subsplit);

			face.b.position = positions.at(atoi(subsplit.at(0).c_str()) - 1);
			face.b.texCoord = texCoords.at(atoi(subsplit.at(1).c_str()) - 1);

			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
			
			// Face V3
			splitString(splitLine.at(1), '/', subsplit);

			face.c.position = positions.at(atoi(subsplit.at(0).c_str()) - 1);
			face.c.texCoord = texCoords.at(atoi(subsplit.at(1).c_str()) - 1);

			positionBuffer->Add(positions.at(atoi(subsplit.at(0).c_str()) - 1));
			if (texCoordBuffer) texCoordBuffer->Add(texCoords.at(atoi(subsplit.at(1).c_str()) - 1));
			if (normalBuffer) normalBuffer->Add(normals.at(atoi(subsplit.at(2).c_str()) - 1));
		
			faces.push_back(face); // Add face to vector
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

void VertexArray::FindModelSize()
{
	std::vector<glm::vec3> positions;
	for (size_t i = 0; i < faces.size(); i++)
	{
		positions.push_back(faces.at(i).a.position);
		positions.push_back(faces.at(i).b.position);
		positions.push_back(faces.at(i).c.position);
	}

	glm::vec3 maxPosition = positions.at(0);
	glm::vec3 minPosition = positions.at(0);

	for (size_t i = 1; i < positions.size(); i++)
	{
		// Check max position
		if (positions.at(i).x > maxPosition.x)
		{
			maxPosition.x = positions.at(i).x;
		}
		if (positions.at(i).y > maxPosition.y)
		{
			maxPosition.y = positions.at(i).y;
		}
		if (positions.at(i).z > maxPosition.z)
		{
			maxPosition.z = positions.at(i).z;
		}

		// Check min position
		if (positions.at(i).x < minPosition.x)
		{
			minPosition.x = positions.at(i).x;
		}
		if (positions.at(i).y < minPosition.y)
		{
			minPosition.y = positions.at(i).y;
		}
		if (positions.at(i).z < minPosition.z)
		{
			minPosition.z = positions.at(i).z;
		}
	}

	glm::vec3 RenderSize;
	RenderSize.x = maxPosition.x - minPosition.x;
	RenderSize.y = maxPosition.y - minPosition.y;
	RenderSize.z = maxPosition.z - minPosition.z;
}
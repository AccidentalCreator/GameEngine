#include "ShaderProgram.h"
#include "VertexArray.h"

ShaderProgram::ShaderProgram(std::string _vert, std::string _frag)
{
	id = glCreateProgram();
	// Need to get shaders from file??
	//glAttachShader(id,  _vert);
	//glAttachShader(id, _frag);

	glBindAttribLocation(id, 0, "in_position");

	glLinkProgram(id);
	// Whats sucess??
	//glGetProgramiv(id, GL_LINK_STATUS, &success);

	//if (!success)
	{
		throw std::exception();
	}

	//glDetachShader(id, vertexShaderId);
	//glDeleteShader(vertexShaderId);
	//glDetachShader(id, fragmentShaderId);
	//glDeleteShader(fragmentShaderId);}


ShaderProgram::~ShaderProgram()
{

}

void ShaderProgram::Draw(VertexArray* _vertexArray)
{

}

void ShaderProgram::SetUniform(glm::vec4 _uniform)
{

}

void ShaderProgram::SetUniform(float _uniform)
{

}
#include "ShaderProgram.h"
#include "VertexArray.h"

ShaderProgram::ShaderProgram(std::string _vert, std::string _frag)
{
	std::ifstream file(_vert.c_str());
	std::string vertSrc;

	if (!file.is_open())
	{
		throw std::exception();
	}

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		vertSrc += line + "\n";
	}

	file.close();
	file.open(_frag.c_str());
	std::string fragSrc;

	if (!file.is_open())
	{
		throw std::exception();
	}

	while (!file.eof())
	{
		std::string line;
		std::getline(file, line);
		fragSrc += line + "\n";
	}

	const GLchar *vs = vertSrc.c_str();
	GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShaderId, 1, &vs, NULL);
	glCompileShader(vertexShaderId);
	GLint success = 0;
	glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		throw std::exception();
	}

	const GLchar *fs = fragSrc.c_str();
	GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShaderId, 1, &fs, NULL);
	glCompileShader(fragmentShaderId);
	glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		throw std::exception();
	}

	id = glCreateProgram();
	glAttachShader(id, vertexShaderId);
	glAttachShader(id, fragmentShaderId);
	glBindAttribLocation(id, 0, "in_Position");
	glBindAttribLocation(id, 1, "in_Color");

	if (glGetError() != GL_NO_ERROR)
	{
		throw std::exception();
	}

	glLinkProgram(id);
	glGetProgramiv(id, GL_LINK_STATUS, &success);

	if (!success)
	{
		throw std::exception();
	}

	glDetachShader(id, vertexShaderId);
	glDeleteShader(vertexShaderId);
	glDetachShader(id, fragmentShaderId);
	glDeleteShader(fragmentShaderId);
}


ShaderProgram::~ShaderProgram()
{

}

void ShaderProgram::Draw(VertexArray& _vertexArray)
{
	glUseProgram(id);
	glBindVertexArray(_vertexArray.GetID());

	glDrawArrays(GL_TRIANGLES, 0, _vertexArray.GetVertexCount());

	glBindVertexArray(0);
	glUseProgram(0);
}

void ShaderProgram::SetUniform(std::string _uniform, glm::vec4 _value)
{
	GLint uniformID = glGetUniformLocation(id, _uniform.c_str());

	if (uniformID == -1)
	{
		throw std::exception();
	}

	glUseProgram(id);
	glUniform4f(uniformID, _value.x, _value.y, _value.z, _value.w);
	glUseProgram(0);
}

void ShaderProgram::SetUniform(std::string _uniform, float _value)
{
	GLint uniformID = glGetUniformLocation(id, _uniform.c_str());

	if (uniformID == -1)
	{
		throw std::exception();
	}

	glUseProgram(id);
	glUniform1f(uniformID, _value);
	glUseProgram(0);
}

void ShaderProgram::SetUniform(std::string _uniform, glm::mat4 _value)
{
	GLint uniformID = glGetUniformLocation(id, _uniform.c_str());

	if (uniformID == -1)
	{
		throw std::exception();
	}
	
	glUseProgram(id);
	glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(_value));
	glUseProgram(0);
}
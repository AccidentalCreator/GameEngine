#pragma once

#ifndef SHADERPROGRAM
#define SHADERPROGRAM

#include <string>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <GL\glew.h>
#include <fstream>

class VertexArray;


class ShaderProgram
{
public:
	ShaderProgram(std::string _vert, std::string _frag);
	~ShaderProgram();

	void Draw(VertexArray& _vertexArray);
	void SetUniform(std::string _uniform, glm::vec4 _value);
	void SetUniform(std::string _uniform, float _value);
	void SetUniform(std::string _uniform, glm::mat4 _value);

	GLuint GetId() { return id; };

private:

	GLuint id;
};

#endif // !SHADERPROGRAM

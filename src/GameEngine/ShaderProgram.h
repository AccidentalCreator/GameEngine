#pragma once

#ifndef SHADERPROGRAM
#define SHADERPROGRAM

#include <string>
#include <glm.hpp>
#include <fstream>

class VertexArray;


class ShaderProgram
{
public:
	ShaderProgram(std::string _vert, std::string _frag);
	~ShaderProgram();
	
	void Draw(VertexArray* _vertexArray);
	void SetUniform(glm::vec4 _uniform);
	void SetUniform(float _uniform);

	GLuint GetId();

private:

	GLuint id;
};

#endif // !SHADERPROGRAM

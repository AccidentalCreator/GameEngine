#pragma once
#ifndef SHADERPROGRAM
#define SHADERPROGRAM

#include <string>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
#include <GL\glew.h>
#include <fstream>
#include <vector>
#include <memory>

namespace GameEngine
{

	class VertexArray;
	class Texture;

	struct Sampler
	{
		GLint id;
		std::shared_ptr<Texture> texture;
	};

	/**
	* Sets up and handles the shaders to be used
	*/
	class ShaderProgram
	{
	public:
		/// Constructor opens and find the relevant shader information
		ShaderProgram(std::string _vert, std::string _frag);
		/// Deconstructor
		~ShaderProgram();

		/// Binds the textures 
		void Draw(VertexArray& _vertexArray);
		/// Sets a vec4 uniform in the shader
		void SetUniform(std::string _uniform, glm::vec4 _value);
		/// Sets a float variable in the shader
		void SetUniform(std::string _uniform, float _value);
		/// Sets a mat4 uniform in the shader
		void SetUniform(std::string _uniform, glm::mat4 _value);
		/// Sets a texture in the shader
		void SetUniform(std::string _uniform, std::shared_ptr<Texture> _texture);

		/// Returns the buffer id
		GLuint GetId() { return id; };

	private:

		GLuint id;
		std::vector<Sampler> samplers;
	};

}


#endif // !SHADERPROGRAM

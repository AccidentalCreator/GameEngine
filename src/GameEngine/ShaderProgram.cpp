#include "ShaderProgram.h"
#include "VertexArray.h"
#include "Texture.h"

namespace GameEngine
{

	ShaderProgram::ShaderProgram(std::string _vert, std::string _frag)
	{
		std::ifstream file(_vert.c_str());
		std::string vertSrc;

		if (!file.is_open())
		{
			throw ("Could not open file");
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
			throw ("Could not open file");
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
			throw ("Vertex Shader failed to load");
		}

		const GLchar *fs = fragSrc.c_str();
		GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShaderId, 1, &fs, NULL);
		glCompileShader(fragmentShaderId);
		glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			throw ("Frag Shader failed to load");
		}

		id = glCreateProgram();
		glAttachShader(id, vertexShaderId);
		glAttachShader(id, fragmentShaderId);
		glBindAttribLocation(id, 0, "in_Position");
		glBindAttribLocation(id, 1, "in_Color");
		glBindAttribLocation(id, 2, "in_TexCoord");
		glBindAttribLocation(id, 3, "in_Normal");

		if (glGetError() != GL_NO_ERROR)
		{
			throw ("Error passing data to shader");
		}

		glLinkProgram(id);
		glGetProgramiv(id, GL_LINK_STATUS, &success);

		if (!success)
		{
			throw ("Shader failed to link");
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

		for (size_t i = 0; i < samplers.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);

			if (samplers.at(i).texture)
			{
				glBindTexture(GL_TEXTURE_2D, samplers.at(i).texture->GetId());
			}
			else
			{
				glBindTexture(GL_TEXTURE_2D, 0);
			}
		}

		glDrawArrays(GL_TRIANGLES, 0, _vertexArray.GetVertexCount());

		for (size_t i = 0; i < samplers.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);
			glBindTexture(GL_TEXTURE_2D, 0);
		}

		glBindVertexArray(0);
		glUseProgram(0);
	}

	void ShaderProgram::SetUniform(std::string _uniform, glm::vec4 _value)
	{
		GLint uniformID = glGetUniformLocation(id, _uniform.c_str());

		if (uniformID == -1)
		{
			throw ("Couldn't locate uniform location");
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
			throw ("Couldn't locate uniform location");
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
			throw ("Couldn't locate uniform location");
		}
	
		glUseProgram(id);
		glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(_value));
		glUseProgram(0);
	}

	void ShaderProgram::SetUniform(std::string uniform, std::shared_ptr<Texture> _texture)
	{
		GLint uniformId = glGetUniformLocation(id, uniform.c_str());

		if (uniformId == -1)
		{
			throw ("Couldn't locate uniform location");
		}

		for (size_t i = 0; i < samplers.size(); i++)
		{
			if (samplers.at(i).id == uniformId)
			{
				samplers.at(i).texture = _texture;

				glUseProgram(id);
				glUniform1i(uniformId, i);
				glUseProgram(0);
				return;
			}
		}

		Sampler s;
		s.id = uniformId;
		s.texture = _texture;
		samplers.push_back(s);

		glUseProgram(id);
		glUniform1i(uniformId, samplers.size() - 1);
		glUseProgram(0);
	}

}

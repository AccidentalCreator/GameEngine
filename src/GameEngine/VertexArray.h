#pragma once
#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <string>
#include <GL\glew.h>
#include <memory>
#include <vector>
#include <string>
#include <glm.hpp>

#include "Face.h"

namespace GameEngine
{

	class VertexBuffer;
	class StaticModelCollider;
	/**
	*	Sets up the vertex array object 
	*/
	class VertexArray
	{
		friend class StaticMeshCollider;
	public:
		/// Constructor
		VertexArray();
		/// Sets up a VAO with the given model path
		VertexArray(std::string _modelPath);
		/// Destructor
		~VertexArray();
		/// Sets the buffer attributes
		void SetBuffer(std::string _attribute, std::weak_ptr<VertexBuffer> _buffer);
		/// Returns the size of the model
		glm::vec3 FindRenderSize();

		/// Return the number of vertex in the model
		int GetVertexCount();
		/// Returns the buffer id
		GLuint GetID();

	private:

		GLuint id;
		std::vector<std::shared_ptr<VertexBuffer>> buffers;
		bool dirty;

		/// When reading from a file removes the whitespace
		void RemoveWhitespace(std::string& _string, std::vector<std::string>& _output);
		/// Splits the string data up into relevant parts
		void SplitString(std::string& _input, char _splitter, std::vector<std::string>& _output);

		std::vector<Face> faces;
	};

}


#endif // !VERTEXARRAY_H

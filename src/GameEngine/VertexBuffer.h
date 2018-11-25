#pragma once

#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <GL\glew.h>
#include <glm.hpp>
#include <vector>

namespace GameEngine
{
	/**
	* Sets up and handlers the Vertex Buffer Object
	*/
	class VertexBuffer
	{
	public:
		/// Constructor
		VertexBuffer();
		/// Deconstructor
		~VertexBuffer();
		/// Adds a vec2 value into the buffer
		void Add(glm::vec2 _value);
		/// Adds a vec3 value into the buffer
		void Add(glm::vec3 _value);
		/// Adds a vec4 value into the buffer
		void Add(glm::vec4 _value);
		/// Returns the number of components in the buffer
		int GetComponents();
		/// Gets the size of the data in the buffer
		int GetDataSize();
		/// Returns the buffer id
		GLuint GetID();

	private:
		GLuint id;
		int components;
		std::vector<GLfloat> data;
		bool dirty;
	};

}


#endif // !VERTEXBUFFER_H

#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <glm.hpp>
#include <memory>
#include <string>

#include "Component.h"

namespace GameEngine
{
	/**
	* Adds a texture to the entities mesh
	*/
	class Texture : public Component
	{
	public:
		/// Loads in the texture from the given texture path
		void Start(std::string _texPath);

		/// Constructor
		Texture();
		/// Destructor 
		~Texture();

		/// Gets the size of the texture
		glm::vec2 GetSize();
		/// Returns the texture buffers id
		GLuint GetId();

	private:
		GLuint id;
		glm::vec2 size;

	};

}


#endif // !TEXTURE_H

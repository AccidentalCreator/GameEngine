#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <glm.hpp>
#include <GL/glew.h>
#include <SDL2\SDL.h>
#include <exception>

namespace GameEngine
{
	/**
	* Handles all SDL screen set up and updates
	*/
	class Screen
	{
	public:
		/// Constructor
		Screen();
		/// Destructor
		~Screen();

		/// Initialisation
		void Init();
		/// Clears the screen
		void Clear();
		/// Updates the screen
		void Update();
		/// Swap the buffers
		void End();

		/// Returns the size of the screen
		glm::vec2 GetSize() { return size; };

		/// Returns the projction matrix
		glm::mat4 GetProjectionMatrix() { return projection; }
	
	private:
		glm::vec2 size;

		SDL_Window *window;

		glm::mat4 projection;
	};

}


#endif // !SCREEN_H

#pragma once

#ifndef SCREEN_H
#define SCREEN_H

#include <glm.hpp>
#include <GL/glew.h>
#include <SDL2\SDL.h>
#include <exception>

namespace GameEngine
{

	class Screen
	{
	public:
		Screen();
		~Screen();

		void Init();
		void Clear();
		void Update();
		void End();

		glm::vec2 GetSize() { return size; };

		glm::mat4 GetProjectionMatrix() { return projection; }
	
	private:
		glm::vec2 size;

		SDL_Window *window;

		glm::mat4 projection;
	};

}


#endif // !SCREEN_H

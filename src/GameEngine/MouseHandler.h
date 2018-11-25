#pragma once
#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include <vector>
#include <SDL2\SDL.h>
#include <glm.hpp>

namespace GameEngine
{
	/**
	* Handles mouse movement and input
	*/
	class MouseHandler
	{
	public:
		/// Checks if a mouse button is being clicked
		bool GetMouseButtonDown(int _button);
		/// Sets a mouse butotn to clicked
		void SetMouseButtonPressed(SDL_MouseButtonEvent _event);
		/// Sets a mouse button to released
		void SetMouseButtonReleased(SDL_MouseButtonEvent _event);
		/// Sets the mouse position
		void SetMousePosition(int _x, int _y);

		/// Retrieves the mouse position
		glm::vec2 GetMousePosition() { return mousePosition; }


	private:

		glm::vec2 mousePosition;

		std::vector<int> mouseButtonDown;
	};

}


#endif // !MOUSEHANDLER_H

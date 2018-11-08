#pragma once
#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include <vector>
#include <SDL2\SDL.h>
#include <glm.hpp>

class MouseHandler
{
public:

	bool GetMouseButtonDown(int _button);
	void SetMouseButtonPressed(SDL_MouseButtonEvent _event);
	void SetMouseButtonReleased(SDL_MouseButtonEvent _event);
	void SetMousePosition(int _x, int _y);

	glm::vec2 GetMousePosition() { return mousePosition; }


private:

	glm::vec2 mousePosition;

	std::vector<int> mouseButtonDown;
};

#endif // !MOUSEHANDLER_H

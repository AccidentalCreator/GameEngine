#include "MouseHandler.h"

bool MouseHandler::GetMouseButtonDown(int _button)
{
	for (int i = 0; i < mouseButtonDown.size(); i++)
	{
		if (mouseButtonDown.at(i) == _button)
		{
			return true;
		}
	}
	return false;
}

void MouseHandler::SetMouseButtonPressed(SDL_MouseButtonEvent _event)
{
	if (_event.button == SDL_BUTTON_LEFT)
	{
		mouseButtonDown.push_back(0);
	}
	else if (_event.button == SDL_BUTTON_RIGHT)
	{
		mouseButtonDown.push_back(1);
	}
	else if (_event.button == SDL_BUTTON_MIDDLE)
	{
		mouseButtonDown.push_back(2);
	}
}


void MouseHandler::SetMouseButtonReleased(SDL_MouseButtonEvent _event)
{
	// Remove key from down vector
	for (size_t i = 0; i < mouseButtonDown.size(); i++)
	{
		if (_event.button == SDL_BUTTON_LEFT)
		{
			mouseButtonDown.erase(mouseButtonDown.begin() + i);
			i++;
		}
		else if (_event.button == SDL_BUTTON_RIGHT)
		{
			mouseButtonDown.erase(mouseButtonDown.begin() + i);
			i++;
		}
		else if (_event.button == SDL_BUTTON_MIDDLE)
		{
			mouseButtonDown.erase(mouseButtonDown.begin() + i);
			i++;
		}
	}
}

void MouseHandler::SetMousePosition(int _x, int _y)
{
	mousePosition.x = _x;
	mousePosition.y = _y;
}

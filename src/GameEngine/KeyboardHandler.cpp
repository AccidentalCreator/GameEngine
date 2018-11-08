#include "KeyboardHandler.h"

bool KeyboardHandler::GetKey(int _keyCode)
{
	// Iterates through all the keys that are not pressed
	for (int i = 0; i < keys.size(); i++)
	{
		// If key is vector return true
		if (keys.at(i) == _keyCode)
		{
			return true;
		}
	}
	return false;
}

bool KeyboardHandler::GetKeyDown(int _keyCode)
{
	// Iterates through all the keys that are not pressed
	for (int i = 0; i < downKeys.size(); i++)
	{
		// If key is vector return true
		if (downKeys.at(i) == _keyCode)
		{
			return true;
		}
	}
	return false;
}

bool KeyboardHandler::GetKeyUp(int _keyCode)
{
	// Iterates through all the down keys that are pressed
	for (int i = 0; i < downKeys.size(); i++)
	{
		// If key is vector return true
		if (downKeys.at(i) == _keyCode)
		{
			return false;
		}
	}
	return true;
}

void KeyboardHandler::SetKeyPressed(SDL_Keycode _key)
{
	downKeys.push_back(_key);
}

void KeyboardHandler::SetKeyReleased(SDL_Keycode _key)
{
	// Remove key from down vector
	for (size_t i = 0; i < downKeys.size(); i++)
	{
		if (_key == downKeys.at(i))
		{
			downKeys.erase(downKeys.begin() + i);
			i--;
		}
	}
}




#include "KeyboardHandler.h"

namespace GameEngine
{

	bool KeyboardHandler::GetKeyUp(std::string _key)
	{
		// Iterates through all the down keys that are pressed
		for (int i = 0; i < downKeys.size(); i++)
		{
			// If key is vector return true
			if (SDL_GetKeyName(downKeys.at(i)) == _key)
			{
				return false;
			}
		}
		return true;
	}

	bool KeyboardHandler::GetKeyDown(std::string _key)
	{
		// Iterates through all the keys that are not pressed
		for (int i = 0; i < downKeys.size(); i++)
		{
			// If key is vector return true
			if (SDL_GetKeyName(downKeys.at(i)) == _key)
			{
				return true;
			}
		}
		return false;
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

}





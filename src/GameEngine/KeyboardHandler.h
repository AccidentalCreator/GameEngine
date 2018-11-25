#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include <vector>
#include <SDL2\SDL.h>
#include <string>

namespace GameEngine
{
	/**
	* Handles keyboard input
	*/
	class KeyboardHandler
	{
	public:
		/// Returns if a questioned key is pressed
		bool GetKeyDown(std::string _key);
		/// Returns if a questioned key is not pressed
		bool GetKeyUp(std::string _key);

		/// Sets a key as pressed
		void SetKeyPressed(SDL_Keycode _key);
		/// Sets a key as released
		void SetKeyReleased(SDL_Keycode _key);

	private:
		std::vector<int> keys;
		std::vector<int> upKeys;
		std::vector<int> downKeys;
	};

}



#endif
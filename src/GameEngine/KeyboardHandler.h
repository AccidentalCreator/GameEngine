#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include <vector>
#include <SDL2\SDL.h>
#include <string>

class KeyboardHandler
{
public:
	bool GetKeyDown(std::string _key);
	bool GetKeyUp(std::string _key);


	void SetKeyPressed(SDL_Keycode _key);
	void SetKeyReleased(SDL_Keycode _key);

private:
	std::vector<int> keys;
	std::vector<int> upKeys;
	std::vector<int> downKeys;
};

#endif
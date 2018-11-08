#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H

#include <vector>
#include <SDL2\SDL.h>


class KeyboardHandler
{
public:
	bool GetKey(int _keyCode);
	bool GetKeyDown(int _keyCode);
	bool GetKeyUp(int _keyCode);

	void SetKeyPressed(SDL_Keycode _key);
	void SetKeyReleased(SDL_Keycode _key);

private:
	std::vector<int> keys;
	std::vector<int> upKeys;
	std::vector<int> downKeys;
};

#endif
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <vector>


class Keyboard
{
public:
	bool GetKey(int _keyCode);
	bool GetKeyDown(int _keyCode);
	bool GetKeyUp(int _keyCode);

private:
	std::vector<int> keyCodes;
};

#endif
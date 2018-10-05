#pragma once

#ifndef SCREEN_H
#define SCREEN_H

#include <glm.hpp>

class Screen
{
public:
	glm::vec2 GetSize() { return size; };
	
private:
	glm::vec2 size;
};

#endif // !SCREEN_H

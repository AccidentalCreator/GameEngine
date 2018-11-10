#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <glm.hpp>

#include "Component.h"

class Button : public Component
{
public:
	void AddButton(glm::vec3 _position);

private:
	void Display();

	glm::vec3 position;
};

#endif // !BUTTON_H

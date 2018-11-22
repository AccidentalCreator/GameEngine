#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <glm.hpp>

#include "Component.h"

namespace GameEngine
{

	class MouseHandler;

	class Button : public Component
	{
	public:
		void Start();
		bool CheckClicked();

	private:

		std::shared_ptr<MouseHandler> mouseInput;

		glm::vec2 size;
		glm::vec2 position;

		bool runOnce;
	};

}


#endif // !BUTTON_H

#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <glm.hpp>

#include "Component.h"

namespace GameEngine
{

	class MouseHandler;

	/**
	* Adds a button to an orthagraphic entity
	*/

	class Button : public Component
	{
	public:
		void Start();
		/**
		* Checks if the button has been interacted with
		*/
		bool CheckClicked();

	private:

		std::shared_ptr<MouseHandler> mouseInput;

		glm::vec2 size; ///< Size of button
		glm::vec2 position; ///< Button position

		bool runOnce;
	};

}


#endif // !BUTTON_H

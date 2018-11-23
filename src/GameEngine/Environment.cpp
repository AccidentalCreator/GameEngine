#include "Environment.h"

#include <SDL2\SDL.h>
#include <iostream>

namespace GameEngine
{

	Environment::Environment()
	{
		deltaTime = 0;
		lastTime = SDL_GetTicks();
	}

	Environment::~Environment()
	{
	}

	void Environment::CalculateDeltaTime()
	{
		lastTime = newTime;
		newTime = SDL_GetTicks();
		deltaTime = (newTime - lastTime) / 1000;
	}

}

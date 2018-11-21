#include "Environment.h"

#include <SDL2\SDL.h>
#include <iostream>

void Environment::CalculateDeltaTime()
{
	lastTime = newTime;
	newTime = SDL_GetPerformanceCounter();

	deltaTime = (double)((newTime - lastTime) * 1000 / (double)SDL_GetPerformanceCounter());

	deltaTime *= 1000;

	//newTime = SDL_GetTicks();
	//deltaTime = newTime - lastTime;
	//lastTime = newTime;
	//std::cout << deltaTime << std::endl;
	

}
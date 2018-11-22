#include "Environment.h"

#include <SDL2\SDL.h>
#include <iostream>



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
	//lastTime = newTime;
	//newTime = SDL_GetPerformanceCounter();

	//deltaTime = (double)((newTime - lastTime) * 1000 / (double)SDL_GetPerformanceCounter());

	//deltaTime *= 1000;

	lastTime = newTime;
	newTime = SDL_GetTicks();
	deltaTime = (newTime - lastTime) / 1000;
	//std::cout << deltaTime << std::endl;
	

}
#include "Core.h"
#include "Entity.h"
#include "Screen.h"

#include <iostream>

std::shared_ptr<Core> Core::Initialize()
{
	std::shared_ptr<Core> rtn = std::make_shared<Core>();
	rtn->running = false;
	rtn->self = rtn;
	
	screen = std::make_shared<Screen>();

	screen->Init();

	return rtn;
}

void Core::Start()
{
	running = true;

	while (running) // add running bool false when stop
	{
		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
		}

		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->Update();
		}

		screen->Clear(); // Clear screen

		for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin();
			it != entities.end(); it++)
		{
			(*it)->Display();
		}

		screen->End(); // Swap window buffers
	}

}

std::shared_ptr<Entity> Core::AddEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
	entities.push_back(rtn);
	rtn->self = rtn;
	rtn->core = self;
	return rtn;
}

void Core::Stop()
{
	running = false;
}

#include "Entity.h"

#include <iostream>

namespace GameEngine
{

	std::shared_ptr<Core> Entity::GetCore()
	{
		return core.lock();
	}

	void Entity::Update()
	{
		for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
			it != components.end(); it++)
		{
			if (!(*it)->ranOnce)
			{
				(*it)->Awake();
				(*it)->ranOnce = true;
			}

			try
			{
				(*it)->Update();
			}
			catch (...) {}

		}
	}

	void Entity::LateUpdate()
	{
		for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
			it != components.end(); it++)
		{
			try
			{
				(*it)->LateUpdate();
			}
			catch (...) {}

		}
	}

	void Entity::Display()
	{
		for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
			it != components.end(); it++)
		{
			(*it)->Display();
		}
	}


	void Entity::Destroy()
	{
		std::cout << "Destroy called" << std::endl;
		isAlive = false;
	}

}

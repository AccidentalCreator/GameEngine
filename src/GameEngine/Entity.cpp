#include "Entity.h"

#include <iostream>

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

		(*it)->Update();

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
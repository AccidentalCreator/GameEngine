#include <iostream>

#include "Entity.h"
#include "Exception.h"

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
			catch (Exception& e)
			{
				std::cout << "Game Engine Exception: " << e.What() << std::endl;
			}
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
			catch (Exception& e)
			{
				std::cout << "Game Engine Exception: " << e.What() << std::endl;
			}
		}
	}

	void Entity::Display()
	{
		for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
			it != components.end(); it++)
		{
			try
			{
				(*it)->Display();
			}
			catch (Exception& e)
			{
				std::cout << "Game Engine Exception: " << e.What() << std::endl;
			}
		}
	}


	void Entity::Destroy()
	{
		isAlive = false;
	}

}

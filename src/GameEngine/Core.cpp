#include "Core.h"
#include "Entity.h"

std::shared_ptr<Core> Core::Initialize()
{
	return std::shared_ptr<Core>();
}

std::shared_ptr<Entity> Core::AddEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
	entities.push_back(rtn);
	return rtn;
}

void Core::Start()
{
	while (true) // add running bool false when stop
	{
		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->Tick();
		}
	}
}

void Core::Stop()
{

}

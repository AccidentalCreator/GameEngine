#include "Entity.h"
#include "Component.h"

void Entity::Tick()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		(*it)->OnTick();
	}
}

void Entity::Display()
{

}
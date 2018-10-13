#include "Component.h"
#include "Entity.h"

std::shared_ptr<Entity> Component::GetEntity()
{
	return entity.lock();
}

std::shared_ptr<Core> Component::GetCore()
{
	return GetEntity()->GetCore();
}

std::shared_ptr<Keyboard> Component::GetKeyboard()
{
	return std::shared_ptr<Keyboard>();
}

std::shared_ptr<Environment> Component::GetEnvironment()
{
	return std::shared_ptr<Environment>();
}

void Component::Awake()
{

}

void Component::Start()
{

}

void Component::Update()
{

}

void Component::Display()
{
	
}

Component::~Component()
{

}
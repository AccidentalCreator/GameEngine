#include "Component.h"
#include "Entity.h"
#include "Core.h"
#include "KeyboardHandler.h"

namespace GameEngine
{

std::shared_ptr<Entity> Component::GetEntity()
{
	return entity.lock();
}

std::shared_ptr<Core> Component::GetCore()
{
	return GetEntity()->GetCore();
}

std::shared_ptr<KeyboardHandler> Component::GetKeyboard()
{
	return GetCore()->GetKeyboard();
}

std::shared_ptr<MouseHandler> Component::GetMouse()
{
	return GetCore()->GetMouse();
}

std::shared_ptr<Environment> Component::GetEnvironment()
{
	return GetCore()->GetEnvironment();
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

void Component::LateUpdate()
{

}

void Component::Display()
{
	
}

Component::~Component()
{

}


}
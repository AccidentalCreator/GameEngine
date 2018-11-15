#pragma once
#ifndef COMPONENT_H
#define COMPONEMT_H

#include <memory>


class Entity;
class Core;
class Environment;
class KeyboardHandler;
class MouseHandler;

class Component
{ 
	// Friend class can access private and protected members from other class
	friend class Entity;
public:
	virtual ~Component();
	std::shared_ptr<Entity> GetEntity();
	std::shared_ptr<Core> GetCore();
	std::shared_ptr<KeyboardHandler> GetKeyboard();
	std::shared_ptr<MouseHandler> GetMouse();
	std::shared_ptr<Environment> GetEnvironment();


private:
	std::weak_ptr<Entity> entity;

	virtual void Awake();
	virtual void Start();
	virtual void Update();
	virtual void Display();

	bool ranOnce;
};

#endif
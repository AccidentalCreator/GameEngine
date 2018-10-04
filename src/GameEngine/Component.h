#pragma once
#ifndef COMPONENT_H
#define COMPONEMT_H

#include <memory>

class Entity;
class Core;
class Environment;
class Keyboard;

class Component
{
public:
	std::shared_ptr<Entity> GetEntity();
	std::shared_ptr<Core> GetCore();
	std::shared_ptr<Keyboard> GetKeyboard();
	std::shared_ptr<Environment> GetEnvironment();

private:
	std::weak_ptr<Entity> entity;

	void OnInit();
	void OnBegin();
	void OnTick();
	void OnDisplay();
};

#endif
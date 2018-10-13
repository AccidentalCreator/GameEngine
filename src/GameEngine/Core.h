#pragma once

#ifndef CORE_H
#define CORE_H


#include <vector>
#include <memory>

class Environment;
class Keyboard;
class Component;
class Entity;
class Screen;

class Core
{

public:
	std::shared_ptr<Core> Initialize();
	void Start();
	void Stop();
	std::shared_ptr<Entity> AddEntity();

private:
	
	std::shared_ptr<Environment> environment;
	std::vector<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Keyboard> keyboard;
	std::weak_ptr<Core> self;
	std::shared_ptr<Screen> screen;

	bool running;
};

#endif
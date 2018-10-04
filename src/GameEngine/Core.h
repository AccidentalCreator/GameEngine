#ifndef CORE_H
#define CORE_H

#pragma once

#include <vector>
#include <memory>

class Environment;
class Keyboard;
class Component;
class Entity;

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
	bool running;
};

#endif
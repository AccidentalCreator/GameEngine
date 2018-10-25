#pragma once

#ifndef CORE_H
#define CORE_H


#include <vector>
#include <memory>

#include <AL/al.h>
#include <AL/alc.h>

class Environment;
class Keyboard;
class Component;
class Entity;
class Screen;

class Core
{

public:
	static std::shared_ptr<Core> Initialize();
	void Start();
	void Stop();
	std::shared_ptr<Entity> AddEntity();
	std::shared_ptr<Screen> GetScreen() { return screen; }

private:
	
	std::shared_ptr<Environment> environment;
	std::vector<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Keyboard> keyboard;
	std::weak_ptr<Core> self;
	std::shared_ptr<Screen> screen;

	ALCdevice* device;
	ALCcontext* context;

	bool running;
};

#endif
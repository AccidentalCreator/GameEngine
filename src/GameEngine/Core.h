#pragma once
#ifndef CORE_H
#define CORE_H


#include <vector>
#include <memory>
#include <iostream>

#include <AL/al.h>
#include <AL/alc.h>

namespace GameEngine
{

	class Environment;
	class Component;
	class Entity;
	class Screen;
	class Resources;
	class Environment;
	class KeyboardHandler;
	class MouseHandler;

	/**
	* Monitors and handles all entites created
	*/

	class Core
	{

	public:
		/// Initiaises the core system
		static std::shared_ptr<Core> Initialize();
		/// Runs the program
		void Start();
		/// Stops the program
		void Stop();
		/// Adds an entity to core
		std::shared_ptr<Entity> AddEntity();
		/// Retrieves screen handler
		std::shared_ptr<Screen> GetScreen() { return screen; }
		/// Retrieves resource handler
		std::shared_ptr<Resources> GetResources() { return resources; }
		/// Retrieves environment handler
		std::shared_ptr<Environment> GetEnvironment() { return environment; }
		/// Retrieves keyboard handler
		std::shared_ptr<KeyboardHandler> GetKeyboard() { return keyboard; }
		/// Retireves mouse handler
		std::shared_ptr<MouseHandler> GetMouse() { return mouse; }
		/// Finds and returns entity with searched tag
		std::shared_ptr<Entity> FindEntityWithTag(std::string _tag);

		/// Finds and returns entity with attatched component
		template <typename T>
		std::shared_ptr<Entity> FindEntityWithComponent()
		{
			// Iterate through entities 
			for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin();
				it != entities.end(); it++)
			{
				// Iterates through all compenents in entity

				for (size_t i = 0; i < (*it)->components.size(); i++)
				{
					std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>((*it)->components.at(i));

					if (tst)
					{
						return *it;
					}
				}
			}
			// Otherwise return null
			return std::shared_ptr<Entity>();
		}



	private:
	
		std::shared_ptr<Environment> environment;
		std::vector<std::shared_ptr<Entity>> entities;
		std::shared_ptr<KeyboardHandler> keyboard;
		std::shared_ptr<MouseHandler> mouse;
		std::weak_ptr<Core> self;
		std::shared_ptr<Screen> screen;
		std::shared_ptr<Resources> resources;

		ALCdevice* device;
		ALCcontext* context;

		bool running;
	};

}


#endif
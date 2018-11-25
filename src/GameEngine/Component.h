#pragma once
#ifndef COMPONENT_H
#define COMPONEMT_H

#include <memory>

namespace GameEngine
{

	class Entity;
	class Core;
	class Environment;
	class KeyboardHandler;
	class MouseHandler;

	/**
	* Components can be assigned to enities, handle all the data and behaviours of the entities
	*/

	class Component
	{ 
		/// Friend class can access private and protected members from other class
		friend class Entity;
	public:
		virtual ~Component();
		/// Returns the entity the component is attatched to 
		std::shared_ptr<Entity> GetEntity();
		/// Returns the core of the game
		std::shared_ptr<Core> GetCore();
		/// Retrieves the keyboard handler
		std::shared_ptr<KeyboardHandler> GetKeyboard();
		/// Retrieves the mouse handler
		std::shared_ptr<MouseHandler> GetMouse();
		/// Retrieves the environment
		std::shared_ptr<Environment> GetEnvironment();


	private:
		std::weak_ptr<Entity> entity;

		virtual void Awake();
		virtual void Start();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Display();

		bool ranOnce;
	};

}


#endif
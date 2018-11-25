#pragma once
#ifndef ENTITY_H
#define ENTITY_H


#include <vector>
#include <memory>
#include <string>

#include "Component.h"

namespace GameEngine
{

	#define ADDCOMPONENT \
		std::shared_ptr<T> rtn = std::make_shared<T>();\
		rtn->entity = self; \
		rtn->ranOnce = false; \
		components.push_back(rtn);

	class Core;
	class Transform;

	/**
	* Acts as a repository for components
	*/

	class Entity
	{
		// Friend class can access private and protected members from other class
		friend class Core;
	public:
		/// Retrieves core
		std::shared_ptr<Core> GetCore();
		/// Destroys the entity safely
		void Destroy();

		/// Returns a component attatched to the entity
		template <typename T>
		std::shared_ptr<T> GetComponent()
		{
			for (size_t i = 0; i < components.size(); i++)
			{
				std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>(components.at(i));

				if (tst)
				{
					return tst;
				}
			}

			throw ("Component not found");
		}

		/// Adds a component to the entity
		template <typename T>
		std::shared_ptr<T> AddComponent()
		{
			ADDCOMPONENT
				rtn->Start();

			return rtn;
		}

		/// Adds a component to the entity
		template <typename T, typename A>
		std::shared_ptr<T> AddComponent(A a)
		{
			ADDCOMPONENT
				rtn->Start(a);

			return rtn;
		}

		/// Adds a component to the entity
		template <typename T, typename A, typename B>
		std::shared_ptr<T> AddComponent(A a, B b)
		{
			ADDCOMPONENT
				rtn->Start(a, b);

			return rtn;
		}

		/// Adds a component to the entity
		template <typename T, typename A, typename B, typename C>
		std::shared_ptr<T> AddComponent(A a, B b, C c)
		{
			ADDCOMPONENT
				rtn->Start(a, b, c);

			return rtn;
		}

		/// Retrieves the tag given to the entity
		std::string GetTag() { return tag; }
		/// Sets a tag to the entity
		void SetTag(std::string _tag) { tag = _tag; }

	private:
		std::vector<std::shared_ptr<Component>> components;
		std::weak_ptr<Core> core;
		std::weak_ptr<Entity> self;

		void Update();
		void LateUpdate();
		void Display();

		bool isAlive;

		std::string tag;
	};

}


#endif
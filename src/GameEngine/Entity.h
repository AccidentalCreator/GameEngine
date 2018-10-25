#ifndef ENTITY_H
#define ENTITY_H

#include "Component.h"

#include <vector>
#include <memory>

#define ADDCOMPONENT \
	std::shared_ptr<T> rtn = std::make_shared<T>();\
	rtn->entity = self; \
	rtn->ranOnce = false; \
	components.push_back(rtn);

class Core;
class Transform;

class Entity
{
	// Friend class can access private and protected members from other class
	friend class Core;
public:
	std::shared_ptr<Core> GetCore();
	void Destroy();

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

		throw std::exception();
	}

	template <typename T>
	std::shared_ptr<T> AddComponent()
	{
		ADDCOMPONENT
			rtn->Start();

		return rtn;
	}

	template <typename T, typename A>
	std::shared_ptr<T> AddComponent(A a)
	{
		ADDCOMPONENT
			rtn->Start(a);

		return rtn;
	}

	template <typename T, typename A, typename B>
	std::shared_ptr<T> AddComponent(A a, B b)
	{
		ADDCOMPONENT
			rtn->Start(a, b);

		return rtn;
	}

private:
	std::vector<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;
	std::weak_ptr<Entity> self;

	void Update();
	void Display();

	bool isAlive;
};

#endif
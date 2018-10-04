#ifndef ENTITY_H
#define ENTITY_H


#include <vector>
#include <memory>

class Component;
class Core;

class Entity
{
public:
	std::shared_ptr<Core>& GetCore() { return core.lock(); };

	template <typename T> 
	std::shared_ptr<T> AddComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();

		components.push_back(rtn);
		return rtn;
	}
	//template <typename T, typename A> std::shared_ptr<T> AddComponent<T, A>(a:A);
	//template <typename T, typename A, template B> std::shared_ptr<T> AddComponent<T, A, B>(a:A, b:B);
	//template <typename T, typename A, template B, template C> std::shared_ptr<T> AddComponent<T, A, B, C>(a : A, b : B, c : C);
	void Tick();

private:
	std::vector<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;

	void Display();

};

#endif
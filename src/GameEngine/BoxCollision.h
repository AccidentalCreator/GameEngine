#pragma once
#ifndef BOXCOLLISION_H
#define BOXCOLLISION_H

#include <memory>

namespace GameEngine
{
	class Entity;

	/**
	* Checks box collision between two entiies
	*/

	class BoxCollision
	{
	public:
		/// Checks AABB Collision between two entities
		bool CheckCollision(std::weak_ptr<Entity> _a, std::weak_ptr<Entity> _b);

	private:

	};
}


#endif // !BOXCOLLISION_H



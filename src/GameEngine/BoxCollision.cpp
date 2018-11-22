#include "BoxCollision.h"
#include "Entity.h"
#include "Transform.h"
#include <iostream>

namespace GameEngine
{

	bool BoxCollision::CheckCollision(std::weak_ptr<Entity> _a, std::weak_ptr<Entity> _b)
	{
		bool xTrue = false;
		bool zTrue = false;
		bool yTrue = false;


		if (_a.lock()->GetComponent<Transform>()->GetPosition().x <= _b.lock()->GetComponent<Transform>()->GetPosition().x + _b.lock()->GetComponent<Transform>()->GetInWorldSize().x / 2
			&& _a.lock()->GetComponent<Transform>()->GetPosition().x >= _b.lock()->GetComponent<Transform>()->GetPosition().x - _b.lock()->GetComponent<Transform>()->GetInWorldSize().x / 2)
		{
			xTrue = true;
			if (_a.lock()->GetComponent<Transform>()->GetPosition().z <= _b.lock()->GetComponent<Transform>()->GetPosition().z + _b.lock()->GetComponent<Transform>()->GetInWorldSize().z / 2
				&& _a.lock()->GetComponent<Transform>()->GetPosition().z >= _b.lock()->GetComponent<Transform>()->GetPosition().z - _b.lock()->GetComponent<Transform>()->GetInWorldSize().z / 2)
			{
				zTrue = true;
				if (_a.lock()->GetComponent<Transform>()->GetPosition().y <= _b.lock()->GetComponent<Transform>()->GetPosition().y + _b.lock()->GetComponent<Transform>()->GetInWorldSize().y / 2
					&& _a.lock()->GetComponent<Transform>()->GetPosition().y >= _b.lock()->GetComponent<Transform>()->GetPosition().y - _b.lock()->GetComponent<Transform>()->GetInWorldSize().y / 2)
				{
					yTrue = true;
				}
			}
		}

		if (xTrue 
			&& zTrue
			&& yTrue)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

}

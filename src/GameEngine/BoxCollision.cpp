#include "BoxCollision.h"
#include "Entity.h"
#include "Transform.h"

bool BoxCollision::CheckCollision(std::weak_ptr<Entity> _a, std::weak_ptr<Entity> _b)
{
	bool xTrue = false;
	bool yTrue = false;

	//if (_a.lock()->GetComponent<Transform>()->GetPosition().x < _b.lock()->GetComponent<Transform>()->GetPosition().x)
	//{
	//	if (_a.lock()->GetComponent<Transform>()->GetPosition().x + _a.lock()->GetComponent<Transform>()->GetSize().x
	//		< _b.lock()->GetComponent<Transform>()->GetPosition().x)
	//	{
	//		xTrue = true;
	//	}
	//}
	//else
	//{
	//	if (_b.lock()->GetComponent<Transform>()->GetPosition().x + _b.lock()->GetComponent<Transform>()->GetSize().x
	//		< _a.lock()->GetComponent<Transform>()->GetPosition().x)
	//	{
	//		xTrue = true;
	//	}
	//}

	//if (_a.lock()->GetComponent<Transform>()->GetPosition().y < _b.lock()->GetComponent<Transform>()->GetPosition().y)
	//{
	//	if (_a.lock()->GetComponent<Transform>()->GetPosition().y + _a.lock()->GetComponent<Transform>()->GetSize().y
	//		< _b.lock()->GetComponent<Transform>()->GetPosition().y)
	//	{
	//		yTrue = true;
	//	}
	//}
	//else
	//{
	//	if (_b.lock()->GetComponent<Transform>()->GetPosition().y + _b.lock()->GetComponent<Transform>()->GetSize().y
	//		< _a.lock()->GetComponent<Transform>()->GetPosition().y)
	//	{
	//		yTrue = true;
	//	}
	//}

	if (_a.lock()->GetComponent<Transform>()->GetPosition().x <= _b.lock()->GetComponent<Transform>()->GetPosition().x + _b.lock()->GetComponent<Transform>()->GetSize().x / 2
		&& _a.lock()->GetComponent<Transform>()->GetPosition().x >= _b.lock()->GetComponent<Transform>()->GetPosition().x - _b.lock()->GetComponent<Transform>()->GetSize().x / 2)
	{
		xTrue = true;
		if (_a.lock()->GetComponent<Transform>()->GetPosition().z <= _b.lock()->GetComponent<Transform>()->GetPosition().z + _b.lock()->GetComponent<Transform>()->GetSize().y / 2
			&& _a.lock()->GetComponent<Transform>()->GetPosition().z >= _b.lock()->GetComponent<Transform>()->GetPosition().z - _b.lock()->GetComponent<Transform>()->GetSize().y / 2)
		{
			yTrue = true;
		}
	}

	if (xTrue && yTrue)
	{
		return true;
	}
	else
	{
		return false;
	}

}
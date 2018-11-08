#include "BoxCollision.h"
#include "Entity.h"
#include "Transform.h"

bool BoxCollision::CheckCollision(Entity _a, Entity _b)
{
	bool xTrue = false;
	bool yTrue = false;

	if (_a.GetComponent<Transform>()->GetPosition().x < _b.GetComponent<Transform>()->GetPosition().x)
	{
		if (_a.GetComponent<Transform>()->GetPosition().x + _a.GetComponent<Transform>()->GetSize().x
			< _b.GetComponent<Transform>()->GetPosition().x)
		{
			xTrue = true;
		}
	}
	else
	{
		if (_b.GetComponent<Transform>()->GetPosition().x + _b.GetComponent<Transform>()->GetSize().x
			< _a.GetComponent<Transform>()->GetPosition().x)
		{
			xTrue = true;
		}
	}

	if (_a.GetComponent<Transform>()->GetPosition().y < _b.GetComponent<Transform>()->GetPosition().y)
	{
		if (_a.GetComponent<Transform>()->GetPosition().y + _a.GetComponent<Transform>()->GetSize().y
			< _b.GetComponent<Transform>()->GetPosition().y)
		{
			xTrue = true;
		}
	}
	else
	{
		if (_b.GetComponent<Transform>()->GetPosition().y + _b.GetComponent<Transform>()->GetSize().y
			< _a.GetComponent<Transform>()->GetPosition().y)
		{
			xTrue = true;
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
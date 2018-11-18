#pragma once
#ifndef PICKUPHANDLER_H
#define PICKUPHANDLER_H

#include <GameEngine\GameEngine.h>
#include <memory>

class PickUpHandler : public Component
{
public:
	void Awake();
	void Start();
	void Update();

private:
	void CheckCollided();


	std::weak_ptr<Entity> player;
	BoxCollision boxCollision;
};


#endif // !PICKUPHANDLER_H

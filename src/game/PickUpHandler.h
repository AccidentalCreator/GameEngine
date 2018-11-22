#pragma once
#ifndef PICKUPHANDLER_H
#define PICKUPHANDLER_H

#include <GameEngine\GameEngine.h>
#include <memory>

using namespace GameEngine;

class PickUpHandler : public Component
{
public:
	void Awake();
	void Start();
	void Update();

private:
	void CheckCollided();
	void Rotate();

	std::weak_ptr<Entity> player;
	std::weak_ptr<Entity> game;
	BoxCollision boxCollision;
	float angle;
};


#endif // !PICKUPHANDLER_H

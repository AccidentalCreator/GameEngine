#pragma once
#ifndef PICKUPHANDLER_H
#define PICKUPHANDLER_H

#include <GameEngine\GameEngine.h>
#include <memory>

using namespace GameEngine;

// Controls the star pickups
class PickUpHandler : public Component
{
public:
	// Initialisation of the pick ups
	void Awake();
	// Further variable initialisation
	void Start();
	// Updates the pickups
	void Update();

private:
	// Checks if the pickups have been collided with
	void CheckCollided();
	// Rotates the stars to make them spin
	void Rotate();

	std::weak_ptr<Entity> player;
	std::weak_ptr<Entity> game;
	BoxCollision boxCollision;
	float angle;
};


#endif // !PICKUPHANDLER_H

#pragma once
#ifndef FLOORBLOCK_H
#define FLOORBLOCK_H

#include <GameEngine\GameEngine.h>

class FloorBlock : public Component
{
public:
	void Awake();
	void Start();
	void Update();
	void Display();

	void SetCounter(int _number) { counter = _number; }

private:
	void FloorPlayerCollision();

	std::weak_ptr<Entity> player;
	BoxCollision collision;
	bool collided;
	float countDown = 1;
	bool flagPlayer;

	int counter;
};

#endif // !FLOORBLOCK_H
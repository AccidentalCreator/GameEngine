#include "FloorBlock.h"
#include "PlayerHandler.h"
#include <iostream>

void FloorBlock::Awake()
{
	//player = GetCore()->FindEntityWithTag("Player");
	//timer = std::make_shared<Timer>(timer);
}

void FloorBlock::Start()
{
	collided = false;
	flagPlayer = false;
	startTimerOnce = true;
	disappearTime = 3.0f;
	isAlive = true;
}

void FloorBlock::Update()
{
	//FloorPlayerCollision();

	if (collided)
	{
		if (!timer.Running())
		{
			if (collision.CheckCollision(GetEntity(), player))
			{
				player.lock()->GetComponent<PlayerHandler>()->SetColliding(false);
			}
			isAlive = false;
		}
	}
}

void FloorBlock::Display()
{
}

void FloorBlock::FloorPlayerCollision()
{
	if (collision.CheckCollision(GetEntity(), player))
	{
		collided = true;
		player.lock()->GetComponent<PlayerHandler>()->SetColliding(true);
		if (startTimerOnce)
		{
			timer.Start(disappearTime);
			startTimerOnce = false;
		}
	}
}

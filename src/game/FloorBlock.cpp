#include "FloorBlock.h"
#include "PlayerHandler.h"
#include <iostream>

void FloorBlock::Awake()
{
	player = GetCore()->FindEntityWithTag("Player");
	collided = false;
	flagPlayer = false;
}

void FloorBlock::Start()
{
}

void FloorBlock::Update()
{
	if (!collided && counter != 1)
		FloorPlayerCollision();
	else if (collided)
	{
		FloorPlayerCollision();
		countDown -= GetEnvironment()->GetDeltaTime();
		if (countDown < 0)
		{
			if (collision.CheckCollision(GetEntity(), player))
			{
				player.lock()->GetComponent<PlayerHandler>()->SetColliding(false);
			}
			GetEntity()->Destroy();
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
	}

}

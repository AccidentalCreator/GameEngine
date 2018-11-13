#include "FloorBlock.h"

#include <iostream>

void FloorBlock::Awake()
{
	player = GetCore()->FindEntityWithTag("Player");
	collided = false;
}

void FloorBlock::Start()
{
}

void FloorBlock::Update()
{
	if (!collided)
		FloorPlayerCollision();
	else if (collided)
	{
		countDown -= GetEnvironment()->GetDeltaTime();
		if (countDown < 0)
		{
			GetEntity()->Destroy();
		}
	}
}

void FloorBlock::Display()
{
}

void FloorBlock::FloorPlayerCollision()
{
	static int i = 0;
	if (collision.CheckCollision(GetEntity(), player))
	{
		collided = true;
	}
}

#include "FloorBlock.h"

#include <iostream>

void FloorBlock::Awake()
{
	player = GetCore()->FindEntityWithTag("Player");
}

void FloorBlock::Start()
{
}

void FloorBlock::Update()
{
	FloorPlayerCollision();
}

void FloorBlock::Display()
{
}

void FloorBlock::FloorPlayerCollision()
{
	static int i = 0;
	if (collision.CheckCollision(GetEntity(), player))
	{

	}
}

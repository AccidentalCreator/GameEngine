#include "PickUpHandler.h"

void PickUpHandler::Awake()
{
	player = GetCore()->FindEntityWithTag("Player");
}

void PickUpHandler::Start()
{
}

void PickUpHandler::Update()
{
	CheckCollided();
}

void PickUpHandler::CheckCollided()
{
	if (boxCollision.CheckCollision(GetEntity(), player))
	{
		GetEntity()->Destroy();
	}
}

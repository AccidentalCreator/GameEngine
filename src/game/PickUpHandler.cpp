#include "PickUpHandler.h"
#include "Game.h"

void PickUpHandler::Awake()
{
	player = GetCore()->FindEntityWithTag("Player");
	game = GetCore()->FindEntityWithTag("Game");
}

void PickUpHandler::Start()
{
	angle = 0.0f;
}

void PickUpHandler::Update()
{
	Rotate();
	CheckCollided();
}

void PickUpHandler::CheckCollided()
{
	if (boxCollision.CheckCollision(player, GetEntity()))
	{
		game.lock()->GetComponent<Game>()->IncrementScore();
		GetEntity()->Destroy();
	}
}

void PickUpHandler::Rotate()
{
	angle += 40.0f * GetEnvironment()->GetDeltaTime();
	GetEntity()->GetComponent<Transform>()->SetRotation(angle);
}

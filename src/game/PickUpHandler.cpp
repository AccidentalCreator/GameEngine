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
	// Checks for collision with player
	if (boxCollision.CheckCollision(player, GetEntity()))
	{
		GetEntity()->GetComponent<Sound>()->Play();
		game.lock()->GetComponent<Game>()->IncrementScore();
		GetEntity()->Destroy();
	}
}

void PickUpHandler::Rotate()
{
	// Rotates star because why not
	angle += 40.0f * GetEnvironment()->GetDeltaTime();
	GetEntity()->GetComponent<Transform>()->SetRotation(angle);
}

#include "PlayerHandler.h"

#include <iostream>


void PlayerHandler::Awake()
{
	speed = 5;
	movementMade = false;
	input = GetKeyboard();
	position = std::make_shared<glm::vec3>(GetEntity()->GetComponent<Transform>()->GetPosition());
}

void PlayerHandler::Start()
{
}

void PlayerHandler::Update()
{
	Movement();
	movementMade = false;
}

void PlayerHandler::Display()
{
}

void PlayerHandler::Movement()
{
	if (input->GetKeyDown("A"))
	{
		position->x += speed * GetEnvironment()->GetDeltaTime();
		movementMade = true;
	}
	else if (input->GetKeyDown("D"))
	{
		position->x -= speed * GetEnvironment()->GetDeltaTime();
		movementMade = true;
	}
	else if (input->GetKeyDown("W"))
	{
		position->z += speed * GetEnvironment()->GetDeltaTime();
		movementMade = true;
	}
	else if (input->GetKeyDown("S"))
	{
		position->z -= speed * GetEnvironment()->GetDeltaTime();
		movementMade = true;
	}

	if (movementMade)
	{
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
}
#include "PlayerHandler.h"

#include <iostream>


void PlayerHandler::Awake()
{
	speed = 1;
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
	if (input->GetKeyDown("A") 
		&& !movementMade)
	{
		position->x += speed;
		movementMade = true;
	}
	else if (input->GetKeyDown("D")
		&& !movementMade)
	{
		position->x -= speed;
		movementMade = true;
	}
	else if (input->GetKeyDown("W")
		&& !movementMade)
	{
		position->z += speed;
		movementMade = true;
	}
	else if (input->GetKeyDown("S")
		&& !movementMade)
	{
		position->z -= speed;
		movementMade = true;
	}

	if (movementMade)
	{
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
}
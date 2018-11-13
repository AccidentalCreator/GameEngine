#include "PlayerHandler.h"

#include <iostream>


void PlayerHandler::Awake()
{
	colliding = true;
	speed = 5;
	input = GetKeyboard();
	position = std::make_shared<glm::vec3>(GetEntity()->GetComponent<Transform>()->GetPosition());
}

void PlayerHandler::Start()
{
}

void PlayerHandler::Update()
{
	Movement();
	CheckKeyRelease();
	GravitySim();
}

void PlayerHandler::Display()
{
}

void PlayerHandler::GravitySim()
{
	if (!colliding)
	{
		position->y -= GetEnvironment()->GetDeltaTime() * 50;
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
}

void PlayerHandler::Movement()
{
	if (input->GetKeyDown("A") 
		&& !movementLeft)
	{
		colliding = false;
		position->x += speed;
		movementLeft = true;
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
	if (input->GetKeyDown("D")
		&& !movementRight)
	{
		colliding = false;
		position->x -= speed;
		movementRight = true;
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
	if (input->GetKeyDown("W")
		&& !movementUp)
	{
		colliding = false;
		position->z += speed;
		movementUp = true;
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
	if (input->GetKeyDown("S")
		&& !movementDown)
	{
		colliding = false;
		position->z -= speed;
		movementDown = true;
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
}

void PlayerHandler::CheckKeyRelease()
{
	if (input->GetKeyUp("A"))
	{
		movementLeft = false;
	}
	if (input->GetKeyUp("D"))
	{
		movementRight = false;
	}
	if (input->GetKeyUp("W"))
	{
		movementUp = false;
	}
	if (input->GetKeyUp("S"))
	{
		movementDown = false;
	}
}
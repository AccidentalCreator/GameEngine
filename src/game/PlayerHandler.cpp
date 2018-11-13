#include "PlayerHandler.h"

#include <iostream>


void PlayerHandler::Awake()
{
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
}

void PlayerHandler::Display()
{
}

void PlayerHandler::Movement()
{
	if (input->GetKeyDown("A") 
		&& !movementLeft)
	{
		position->x += speed;
		movementLeft = true;
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
	if (input->GetKeyDown("D")
		&& !movementRight)
	{
		position->x -= speed;
		movementRight = true;
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
	if (input->GetKeyDown("W")
		&& !movementUp)
	{
		position->z += speed;
		movementUp = true;
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
	if (input->GetKeyDown("S")
		&& !movementDown)
	{
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
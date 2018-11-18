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
	//GravitySim();
}

void PlayerHandler::Display()
{
}

void PlayerHandler::Movement()
{
	if (input->GetKeyDown("A"))
	{
		position->x += speed;
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
	if (input->GetKeyDown("D"))
	{
		position->x -= speed;
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
	if (input->GetKeyDown("W"))
	{
		position->z += speed;
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
	if (input->GetKeyDown("S"))
	{
		position->z -= speed;
		GetEntity()->GetComponent<Transform>()->SetPosition(*position.get());
	}
}
#include "PlayerHandler.h"

#include <iostream>

void PlayerHandler::Awake()
{
	keyInput = GetKeyboard();
	mouseInput = GetMouse();
	mouseSensitivity = 0.5f;
	cameraFront = GetEntity()->GetComponent<Camera>()->GetCameraFront();
	startPosition = transform->GetPosition();
	gravityStrength = 0.5f;
}

void PlayerHandler::Start()
{
	transform = GetEntity()->GetComponent<Transform>();
	transform->SetPosition(glm::vec3(80, 10, 45)); 
	groundPosition = 9;
	speed = 7.0f;
	jumping = false;
	jumpPeak = false;
	grounded = false;
	sprinting = false;
}

void PlayerHandler::Update()
{
	Movement();
	Direction();
	Gravity();
}

void PlayerHandler::Movement()
{
	postition = transform->GetPosition();

	glm::vec3 lastPosition = transform->GetPosition();
	
	glm::vec3 cameraFrontTemp = *cameraFront;
	cameraFrontTemp.y = 0;

	if (keyInput->GetKeyDown("W"))
	{
		postition += speed * cameraFrontTemp * GetEnvironment()->GetDeltaTime();;
	}
	if (keyInput->GetKeyDown("S"))
	{
		postition -= speed * cameraFrontTemp * GetEnvironment()->GetDeltaTime();;
	}
	if (keyInput->GetKeyDown("A"))
	{
		postition -= glm::normalize(glm::cross(cameraFrontTemp, glm::vec3(0, 1, 0))) * speed * GetEnvironment()->GetDeltaTime();;
	}
	if (keyInput->GetKeyDown("D"))
	{
		postition += glm::normalize(glm::cross(cameraFrontTemp, glm::vec3(0, 1, 0))) * speed * GetEnvironment()->GetDeltaTime();;
	}
	if (keyInput->GetKeyDown("Left Shift")
		&& !sprinting)
	{
		std::cout << "SPRINTING" << std::endl;
		speed *= 2.0f;
		sprinting = true;
	}
	if (keyInput->GetKeyUp("Left Shift")
		&& sprinting)
	{
		speed /= 2.0f;
		sprinting = false;
	}
	if (keyInput->GetKeyDown("Space") 
		&& !jumping 
		&& grounded)
	{
		jumping = true;
		jumpPeak = false;
		maxJumpHeight = postition.y + 20;
		gravityStrength = 0.5f;
	}
	CheckCollision(lastPosition, postition);
	if (postition.y < -20)
	{
		transform->SetPosition(glm::vec3(80, 10, 45));
	}
}

void PlayerHandler::Direction()
{
	if (runOnce)
	{
		lastMouseX = mouseInput->GetMousePosition().x;
		lastMouseY = mouseInput->GetMousePosition().y;
		runOnce = false;
	}

	offsetX = mouseInput->GetMousePosition().x - lastMouseX;
	offsetY = lastMouseY - mouseInput->GetMousePosition().y;
	lastMouseX = mouseInput->GetMousePosition().x;
	lastMouseY = mouseInput->GetMousePosition().y;

	offsetX *= mouseSensitivity;
	offsetY *= mouseSensitivity;

	yaw += offsetX;
	pitch += offsetY;

	if (pitch > 89.0f)
	{
		pitch = 89.0f;
	}
	if (pitch < -89.0f)
	{
		pitch = -89.0f;
	}

	newCameraFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	newCameraFront.y = sin(glm::radians(pitch));
	newCameraFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	newCameraFront = glm::normalize(newCameraFront);
	GetEntity()->GetComponent<Camera>()->SetCameraFront(newCameraFront);

	
}

void PlayerHandler::CheckCollision(glm::vec3 lastPosition, glm::vec3 newPosition)
{
	newPosition = newPosition + glm::vec3 (0, -1, 0);

	bool solved = false;
	glm::vec3 solvedPosition = staticMeshCollider->CollisionAdjustment(newPosition, transform->GetSize(), solved, lastPosition);

	if (solved)
	{
		// Check if collided with ground
		if (staticMeshCollider->GetCollidingY())
		{
			groundPosition = staticMeshCollider->GetUncollideY();
			grounded = true;
		}
		else
		{
  			grounded = false;
		}
		newPosition = solvedPosition;
	}
	else
	{
		newPosition = lastPosition;
	}
	
	newPosition = newPosition + glm::vec3(0, 1, 0);
	transform->SetPosition(newPosition);
}

void PlayerHandler::Gravity()
{
	// Gravity - Brings player down
	if ((transform->GetPosition().y + transform->GetSize().y > groundPosition && !jumping)
		|| (jumping && !grounded && jumpPeak))
	{
		MovePlayerDown();
	}
	else if (!jumping && !grounded && !staticMeshCollider->GetCollidingY())
	{
		MovePlayerDown();
	}

	// If jumping move player up
	if (jumping 
		&& transform->GetPosition().y < maxJumpHeight
		&& !jumpPeak)
	{
		grounded = false;
		MovePlayerUp();
		if (transform->GetPosition().y > maxJumpHeight - 1.0f)
		{
			jumpPeak = true;
		}
	}

	if (jumpPeak 
		&& grounded)
	{
		jumping = false;
	}
	
}

void PlayerHandler::MovePlayerUp()
{
	glm::vec3 position = transform->GetPosition();
	position.y += gravityStrength;
	transform->SetPosition(position);
}

void PlayerHandler::MovePlayerDown()
{
	glm::vec3 position = transform->GetPosition();
	position.y -= gravityStrength;
	transform->SetPosition(position);
}

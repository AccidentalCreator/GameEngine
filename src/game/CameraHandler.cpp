#include "CameraHandler.h"

#include <iostream>

void CameraHandler::Awake()
{
	keyInput = GetKeyboard();
	mouseInput = GetMouse();
	transform = GetEntity()->GetComponent<Transform>();
	mouseSensitivity = 0.5f;
	cameraFront = GetEntity()->GetComponent<Camera>()->GetCameraFront();
	transform->SetPosition(glm::vec3(80, 10, 45));
	startPosition = transform->GetPosition();
	gravityStrength = 0.5f;
	groundPosition = 9;
	jumping = false;
	jumpPeak = false;
	grounded = false;
}

void CameraHandler::Start()
{
}

void CameraHandler::Update()
{
	Movement();
	Direction();
	Gravity();
}

void CameraHandler::Movement()
{
	speed = 7.0f * GetEnvironment()->GetDeltaTime();
	postition = transform->GetPosition();

	glm::vec3 lastPosition = transform->GetPosition();
	
	glm::vec3 cameraFrontTemp = *cameraFront;
	cameraFrontTemp.y = 0;

	if (keyInput->GetKeyDown("W"))
	{
		postition += speed * cameraFrontTemp;
	}
	if (keyInput->GetKeyDown("S"))
	{
		postition -= speed * cameraFrontTemp;
	}
	if (keyInput->GetKeyDown("A"))
	{
		postition -= glm::normalize(glm::cross(cameraFrontTemp, glm::vec3(0, 1, 0))) * speed;
	}
	if (keyInput->GetKeyDown("D"))
	{
		postition += glm::normalize(glm::cross(cameraFrontTemp, glm::vec3(0, 1, 0))) * speed;
	}
	if (keyInput->GetKeyDown("Space") 
		&& !jumping)
	{
		jumping = true;
		jumpPeak = false;
		maxJumpHeight = postition.y + 25;
		gravityStrength = 0.5f;
	}
	CheckCollision(lastPosition, postition);
}

void CameraHandler::Direction()
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

void CameraHandler::CheckCollision(glm::vec3 lastPosition, glm::vec3 newPosition)
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

void CameraHandler::Gravity()
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

void CameraHandler::MovePlayerUp()
{
	glm::vec3 position = transform->GetPosition();
	position.y += gravityStrength;
	transform->SetPosition(position);
}

void CameraHandler::MovePlayerDown()
{
	glm::vec3 position = transform->GetPosition();
	position.y -= gravityStrength;
	transform->SetPosition(position);
}

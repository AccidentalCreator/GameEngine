#include "CameraHandler.h"

#include <iostream>

void CameraHandler::Awake()
{
	keyInput = GetKeyboard();
	mouseInput = GetMouse();
	transform = GetEntity()->GetComponent<Transform>();
	mouseSensitivity = 0.5f;
	cameraFront = GetEntity()->GetComponent<Camera>()->GetCameraFront();
	//player = GetCore()->FindEntityWithTag("Player");
}

void CameraHandler::Start()
{
}

void CameraHandler::LateUpdate()
{
	//GetEntity()->GetComponent<Camera>()->SetTarget(player.lock()->GetComponent<Transform>()->GetPosition());
	//glm::vec3 position = GetEntity()->GetComponent<Transform>()->GetPosition() + glm::vec3(0, 10, -15);
	//transform->SetPosition( position);
	Movement();
	Direction();
}

void CameraHandler::Movement()
{
	speed = 7.0f * GetEnvironment()->GetDeltaTime();
	postition = transform->GetPosition();

	glm::vec3 lastPosition = transform->GetPosition();
	if (keyInput->GetKeyDown("W"))
	{
		postition += speed * *cameraFront;
	}
	if (keyInput->GetKeyDown("S"))
	{
		postition -= speed * *cameraFront;
	}
	if (keyInput->GetKeyDown("A"))
	{
		postition -= glm::normalize(glm::cross(*cameraFront, glm::vec3(0, 1, 0))) * speed;
	}
	if (keyInput->GetKeyDown("D"))
	{
		postition += glm::normalize(glm::cross(*cameraFront, glm::vec3(0, 1, 0))) * speed;
	}
	//postition.y = 0;
	//CheckCollision(lastPosition, postition);
	transform->SetPosition(postition);
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
	static int i = 0;

	newPosition = newPosition + glm::vec3 (0, -1, 0);

	bool solved = false;

	glm::vec3 solvedPosition = staticMeshCollider->CollisionAdjustment(newPosition, glm::vec3(1, 1, 1), solved, lastPosition);

	if (solved)
	{
		std::cout << solved << " " << i << std::endl;
		i++;
		newPosition = solvedPosition;
	}
	else
	{
		newPosition = lastPosition;
	}
	
	newPosition = newPosition + glm::vec3(0, 1, 0);
	transform->SetPosition(newPosition);

}

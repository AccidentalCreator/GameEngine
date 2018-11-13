#include "CameraHandler.h"

void CameraHandler::Awake()
{
	player = GetCore()->FindEntityWithTag("Player");
	playerPosition = std::make_shared<glm::vec3>(GetEntity()->GetComponent<Transform>()->GetPosition());
	GetEntity()->GetComponent<Camera>()->SetPosition(*playerPosition);
}

void CameraHandler::Start()
{

}

void CameraHandler::Update()
{
	playerPosition = std::make_shared<glm::vec3>(player->GetComponent<Transform>()->GetPosition());
	//std::cout << playerPosition->x << std::endl;
	GetEntity()->GetComponent<Camera>()->SetPosition(*playerPosition + glm::vec3 (0, 10, -35));
}

void CameraHandler::FollowPlayer()
{

}
#include "CameraHandler.h"

void CameraHandler::Awake()
{
	player = GetCore()->FindEntityWithTag("Player");
	playerPosition = std::make_shared<glm::vec3>(player->GetComponent<Transform>()->GetPosition());
}

void CameraHandler::Start()
{

}

void CameraHandler::Update()
{
	std::cout << playerPosition.get()->x << std::endl;
	//position = *playerPosition.lock().get();// +glm::vec3(0, 3, 0);
	//position = playerPosition.get() + glm::vec3(0, 3, 0);
	GetEntity()->GetComponent<Transform>()->SetPosition(position);
	//std::cout << GetEntity()->GetComponent<Transform>()->GetPosition().x << std::endl;
}

void CameraHandler::FollowPlayer()
{

}
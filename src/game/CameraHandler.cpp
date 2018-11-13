#include "CameraHandler.h"

void CameraHandler::Awake()
{
	//player = GetCore()->FindEntityWithTag("Player");
	//GetEntity()->GetComponent<Camera>()->SetTarget(player->GetComponent<Transform>()->GetPosition());
	//position = std::make_shared<glm::vec3>(GetEntity()->GetComponent<Transform>()->GetPosition());	
}

void CameraHandler::Start()
{

}

void CameraHandler::Update()
{
	//playerPosition = std::make_shared<glm::vec3>(player->GetComponent<Transform>()->GetPosition());
	//std::cout << playerPosition->x << std::endl;
	//position = *playerPosition.lock().get();// +glm::vec3(0, 3, 0);
	//position = *playerPosition.get();// +glm::vec3(0, 3, -2);
	//position.y += 3;
	//GetEntity()->GetComponent<Camera>()->SetPosition(position);
	//std::cout << GetEntity()->GetComponent<Transform>()->GetPosition().x << std::endl;
}

void CameraHandler::FollowPlayer()
{

}
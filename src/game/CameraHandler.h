#ifndef CAMERAHANDLER_H
#define CAMERAHANDLER_H

#include "GameEngine\GameEngine.h"
#include "glm.hpp"
#include <memory>

class CameraHandler : public Component
{
public:	
	void Awake();
	void Start();
	void Update();

	void FollowPlayer();

private:
	//std::shared_ptr<glm::vec3> position;
	//std::weak_ptr<glm::vec3> playerPosition;
	//glm::vec3 position;
	std::shared_ptr<glm::vec3> playerPosition;

	std::shared_ptr<Entity> player;
};

#endif // !CAMERAHANDLER_H

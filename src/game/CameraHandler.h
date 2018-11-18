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
	void LateUpdate();

	std::shared_ptr<StaticMeshCollider> staticMeshCollider;
	

private:
	std::weak_ptr<Entity> player;
	std::shared_ptr<MouseHandler> mouseInput;
	std::shared_ptr<KeyboardHandler> keyInput;

	std::shared_ptr<Transform> transform;
	glm::vec3 postition;
	std::shared_ptr<glm::vec3> cameraFront;

	void Movement();
	void Direction();
	void CheckCollision(glm::vec3 lastPosition, glm::vec3 newPosition);

	float speed;
	float lastMouseX;
	float lastMouseY;
	float offsetX;
	float offsetY;
	float mouseSensitivity;
	float yaw;
	float pitch;
	glm::vec3 newCameraFront;

	bool runOnce;

};

#endif // !CAMERAHANDLER_H

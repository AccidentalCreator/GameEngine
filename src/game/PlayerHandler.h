#ifndef PLAYERHANDLER_H
#define PLAYERHANDLER_H

#include "GameEngine\GameEngine.h"
#include "glm.hpp"
#include <memory>

class PlayerHandler : public Component
{
public:	
	void Awake();
	void Start();
	void Update();

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
	void Gravity();

	float speed;
	float lastMouseX;
	float lastMouseY;
	float offsetX;
	float offsetY;
	float mouseSensitivity;
	float yaw;
	float pitch;
	float groundPosition;
	float gravityStrength;
	glm::vec3 startPosition;
	glm::vec3 newCameraFront;

	bool jumping;
	bool jumpPeak;
	bool grounded;
	float maxJumpHeight;

	bool runOnce;

	void MovePlayerUp();
	void MovePlayerDown();

	bool sprinting;

};

#endif // !PLAYERHANDLER_H

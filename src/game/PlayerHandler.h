#ifndef PLAYERHANDLER_H
#define PLAYERHANDLER_H

#include "GameEngine\GameEngine.h"
#include "glm.hpp"
#include <memory>

using namespace GameEngine;

// Handles the player
class PlayerHandler : public Component
{
public:	
	// Initialisation
	void Awake();
	// Further variable initialisation
	void Start();
	// Runs through the players functions
	void Update();

	std::shared_ptr<StaticMeshCollider> staticMeshCollider;
	

private:
	std::weak_ptr<Entity> player;
	std::shared_ptr<MouseHandler> mouseInput;
	std::shared_ptr<KeyboardHandler> keyInput;

	std::shared_ptr<Transform> transform;
	glm::vec3 postition;
	std::shared_ptr<glm::vec3> cameraFront;

	// Checks for keyboard input and moves the player accordingly
	void Movement();
	// Checks the direction of the player
	void Direction();
	// Checks if the player is colliding with the static mesh
	void CheckCollision(glm::vec3 _lastPosition, glm::vec3 _newPosition); 
	// Pulls the player down to the mesh
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

	// Increments the players y coordinate if jumpped
	void MovePlayerUp();
	// Decreases the players y coordinate if the player is in the air
	void MovePlayerDown();

};

#endif // !PLAYERHANDLER_H

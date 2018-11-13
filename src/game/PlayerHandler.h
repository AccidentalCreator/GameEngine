#ifndef PLAYERHANDLER_H
#define PLAYERHANDLER_H

#include <memory>
#include <glm.hpp>
#include "GameEngine\GameEngine.h"

class PlayerHandler : public Component
{
public:
	void Start();
	void Awake();
	void Update();
	void Display();

	void GravitySim();
	
	void SetColliding(bool _colliding) { colliding = _colliding; }
	// delete after testing
	bool GetColliding() { return colliding; }

private:

	std::shared_ptr<KeyboardHandler> input;

	std::shared_ptr<glm::vec3> position;

	float speed;
	bool movementUp;
	bool movementDown;
	bool movementLeft;
	bool movementRight;
	bool colliding;


	void Movement();
	void CheckKeyRelease();

};

#endif // !PLAYERHANDLER_H

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

private:

	std::shared_ptr<KeyboardHandler> input;

	std::shared_ptr<glm::vec3> position;

	float speed;
	bool movementMade;

	void Movement();

};

#endif // !PLAYERHANDLER_H
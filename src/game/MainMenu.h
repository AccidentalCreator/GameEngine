#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include <GameEngine\GameEngine.h>

class MainMenu : public Component
{
public:
	void Start();
	void Update();

private:

	std::shared_ptr<Entity> startButton;

	glm::vec2 screenSize;
};

#endif // !MAINMENU_H

#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include <GameEngine\GameEngine.h>

using namespace GameEngine;

class Game;

class MainMenu : public Component
{
public:
	void Start();
	void Update();

private:

	std::shared_ptr<Entity> startButton;

	glm::vec2 screenSize;

	std::shared_ptr<Entity> game;
};

#endif // !MAINMENU_H

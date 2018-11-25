#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include <GameEngine\GameEngine.h>

using namespace GameEngine;

class Game;
// Handles and controls the main menu
class MainMenu : public Component
{
public:
	// Initialisation
	void Start();
	// Checks for any input
	void Update();

private:

	std::shared_ptr<Entity> startButton;
	std::shared_ptr<Entity> instuctions;

	glm::vec2 screenSize;

	std::shared_ptr<Entity> game;
};

#endif // !MAINMENU_H

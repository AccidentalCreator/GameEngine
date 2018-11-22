#pragma once
#ifndef GAME_H
#define GAME_H

#include <GameEngine\GameEngine.h>
#include <vector>
#include <memory>

using namespace GameEngine;

class Game : public Component
{
public:
	void StartGame();

	void Awake();
	void Start();
	
	void IncrementScore();

private:
	void LoadObjects();
	std::vector<glm::vec3> SetStarPositions();
	void CreateUIStar();
	void CallWinScreen();

	bool startGame;

	std::vector<std::shared_ptr<Entity>> uiStars;
	
	int score;
	int xOffset;
};

#endif // !GAME_H

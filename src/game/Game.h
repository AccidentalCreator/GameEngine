#pragma once
#ifndef GAME_H
#define GAME_H

#include <GameEngine\GameEngine.h>
#include <vector>
#include <memory>

class Game : public Component
{
public:
	void StartGame();
	void SetStarPositions();
	void CreateUIStar();
	void CallWinScreen();

	void Awake();
	void Start();
	void Update();
	
	void IncrementScore();

private:
	void LoadObjects();
	bool startGame;

	std::vector<std::shared_ptr<Entity>> stars;
	std::vector<std::shared_ptr<Entity>> uiStars;
	std::vector<glm::vec3> starPositions;
	std::vector<glm::vec3> uiStarPositions;

	int score;
	int xOffset;
};

#endif // !GAME_H

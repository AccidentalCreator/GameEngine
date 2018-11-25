#pragma once
#ifndef GAME_H
#define GAME_H

#include <GameEngine\GameEngine.h>
#include <vector>
#include <memory>

using namespace GameEngine;

// Handles and controlls the game 
class Game : public Component
{
public:
	// Starts the game
	void StartGame();
	// Initialises starting variable
	void Awake();
	// Further variable initialisation
	void Start();
	// Increases score
	void IncrementScore();

private:
	// Loads the objects into the scene
	void LoadObjects();
	// Sets the positon for the stars to spawn
	std::vector<glm::vec3> SetStarPositions();
	// Creates a new UI star when a star is collected
	void CreateUIStar();
	// Outputs the win screen when game is completed
	void CallWinScreen();

	bool startGame;

	std::vector<std::shared_ptr<Entity>> uiStars;
	
	int score;
	int xOffset;
};

#endif // !GAME_H

#include "Game.h"
#include "PickUpHandler.h"
#include "PlayerHandler.h"

#include <iostream>


void Game::Awake()
{
	startGame = false;
}

void Game::Start()
{
	if (startGame)
	{
		score = 0;
		SetStarPositions();
		LoadObjects();
		startGame = false;
		xOffset = 50;
	}
}

void Game::StartGame()
{
	startGame = true;
	Start();
}

void Game::LoadObjects()
{
	// Map 
	std::shared_ptr<Entity> level = GetCore()->AddEntity();
	std::shared_ptr<MeshRenderer> levelRenderer = level->AddComponent<MeshRenderer>("../resources/models/Map3.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	std::shared_ptr<StaticMeshCollider> meshCollider = level->AddComponent<StaticMeshCollider>();
	std::shared_ptr<Texture> levelTexture = level->AddComponent<Texture>("../resources/textures/MapTexture.png");
	level->GetComponent<Transform>()->SetTransform(glm::vec3(0, 0, 0), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));

	// Camera
	std::shared_ptr<Entity> camera = GetCore()->AddEntity();
	camera->SetTag("Player");
	camera->GetComponent<Transform>()->SetPosition(glm::vec3(0, 0, 1));
	camera->GetComponent<Transform>()->SetSize(glm::vec3(6, 15, 6));
	std::shared_ptr<Camera> cam = camera->AddComponent<Camera>();
	std::shared_ptr<PlayerHandler> cameraHandler = camera->AddComponent<PlayerHandler>();
	camera->GetComponent<PlayerHandler>()->staticMeshCollider = meshCollider;


	// Stars
	std::vector<std::shared_ptr<Entity>> stars;
	std::vector<glm::vec3> starPositions = SetStarPositions();
	for (int i = 0; i < starPositions.size(); i++)
	{
		std::shared_ptr<Entity> newStar = GetCore()->AddEntity();
		newStar->GetComponent<Transform>()->SetTransform(starPositions.at(i), 0.0f, glm::vec3(3.0f, 3.0f, 3.0f));
		std::shared_ptr<MeshRenderer> starRenderer = newStar->AddComponent<MeshRenderer>("../resources/models/star.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
		std::shared_ptr<Texture> starTexture = newStar->AddComponent<Texture>("../resources/textures/Yellow.png");
		std::shared_ptr<PickUpHandler> pickUpHandler = newStar->AddComponent<PickUpHandler>();
		stars.push_back(newStar);
	}
}

std::vector<glm::vec3> Game::SetStarPositions()
{
	std::vector<glm::vec3> starPositions;
	starPositions.push_back(glm::vec3(67, 6, -36));
	starPositions.push_back(glm::vec3(0, 40, 0));
	starPositions.push_back(glm::vec3(-50, 6, 42));
	starPositions.push_back(glm::vec3(-25, 6, -37));
	starPositions.push_back(glm::vec3(20, 25, -46));
	return starPositions;
}


void Game::IncrementScore()
{
	score++;
	CreateUIStar();
	if (score == 5)
	{
		CallWinScreen();
	}
}

void Game::CreateUIStar()
{
	glm::vec2 screenSize = GetCore()->GetScreen()->GetSize();
	std::shared_ptr<Entity> newStar = GetCore()->AddEntity();
	newStar->GetComponent<Transform>()->SetTransform(glm::vec3(20 + xOffset, screenSize.y - 70, 0), 0.0f, glm::vec3(30.0f, 30.0f, 0.0f));
	std::shared_ptr<Orthagraphic> starRenderer = newStar->AddComponent<Orthagraphic>("../resources/models/star.obj", "../resources/shaders/Ortho.vert", "../resources/shaders/Ortho.frag");
	std::shared_ptr<Texture> starTexture = newStar->AddComponent<Texture>("../resources/textures/Yellow.png");
	uiStars.push_back(newStar);
	xOffset += 80;
}

void Game::CallWinScreen()
{
	glm::vec2 screenSize = GetCore()->GetScreen()->GetSize();

	std::shared_ptr<Entity> winText = GetCore()->AddEntity();
	std::shared_ptr<Orthagraphic> winButtonRenderer = winText->AddComponent<Orthagraphic>("../resources/models/WinText.obj", "../resources/shaders/Ortho.vert", "../resources/shaders/Ortho.frag");
	std::shared_ptr<Texture> winTextTexture = winText->AddComponent<Texture>("../resources/textures/MissingTexture.png");
	winText->GetComponent<Transform>()->SetTransform(glm::vec3(screenSize.x / 2, screenSize.y / 2, 0), 0.0f, glm::vec3(100, 100, 0));
}


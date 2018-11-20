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

void Game::Update()
{
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
	std::shared_ptr<MeshRenderer> levelRenderer = level->AddComponent<MeshRenderer>();
	levelRenderer->AddModel("../resources/models/Map3.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	std::shared_ptr<StaticMeshCollider> meshCollider = level->AddComponent<StaticMeshCollider>();
	std::shared_ptr<Texture> levelTexture = level->AddComponent<Texture>();
	levelTexture->AddTexture("../resources/textures/MapTexture.png");
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
	for (int i = 0; i < starPositions.size(); i++)
	{
		std::shared_ptr<Entity> newStar = GetCore()->AddEntity();
		newStar->GetComponent<Transform>()->SetTransform(starPositions.at(i), 0.0f, glm::vec3(3.0f, 3.0f, 3.0f));
		std::shared_ptr<MeshRenderer> starRenderer = newStar->AddComponent<MeshRenderer>();
		starRenderer->AddModel("../resources/models/star.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
		std::shared_ptr<Texture> starTexture = newStar->AddComponent<Texture>();
		starTexture->AddTexture("../resources/textures/Yellow.png");
		std::shared_ptr<PickUpHandler> pickUpHandler = newStar->AddComponent<PickUpHandler>();
		stars.push_back(newStar);
	}
}

void Game::SetStarPositions()
{
	starPositions.push_back(glm::vec3(67, 6, -36));
	starPositions.push_back(glm::vec3(0, 40, 0));
	starPositions.push_back(glm::vec3(-50, 6, 42));
	starPositions.push_back(glm::vec3(-25, 6, -37));
	starPositions.push_back(glm::vec3(20, 25, -46));
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
	std::shared_ptr<Orthagraphic> starRenderer = newStar->AddComponent<Orthagraphic>();
	starRenderer->AddModel("../resources/models/star.obj", "../resources/shaders/Ortho.vert", "../resources/shaders/Ortho.frag");
	std::shared_ptr<Texture> starTexture = newStar->AddComponent<Texture>();
	starTexture->AddTexture("../resources/textures/Yellow.png");
	uiStars.push_back(newStar);
	xOffset += 80;
}

void Game::CallWinScreen()
{
	std::cout << "Winner" << std::endl;
}

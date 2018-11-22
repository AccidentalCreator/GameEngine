#include "MainMenu.h"
#include "Game.h"

#include <iostream>


void MainMenu::Start()
{
	screenSize = GetCore()->GetScreen()->GetSize();

	startButton = GetCore()->AddEntity();
	std::shared_ptr<Orthagraphic> startButtonRenderer = startButton->AddComponent<Orthagraphic>("../resources/models/PlayText.obj", "../resources/shaders/Ortho.vert", "../resources/shaders/Ortho.frag");
	//startButtonRenderer->AddOrtho("../resources/models/PlayText.obj", "../resources/shaders/Ortho.vert", "../resources/shaders/Ortho.frag");
	std::shared_ptr<Texture> startButtonTexture = startButton->AddComponent<Texture>("../resources/textures/MissingTexture.png");
	startButton->GetComponent<Transform>()->SetTransform(glm::vec3(screenSize.x / 2, screenSize.y / 2, 0), 0.0f, glm::vec3(100, 100, 0));
	std::shared_ptr<Button> button = startButton->AddComponent<Button>();
}

void MainMenu::Update()
{
	// Check Play button pressed
	if (startButton->GetComponent<Button>()->CheckClicked())
	{
		game = GetCore()->FindEntityWithComponent<Game>();
		game->GetComponent<Game>()->StartGame();
		startButton->Destroy();
		GetEntity()->Destroy();
	}
}
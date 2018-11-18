#include "MainMenu.h"

#include <iostream>

void MainMenu::Start()
{
	screenSize = GetCore()->GetScreen()->GetSize();

	startButton = GetCore()->AddEntity();
	std::shared_ptr<Orthagraphic> startButtonRenderer = startButton->AddComponent<Orthagraphic>();
	startButtonRenderer->AddOrtho("../resources/models/PlayText.obj", "../resources/shaders/Ortho.vert", "../resources/shaders/Ortho.frag");
	std::shared_ptr<Texture> startButtonTexture = startButton->AddComponent<Texture>();
	startButtonTexture->AddTexture("../resources/textures/WhiteCube.png");
	startButton->GetComponent<Transform>()->SetTransform(glm::vec3(screenSize.x / 2, screenSize.y / 2, 0), 0.0f, glm::vec3(100, 100, 0));
	std::shared_ptr<Button> button = startButton->AddComponent<Button>();
}

void MainMenu::Update()
{
	if (startButton->GetComponent<Button>()->CheckClicked())
	{
		startButton->Destroy();
		GetEntity()->Destroy();
	}
}
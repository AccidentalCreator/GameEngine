#include <GameEngine\GameEngine.h>
#include "MainMenu.h"
#include "Game.h"

#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<Core> core = Core::Initialize();

	// Main Menu
	std::shared_ptr<Entity> menu = core->AddEntity();
	std::shared_ptr<MainMenu> mainMenu = menu->AddComponent<MainMenu>();

	std::shared_ptr<Entity> game = core->AddEntity();
	game->SetTag("Game");
	std::shared_ptr<Game> gameHandler = game->AddComponent<Game>();
   
	//// Map 
	//std::shared_ptr<Entity> level = core->AddEntity();
	//std::shared_ptr<MeshRenderer> levelRenderer = level->AddComponent<MeshRenderer>();
	//levelRenderer->AddModel("../resources/models/Map3.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	//std::shared_ptr<StaticMeshCollider> meshCollider = level->AddComponent<StaticMeshCollider>();
	//std::shared_ptr<Texture> levelTexture = level->AddComponent<Texture>();
	//levelTexture->AddTexture("../resources/textures/MapTexture.png");
	//level->GetComponent<Transform>()->SetTransform(glm::vec3(0, 0, 0), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));

	//// Camera
	//std::shared_ptr<Entity> camera = core->AddEntity();
	//camera->SetTag("Player");
	//camera->GetComponent<Transform>()->SetPosition(glm::vec3 (0, 0, 1));
	//camera->GetComponent<Transform>()->SetSize(glm::vec3(6, 15, 6));
	//std::shared_ptr<Camera> cam = camera->AddComponent<Camera>();
	//std::shared_ptr<PlayerHandler> cameraHandler = camera->AddComponent<PlayerHandler>();
	//camera->GetComponent<PlayerHandler>()->staticMeshCollider = meshCollider;


	//std::shared_ptr<Entity> pickUp = core->AddEntity();
	//std::shared_ptr<MeshRenderer> pickUpMesh = pickUp->AddComponent<MeshRenderer>();
	//pickUpMesh->AddModel("../resources/models/Cube3.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	//pickUp->GetComponent<Transform>()->SetTransform(glm::vec3(0, 0, 0), 0.0f, glm::vec3(2.0f, 2.0f, 2.0f));
	//std::shared_ptr<Texture> pickUpTexture = pickUp->AddComponent<Texture>();
	//pickUpTexture->AddTexture("../resources/textures/WhiteCube.png");
	//std::shared_ptr<PickUpHandler> pickUpHandler = pickUp->AddComponent<PickUpHandler>();


	std::shared_ptr<Sound> sound = std::make_shared<Sound>("../resources/sounds/dixie_horn.ogg");
	//sound->Play();

	core->Start();


	return 0;
}

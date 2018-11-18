#include <GameEngine\GameEngine.h>
#include "CameraHandler.h"
#include "PickUpHandler.h"
#include "PlayerHandler.h"
#include "MainMenu.h"

#include <iostream>
#include <memory>

int main()
{

	std::shared_ptr<Core> core = Core::Initialize();

	// Main Menu
	std::shared_ptr<Entity> menu = core->AddEntity();
	std::shared_ptr<MainMenu> mainMenu = menu->AddComponent<MainMenu>();
   
	// Map 
	std::shared_ptr<Entity> level = core->AddEntity();
	std::shared_ptr<MeshRenderer> levelRenderer = level->AddComponent<MeshRenderer>();
	levelRenderer->AddModel("../resources/models/Map3.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	std::shared_ptr<StaticMeshCollider> meshCollider = level->AddComponent<StaticMeshCollider>();
	std::shared_ptr<Texture> levelTexture = level->AddComponent<Texture>();
	levelTexture->AddTexture("../resources/textures/MapTexture.png");
	level->GetComponent<Transform>()->SetTransform(glm::vec3(-100, -10, -50), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));

	// Camera
	std::shared_ptr<Entity> camera = core->AddEntity();
	camera->SetTag("Player");
	camera->GetComponent<Transform>()->SetPosition(glm::vec3 (0, 0, -1));
	camera->GetComponent<Transform>()->SetSize(glm::vec3(1, 1, 1));
	std::shared_ptr<Camera> cam = camera->AddComponent<Camera>();
	std::shared_ptr<CameraHandler> cameraHandler = camera->AddComponent<CameraHandler>();
	camera->GetComponent<CameraHandler>()->staticMeshCollider = meshCollider;


	//std::shared_ptr<Entity> player = core->AddEntity();
	//player->SetTag("Player");
	//player->GetComponent<Transform>()->SetTransform(glm::vec3(5, 0, 5), 0.0f, glm::vec3(1, 1, 1));
	//player->GetComponent<Transform>()->SetSize(glm::vec3(1, 2, 1));
	//std::shared_ptr<PlayerHandler> playerHandler = player->AddComponent<PlayerHandler>();
	//std::shared_ptr<MeshRenderer> playerRenderer = player->AddComponent<MeshRenderer>();
	//playerRenderer->AddModel("../resources/models/cat.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	//// Why doesnt this work!
	////std::shared_ptr<Texture> playerTexture = player->AddComponent<Texture>("../resources/textures/MissingTexture.png");
	//std::shared_ptr<Texture> playerTexture = player->AddComponent<Texture>();
	//playerTexture->AddTexture("../resources/textures/cat.png");


	std::shared_ptr<Entity> pickUp = core->AddEntity();
	std::shared_ptr<MeshRenderer> pickUpMesh = pickUp->AddComponent<MeshRenderer>();
	pickUpMesh->AddModel("../resources/models/Cube3.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	pickUp->GetComponent<Transform>()->SetTransform(glm::vec3(0, 0, 0), 0.0f, glm::vec3(2.0f, 2.0f, 2.0f));
	std::shared_ptr<Texture> pickUpTexture = pickUp->AddComponent<Texture>();
	pickUpTexture->AddTexture("../resources/textures/WhiteCube.png");
	std::shared_ptr<PickUpHandler> pickUpHandler = pickUp->AddComponent<PickUpHandler>();

	//std::shared_ptr<Entity> cat = core->AddEntity();
	//std::shared_ptr<MeshRenderer> catRenderer = cat->AddComponent<MeshRenderer>();
	//catRenderer->AddModel("../resources/models/cat.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	//std::shared_ptr<Texture> catTexture = cat->AddComponent<Texture>();
	//catTexture->AddTexture("../resources/textures/cat.png");
	//cat->GetComponent<Transform>()->SetTransform(glm::vec3(2, 0, 0), 180.0f, glm::vec3(1, 1, 1));

	//std::shared_ptr<Entity> cat2 = core->AddEntity();
	//std::shared_ptr<MeshRenderer> cat2Renderer = cat2->AddComponent<MeshRenderer>();
	//cat2Renderer->AddModel("../resources/models/cat.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	//std::shared_ptr<Texture> cat2Texture = cat2->AddComponent<Texture>();
	//cat2Texture->AddTexture("../resources/textures/cat.png");
	//cat2->GetComponent<Transform>()->SetTransform(glm::vec3(-1, 0, 0), 180.0f, glm::vec3(1, 1, 1));

	//std::shared_ptr<Entity> cat3 = core->AddEntity();
	//std::shared_ptr<Orthagraphic> cat3Renderer = cat3->AddComponent<Orthagraphic>();
	//cat3Renderer->AddModel("../resources/models/cube.obj", "../resources/shaders/Ortho.vert", "../resources/shaders/Ortho.frag");
	////std::shared_ptr<Material> material3 = cat3->AddComponent<Material>("../resources/textures/cat.png");
	//cat3->GetComponent<Transform>()->SetTransform(glm::vec3(580, 70, 0), 0.0f, glm::vec3(50, 50, 1));

	std::shared_ptr<Sound> sound = std::make_shared<Sound>("../resources/sounds/dixie_horn.ogg");
	//sound->Play();

	core->Start();


	return 0;
}

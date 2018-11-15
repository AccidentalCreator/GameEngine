#include <GameEngine\GameEngine.h>
#include "PlayerHandler.h"
#include "CameraHandler.h"
#include "FloorManager.h"
#include "FloorBlock.h" // Can deleted after testing

#include <iostream>
#include <memory>

int main()
{

	std::shared_ptr<Core> core = Core::Initialize();

	std::shared_ptr<Entity> camera = core->AddEntity();
	camera->GetComponent<Transform>()->SetPosition(glm::vec3 (0, 0, -10));
	std::shared_ptr<Camera> cam = camera->AddComponent<Camera>();
	std::shared_ptr<CameraHandler> cameraHandler = camera->AddComponent<CameraHandler>();
	//std::shared_ptr<Camera> cam = camera->AddComponent<Camera>(glm::vec3(0, 10, -20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	

	std::shared_ptr<Entity> GameHandler = core->AddEntity();
	std::shared_ptr<FloorManager> floorHandler = GameHandler->AddComponent<FloorManager>();

	//std::shared_ptr<Entity> player = core->AddEntity();
	//player->SetTag("Player");
	//player->GetComponent<Transform>()->SetTransform(glm::vec3(0, 1, 0), 0.0f, glm::vec3(1, 1, 1));
	//player->GetComponent<Transform>()->SetSize(glm::vec3(1, 2, 1));
	//std::shared_ptr<PlayerHandler> playerHandler = player->AddComponent<PlayerHandler>();
	//std::shared_ptr<MeshRenderer> playerRenderer = player->AddComponent<MeshRenderer>();
	//playerRenderer->AddModel("../resources/models/cat.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	//// Why doesnt this work!
	////std::shared_ptr<Texture> playerTexture = player->AddComponent<Texture>("../resources/textures/MissingTexture.png");
	//std::shared_ptr<Texture> playerTexture = player->AddComponent<Texture>();
	//playerTexture->AddTexture("../resources/textures/MissingTexture.png");
   


	std::shared_ptr<Entity> cat = core->AddEntity();
	std::shared_ptr<MeshRenderer> catRenderer = cat->AddComponent<MeshRenderer>();
	catRenderer->AddModel("../resources/models/cat.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	std::shared_ptr<Texture> catTexture = cat->AddComponent<Texture>();
	catTexture->AddTexture("../resources/textures/cat.png");
	cat->GetComponent<Transform>()->SetTransform(glm::vec3(2, 0, 0), 180.0f, glm::vec3(1, 1, 1));

	std::shared_ptr<Entity> cat2 = core->AddEntity();
	std::shared_ptr<MeshRenderer> cat2Renderer = cat2->AddComponent<MeshRenderer>();
	cat2Renderer->AddModel("../resources/models/cat.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	std::shared_ptr<Texture> cat2Texture = cat2->AddComponent<Texture>();
	cat2Texture->AddTexture("../resources/textures/cat.png");
	cat2->GetComponent<Transform>()->SetTransform(glm::vec3(-1, 0, 0), 180.0f, glm::vec3(1, 1, 1));

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

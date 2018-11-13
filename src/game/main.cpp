#include <GameEngine\GameEngine.h>
#include "PlayerHandler.h"
#include "CameraHandler.h"
// Include game engine

#include <iostream>
#include <memory>

int main()
{

	std::shared_ptr<Core> core = Core::Initialize();

	std::shared_ptr<Entity> camera = core->AddEntity();
	std::shared_ptr<Camera> cam = camera->AddComponent<Camera>(glm::vec3(9, 10, -20), glm::vec3(9, 0, 0), glm::vec3(0, 1, 0));
	//std::shared_ptr<Camera> cam = camera->AddComponent<Camera>(glm::vec3(0, 10, -20), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

	std::shared_ptr<CameraHandler> cameraHandler = camera->AddComponent<CameraHandler>();

	int noOfFloorTiles = 42;
	int x = 0;
	int z = -6;
	std::vector<std::shared_ptr<Entity>> floorTiles;
	for (int i = 0; i < noOfFloorTiles; i++)
	{
		std::shared_ptr<Entity> floorTile = core->AddEntity();
		std::shared_ptr<MeshRenderer> floorRenderer = floorTile->AddComponent<MeshRenderer>();
		floorRenderer->AddModel("../resources/models/Cube2.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
		floorTile->GetComponent<Transform>()->SetTransform(glm::vec3(x, 0, z), 0.0f, glm::vec3(1, 1, 1));
		std::shared_ptr<Material> floorMaterial = floorTile->AddComponent<Material>("../resources/textures/WhiteCube.png");
		floorTiles.push_back(floorTile);
		z += 3;
		if (z > 10)
		{
			z = -6;
			x += 3;
		}
	}

	std::shared_ptr<Entity> player = core->AddEntity();
	player->SetTag("Player");
	std::shared_ptr<PlayerHandler> playerHandler = player->AddComponent<PlayerHandler>();
	std::shared_ptr<MeshRenderer> playerRenderer = player->AddComponent<MeshRenderer>();
	playerRenderer->AddModel("../resources/models/Cube2.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	std::shared_ptr<Material> playerMaterial = player->AddComponent<Material>("../resources/textures/RedCube.png");
	player->GetComponent<Transform>()->SetTransform(glm::vec3(2, 1, 0), 0.0f, glm::vec3(1, 1, 1));



	//std::shared_ptr<Entity> cat = core->AddEntity();
	//std::shared_ptr<MeshRenderer> catRenderer = cat->AddComponent<MeshRenderer>();
	//catRenderer->AddModel("../resources/models/cat.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	//std::shared_ptr<Material> material = cat->AddComponent<Material>("../resources/textures/cat.png");
	//cat->GetComponent<Transform>()->SetTransform(glm::vec3(2, 0, 0), 180.0f, glm::vec3(1, 1, 1));

	//std::shared_ptr<Entity> cat2 = core->AddEntity();
	//std::shared_ptr<MeshRenderer> cat2Renderer = cat2->AddComponent<MeshRenderer>();
	//cat2Renderer->AddModel("../resources/models/cat.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	//std::shared_ptr<Material> material2 = cat2->AddComponent<Material>("../resources/textures/cat.png");
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

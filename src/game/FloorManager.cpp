#include "FloorManager.h"
#include "FloorBlock.h"

void FloorManager::Awake()
{
}

void FloorManager::Start()
{
	x = -5;
	z = 0;
	SpawnStartingFloor();
}

void FloorManager::Update()
{
}

void FloorManager::Display()
{
}

void FloorManager::SpawnFloor()
{
}

void FloorManager::SpawnStartingFloor()
{
	std::vector<std::shared_ptr<Entity>> floorTiles;
	for (int i = 0; i < noOfTiles; i++)
	{
		std::shared_ptr<Entity> floorTile = GetCore()->AddEntity();
		std::shared_ptr<MeshRenderer> floorRenderer = floorTile->AddComponent<MeshRenderer>();
		floorRenderer->AddModel("../resources/models/Cube2.obj", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
		floorTile->GetComponent<Transform>()->SetTransform(glm::vec3(x, 0, z), 0.0f, glm::vec3(1, 1, 1));
		floorTile->GetComponent<Transform>()->SetSize(glm::vec3(1, 1, 1));
		std::shared_ptr<Material> floorMaterial = floorTile->AddComponent<Material>("../resources/textures/WhiteCube.png");
		std::shared_ptr<FloorBlock> floorHandler = floorTile->AddComponent<FloorBlock>();
		floorHandler->SetCounter(i);
		floorTiles.push_back(floorTile);
		x += 5;
		if (x > 5)
		{
			x = -5;
			z += 5;
		}
	}
}

void FloorManager::RemoveFloor()
{
}

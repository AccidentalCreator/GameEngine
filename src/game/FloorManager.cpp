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
	std::cout << floorTiles.size() << std::endl;
	VectorCleanUp();
}

void FloorManager::Display()
{
}

void FloorManager::SpawnFloor()
{
}

void FloorManager::SpawnStartingFloor()
{
	for (int i = 0; i < noOfTiles; i++)
	{
		std::shared_ptr<Entity> floorTile = GetCore()->AddEntity();
		std::shared_ptr<MeshRenderer> floorRenderer = floorTile->AddComponent<MeshRenderer>();
//		floorRenderer->AddModel("../resources/models/Cube3.obj", "../resources/textures/CubeText.png", "../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
		floorTile->GetComponent<Transform>()->SetTransform(glm::vec3(x, 0, z), 0.0f, glm::vec3(2, 2, 2));
		floorTile->GetComponent<Transform>()->SetSize(glm::vec3(2, 2, 2));
		std::shared_ptr<Texture> floorMaterial = floorTile->AddComponent<Texture>();
		floorMaterial->AddTexture("../resources/textures/WhiteCube.png");
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

void FloorManager::VectorCleanUp()
{
	// Iterates through vector removing floor tiles
	for (size_t i = 0; i < floorTiles.size(); i++)
	{
		if (!floorTiles.at(i)->GetComponent<FloorBlock>()->GetIsAlive())
		{
			floorTiles.at(i)->Destroy();
			floorTiles.erase(floorTiles.begin() + i);
			i--;
		}
	}
}

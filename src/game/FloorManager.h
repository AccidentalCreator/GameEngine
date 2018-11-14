#pragma once
#ifndef FLOORMANAGER_H
#define FLOORMANAGER_H
#include <memory>

#include "GameEngine\GameEngine.h"

class FloorManager : public Component
{
public:
	void Awake();
	void Start();
	void Update();
	void Display();

private:
	void SpawnFloor();
	void SpawnStartingFloor();
	void RemoveFloor();
	void VectorCleanUp();

	int noOfTiles = 30;
	int x;
	int z;
	std::vector<std::shared_ptr<Entity>> floorTiles;
};

#endif // !FLOORMANAGER_H

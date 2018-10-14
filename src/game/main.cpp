#include <GameEngine\GameEngine.h>
// Include game engine

#include <iostream>
#include <memory>

class Player : public Component
{
public:
	void OnTick()
	{
		//std::cout << "Hello World" << std::endl;
	}
};

int main()
{

	std::shared_ptr<Core> core = std::make_shared<Core>(); // Gets core from engine
	core->Initialize();

	std::shared_ptr<Entity> triangle = core->AddEntity();
	std::shared_ptr<MeshRenderer> meshRenderer = triangle->AddComponent<MeshRenderer>();
	std::shared_ptr<Material> material = triangle->AddComponent<Material>();
	material->LoadTexture("../resources/textures/wall.jpg");

	core->Start();


	return 0;
}

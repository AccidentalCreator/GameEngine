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

	std::shared_ptr<Entity> cube = core->AddEntity();
	std::shared_ptr<MeshRenderer> meshRenderer = cube->AddComponent<MeshRenderer>();
	std::shared_ptr<Material> material = cube->AddComponent<Material>();
	material->LoadTexture("../resources/textures/wall.jpg");

	std::shared_ptr<Sound> sound = std::make_shared<Sound>("../resources/sounds/dixie_horn.ogg");
	sound->Play();

	core->Start();


	return 0;
}

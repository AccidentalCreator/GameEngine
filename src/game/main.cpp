//#include <GameEngine/Core.h>
//#include <GameEngine/Component.h>
//#include <GameEngine/Entity.h>
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

	core->Start();


	return 0;
}

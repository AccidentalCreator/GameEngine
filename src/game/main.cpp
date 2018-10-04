#include <GameEngine/Core.h>
#include <GameEngine/Component.h>
#include <GameEngine/Entity.h>
// Include game engine

#include <iostream>
#include <memory>

class Player : public Component
{
public:
	void OnTick()
	{
		std::cout << "Hello World" << std::endl;
	}
};

int main()
{

	std::shared_ptr<Core> core = std::make_shared<Core>(); // Gets core from engine

	std::shared_ptr<Entity> player = core->AddEntity();
	player->AddComponent<Player>();

	core->Start();

	std::cout << "Hello World" << std::endl;

	system("PAUSE");
	return 0;
}

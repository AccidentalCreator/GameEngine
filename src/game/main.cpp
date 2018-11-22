#include <GameEngine\GameEngine.h>
#include "MainMenu.h"
#include "Game.h"

#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<Core> core = Core::Initialize();

	// Main Menu
	std::shared_ptr<Entity> menu = core->AddEntity();
	std::shared_ptr<MainMenu> mainMenu = menu->AddComponent<MainMenu>();

	std::shared_ptr<Entity> game = core->AddEntity();
	game->SetTag("Game");
	std::shared_ptr<Game> gameHandler = game->AddComponent<Game>();

	//std::shared_ptr<Sound> sound = std::make_shared<Sound>("../resources/sounds/dixie_horn.ogg");
	//sound->Play();

	core->Start();


	return 0;
}

#include <GameEngine\GameEngine.h>
#include "MainMenu.h"
#include "Game.h"

#include <iostream>
#include <memory>

using namespace GameEngine;

int main()
{
	try
	{
		std::shared_ptr<Core> core = Core::Initialize();

		// Main Menu
		std::shared_ptr<Entity> menu = core->AddEntity();
		std::shared_ptr<MainMenu> mainMenu = menu->AddComponent<MainMenu>();

		std::shared_ptr<Entity> game = core->AddEntity();
		game->SetTag("Game");
		std::shared_ptr<Game> gameHandler = game->AddComponent<Game>();
		std::shared_ptr<Sound> backgroundSound = game->AddComponent<Sound>("../resources/sounds/BackgroundMusic.ogg");
		backgroundSound->Play();

		core->Start();
	}
	catch (Exception& e)
	{
		std::cout << "Game Engine Exception: " << e.What() << std::endl;
	}


	return 0;
}

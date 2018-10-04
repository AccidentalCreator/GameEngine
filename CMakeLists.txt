cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

add_executable(game
	src/game/main.cpp
)

add_library(GameEngine
	src/GameEngine/Core.h
	src/GameEngine/Environment.h
	src/GameEngine/Entity.h
	src/GameEngine/Keyboard.h
	src/GameEngine/Component.h

	src/GameEngine/Core.cpp
	src/GameEngine/Environment.cpp
	src/GameEngine/Entity.cpp
	src/GameEngine/Keyboard.cpp
	src/GameEngine/Component.cpp
)
	
target_link_libraries(game GameEngine)



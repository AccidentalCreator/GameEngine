cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

add_executable(jumper
	src/jumper/main.cpp
)

add_library(GameEngine
	src/GameEngine/Entity.cpp
)
	
target_link_libraries(jumper GameEngine)



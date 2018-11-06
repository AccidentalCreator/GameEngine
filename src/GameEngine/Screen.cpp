#include "Screen.h"

#include <iostream>
#include <gtx/transform.hpp>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

Screen::Screen()
{
}

Screen::~Screen()
{
	SDL_DestroyWindow(window);
}

void Screen::Init()
{
	window = SDL_CreateWindow("GameEngine",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);


	if (!SDL_GL_CreateContext(window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}

	

	// OpenGL windoow settings
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	projection = glm::perspective(glm::radians(45.0f), (float)(WINDOW_WIDTH / WINDOW_HEIGHT), 0.1f, 100.0f);
}

void Screen::Clear()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Screen::Update()
{

}

void Screen::End()
{
	SDL_GL_SwapWindow(window);
}
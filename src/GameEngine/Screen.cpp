#include "Screen.h"

#include <iostream>

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
}

void Screen::Clear()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Screen::Update()
{

}

void Screen::End()
{
	SDL_GL_SwapWindow(window);
}
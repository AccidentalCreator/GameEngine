#include <gtx/transform.hpp>

#include "Screen.h"


namespace GameEngine
{

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

		size.x = WINDOW_WIDTH;
		size.y = WINDOW_HEIGHT;

		if (!SDL_GL_CreateContext(window))
		{
			throw ("Could not create SDL Window");
		}

		if (glewInit() != GLEW_OK)
		{
			throw ("Glew Init failed");
		}

		// OpenGL windoow settings
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);

		// Locks mouse to window
		SDL_WarpMouseInWindow(window, size.x / 2, size.y / 2);
		//SDL_SetRelativeMouseMode(SDL_TRUE);
		SDL_CaptureMouse(SDL_TRUE);

		projection = glm::perspective(glm::radians(45.0f), (float)(WINDOW_WIDTH / WINDOW_HEIGHT), 0.1f, 500.0f);
	}

	void Screen::Clear()
	{
		glClearColor(0.21f, 0.31f, 0.36f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Screen::Update()
	{

	}

	void Screen::End()
	{
		SDL_GL_SwapWindow(window);
	}

}

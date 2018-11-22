#pragma once
#ifndef TEXT_H
#define TEXT_H

//#include <SDL_ttf.h>
#include <SDL2\SDL.h>

namespace GameEngine
{

	class Text
	{
	public:
		Text();
		~Text();

		void DrawText(char* myMessage, SDL_Rect& rect);

		void DrawText(const char* myMessage, SDL_Rect& rect);

	private:

		//TTF_Font* font; // Creates a font

	};

}
#endif // !TEXT_H

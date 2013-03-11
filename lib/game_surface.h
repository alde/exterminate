#pragma once

#include <SDL/SDL.h>

class GameSurface {
public:
	GameSurface();

	static SDL_Surface* load_image(char* file);

	static bool draw(SDL_Surface* dest, SDL_Surface* source, int x, int y);
	static bool draw(
		SDL_Surface* dest,
		SDL_Surface* source,
		int x,
		int y,
		int x2,
		int y2,
		int w,
		int h
	);
};
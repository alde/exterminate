#include "game_surface.h"

GameSurface::GameSurface() {

}

SDL_Surface* GameSurface::load_image(char* file) {
	SDL_Surface* temp = NULL;
	SDL_Surface* surf = NULL;

	if ((temp = SDL_LoadBMP(file)) == NULL) {
		return NULL;
	}

	surf = SDL_DisplayFormat(temp);
	SDL_FreeSurface(temp);

	return surf;
}

bool GameSurface::draw(SDL_Surface* dest, SDL_Surface* source, int x, int y) {
	if (dest == NULL || source == NULL) {
		return false;
	}

	SDL_Rect rect;

	rect.x = x;
	rect.y = y;

	SDL_BlitSurface(source, NULL, dest, &rect);

	return true;
}

bool GameSurface::draw(
	SDL_Surface* dest,	SDL_Surface* source, int x,	int y,	int x2,	int y2,
	int w,	int h
) {
	if (dest == NULL || source == NULL) {
		return false;
	}

	SDL_Rect dest_rect, src_rect;

	dest_rect.x = x;
	dest_rect.y = y;

	src_rect.x = x2;
	src_rect.y = y2;
	src_rect.w = w;
	src_rect.h = h;

	SDL_BlitSurface(source, &src_rect, dest, &dest_rect);

	return true;
}
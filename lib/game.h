#pragma once

#include "SDL/SDL.h"
#include "game_surface.h"

class Game {
public:
	Game() {
		m_background = NULL;
		m_test = NULL;
		m_running = true;
	}

	int start();

protected:
	bool init();
	void handle_event(SDL_Event* event);
	void loop();
	void render();
	void cleanup();

private:
	bool 			m_running;
	SDL_Surface* 	m_background;
	SDL_Surface*	m_test;
};
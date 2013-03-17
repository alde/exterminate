#pragma once

#include "SDL/SDL.h"
#include "game_event.h"
#include "game_surface.h"
#include <fstream>

#define MAX_HEALTH 10
#define TILE_SIZE 64

class Game : public GameEvent {
public:
	Game() {
		m_background = NULL;
		m_running = true;
		m_health = 4;
		m_healthbar = NULL;
	}

	int start();

protected:
	bool init();
	void handle_event(SDL_Event* event);
	void loop();
	void render();
	void renderMap(char* map);
	void cleanup();
	void doExit();
	void modHealth(int amount);

private:
	bool 			m_running;
	SDL_Surface* 	m_background;
	SDL_Surface* 	m_healthbar;
	int 			m_health;
};

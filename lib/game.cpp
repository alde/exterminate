#include "game.h"

bool Game::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) return false;

	m_background = SDL_SetVideoMode(
		1366, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN
	);

	if (m_background == NULL) return false;

	m_healthbar = GameSurface::load_image("media/dalek.bmp");
	if (m_healthbar == NULL) return false;

	return true;
}

void Game::handle_event(SDL_Event* event) {
	GameEvent::handle_event(event);
}

void Game::modHealth(int i) {
	if (m_health > 0 && (m_health < MAX_HEALTH || i < 0))
		m_health += i;

	if (m_health <= 0) {
		printf("Oh my god, you self-exterminated!\n");
		doExit();
	}
}

void Game::doExit() {
	m_running = false;
}

void Game::loop() {

}

void Game::renderMap() {
	SDL_Surface* sprite = NULL;
	char wall = '#', grass = '.';
	int x_pos = 0, y_pos = 0, c;
	FILE* fp;

	fp = fopen(m_currentMap, "r");
	while ((c = fgetc(fp)) != EOF) {
		if (c == wall)
			sprite = GameSurface::load_image("media/wall.bmp");
		else if (c == grass)
			sprite = GameSurface::load_image("media/grass.bmp");

		if (sprite != NULL)
			GameSurface::draw(m_background, sprite, x_pos, y_pos);

		if (c == '\n') x_pos = 0;
		else x_pos += TILE_SIZE;

		if (x_pos == 0) y_pos += TILE_SIZE;
	}
}

void Game::drawHealth() {
	for (int i = 0; i < m_health; i++)
		GameSurface::draw(m_background, m_healthbar, 15 + 50*i, 15);
}

void Game::render() {
	renderMap();
	drawHealth();

	SDL_Flip(m_background);
}

void Game::cleanup() {
	SDL_FreeSurface(m_background);
	SDL_FreeSurface(m_healthbar);

	SDL_Quit();
}

int Game::start() {
	if (init() == false) {
		return -1;
	}

	SDL_Event event;

	m_currentMap = "media/maps/map_01.emp";
	while (m_running) {
		while (SDL_PollEvent(&event)) {
			handle_event(&event);
		}

		loop();
		render();
	}

	cleanup();

	return 0;
}

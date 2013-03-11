#include "game.h"

bool Game::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	m_background = SDL_SetVideoMode(
		640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF
	);

	if (m_background == NULL) {
		return false;
	}

	m_test = GameSurface::load_image("dalek.bmp");
	if (m_test == NULL) {
		return false;
	}

	return true;
}

void Game::handle_event(SDL_Event* event) {
	if (event->type == SDL_QUIT) {
		m_running = false;
	}
}

void Game::loop() {

}

void Game::render() {
	GameSurface::draw(m_background, m_test, 0, 0);
	GameSurface::draw(m_background, m_test, 100, 100, 0, 0, 50, 50);

	SDL_Flip(m_background);
}

void Game::cleanup() {
	SDL_FreeSurface(m_test);
	SDL_FreeSurface(m_background);

	SDL_Quit();
}

int Game::start() {
	if (init() == false) {
		return -1;
	}

	SDL_Event event;

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

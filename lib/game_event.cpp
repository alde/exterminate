#include "game_event.h"

GameEvent::GameEvent() {

}

GameEvent::~GameEvent() {

}

void GameEvent::handle_event(SDL_Event* event) {
    switch(event->type) {
    case SDL_ACTIVEEVENT:
        switch(event->active.state) {
        case SDL_APPMOUSEFOCUS:
            if (event->active.gain) {
                mouse_focus();
            } else {
                mouse_blur();
            }
            break;
        case SDL_APPINPUTFOCUS:
            if (event->active.gain) {
                input_focus();
            } else {
                input_blur();
            }
            break;
        case SDL_APPACTIVE:
            if (event->active.gain) {
                restore();
            } else {
                minimize();
            }
            break;
        }
        break;
    case SDL_KEYDOWN:
        key_down(
            event->key.keysym.sym,
            event->key.keysym.mod,
            event->key.keysym.unicode
        );
        break;

    case SDL_KEYUP:
        key_up(
            event->key.keysym.sym,
            event->key.keysym.mod,
            event->key.keysym.unicode
        );
        break;

    case SDL_MOUSEMOTION:
        mouse_move(
            event->motion.x,
            event->motion.y,
            event->motion.xrel,
            event->motion.yrel,
            (event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
            (event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
            (event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0
        );
        break;

    case SDL_MOUSEBUTTONDOWN:
        switch(event->button.button) {
        case SDL_BUTTON_LEFT:
            left_button_down(
                event->button.x,
                event->button.y
            );
            break;

        case SDL_BUTTON_RIGHT:
            right_button_down(
                event->button.x,
                event->button.y
            );
            break;

        case SDL_BUTTON_MIDDLE:
            middle_button_down(
                event->button.x,
                event->button.y
            );
            break;
        }
        break;

    case SDL_MOUSEBUTTONUP:
        switch(event->button.button) {
        case SDL_BUTTON_LEFT:
            left_button_up(
                event->button.x,
                event->button.y
            );
            break;

        case SDL_BUTTON_RIGHT:
            right_button_up(
                event->button.x,
                event->button.y
            );
            break;

        case SDL_BUTTON_MIDDLE:
            middle_button_up(
                event->button.x,
                event->button.y
            );
            break;
        }
        break;

    case SDL_JOYAXISMOTION:
        joy_axis(
            event->jaxis.which,
            event->jaxis.axis,
            event->jaxis.value
        );
        break;

    case SDL_JOYBALLMOTION:
        joy_ball(
            event->jball.which,
            event->jball.ball,
            event->jball.xrel,
            event->jball.yrel
        );
        break;

    case SDL_JOYHATMOTION:
        joy_hat(
            event->jhat.which,
            event->jhat.hat,
            event->jhat.value
        );
        break;

    case SDL_JOYBUTTONDOWN:
        joy_button_down(
            event->jbutton.which,
            event->jbutton.button
        );
        break;

    case SDL_JOYBUTTONUP:
        joy_button_up(
            event->jbutton.which,
            event->jbutton.button
        );
        break;

    case SDL_QUIT:
        doExit();
        break;

    case SDL_SYSWMEVENT:
        // ignore
        break;

    case SDL_VIDEORESIZE:
        resize(
            event->resize.w,
            event->resize.h
        );
        break;

    case SDL_VIDEOEXPOSE:
        expose();
        break;

    default:
        user(
            event->user.type,
            event->user.code,
            event->user.data1,
            event->user.data2
        );
        break;
    }
}

void GameEvent::input_focus() {
    // placeholder
}

void GameEvent::input_blur() {
    // placeholder
}

void GameEvent::key_down(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
    case SDLK_ESCAPE:
        doExit();
        break;

    case SDLK_UP:
        modHealth(1);
        break;

    case SDLK_DOWN:
        modHealth(-1);
        break;

    default:
        break;
    }
}

void GameEvent::key_up(SDLKey sym, SDLMod mod, Uint16 unicode) {
    // placeholder
}

void GameEvent::mouse_focus() {
    // placeholder
}

void GameEvent::mouse_blur() {
    // placeholder
}

void GameEvent::mouse_move(int mX, int mY, int relX, int relY, bool left, bool right, bool middle) {
    // placeholder
}

void GameEvent::mouse_wheel(bool up, bool down) {
    // placeholder
}

void GameEvent::left_button_down(int mX, int mY) {
    // placeholder
}

void GameEvent::left_button_up(int mX, int mY) {
    // placeholder
}

void GameEvent::right_button_down(int mX, int mY) {
    // placeholder
}

void GameEvent::right_button_up(int mX, int mY) {
    // placeholder
}

void GameEvent::middle_button_down(int mX, int mY) {
    // placeholder
}

void GameEvent::middle_button_up(int mX, int mY) {
    // placeholder
}

void GameEvent::joy_axis(Uint8 which, Uint8 axis, Sint16 value) {
    // placeholder
}

void GameEvent::joy_button_down(Uint8 which, Uint8 button) {
    // placeholder
}

void GameEvent::joy_button_up(Uint8 which, Uint8 button) {
    // placeholder
}

void GameEvent::joy_hat(Uint8 which, Uint8 hat, Uint8 value) {
    // placeholder
}

void GameEvent::joy_ball(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel) {
    // placeholder
}

void GameEvent::minimize() {
    // placeholder
}

void GameEvent::restore() {
    // placeholder
}

void GameEvent::resize(int w, int h) {
    // placeholder
}

void GameEvent::expose() {
    // placeholder
}

void GameEvent::doExit() {
    // placeholder
}

void GameEvent::user(Uint8 type, int code, void* data1, void* data2) {
    // placeholder
}

void GameEvent::modHealth(int amount) {
    // placeholder
}

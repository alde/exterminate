#pragma once

#include <SDL/SDL.h>

class GameEvent {
public:
    GameEvent();

    virtual ~GameEvent();

    virtual void handle_event(SDL_Event* event);

    virtual void input_focus();

    virtual void input_blur();

    virtual void key_down(SDLKey sym, SDLMod mod, Uint16 unicode);

    virtual void key_up(SDLKey sym, SDLMod mod, Uint16 unicode);

    virtual void mouse_focus();

    virtual void mouse_blur();

    virtual void mouse_move(int mX, int mY, int relX, int relY, bool left, bool right, bool middle);

    virtual void mouse_wheel(bool up, bool down);

    virtual void left_button_down(int mX, int mY);

    virtual void left_button_up(int mX, int mY);

    virtual void right_button_down(int mX, int mY);

    virtual void right_button_up(int mX, int mY);

    virtual void middle_button_down(int mX, int mY);

    virtual void middle_button_up(int mX, int mY);

    virtual void joy_axis(Uint8 which, Uint8 axis, Sint16 value);

    virtual void joy_button_down(Uint8 which, Uint8 button);

    virtual void joy_button_up(Uint8 which, Uint8 button);

    virtual void joy_hat(Uint8 which, Uint8 hat, Uint8 value);

    virtual void joy_ball(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);

    virtual void minimize();

    virtual void restore();

    virtual void resize(int w, int h);

    virtual void expose();

    virtual void doExit();

    virtual void user(Uint8 type, int code, void* data1, void* data2);

    virtual void modHealth(int amount);
};

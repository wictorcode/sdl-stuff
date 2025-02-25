#pragma once
#include <stdio.h>
#include <SDL3/SDL.h>
#include "events/event_manager.h"
#include "player.h"
#include "events/inputs.h"

struct PlayerState {
    bool UP = false;
    bool DOWN = false;
    bool LEFT = false;
    bool RIGHT = false;
};

namespace Game { namespace Player {

    void initListeners();
    void update_position();
    void reset_position();
    void set_position(int x, int y);
    SDL_FRect* get_player_rectangle();

}}
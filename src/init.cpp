#include <SDL3/SDL.h>
#include "events/inputs.h"

void init_keybinds()
{
    // Engine::InputManager::initialize();
    Engine::InputManager::mapKeyToAction(ACTION_JUMP, SDLK_SPACE);
    Engine::InputManager::mapKeyToAction(ACTION_MOVE_UP, SDLK_UP);
    Engine::InputManager::mapKeyToAction(ACTION_MOVE_DOWN, SDLK_DOWN);
    Engine::InputManager::mapKeyToAction(ACTION_MOVE_LEFT, SDLK_LEFT);
    Engine::InputManager::mapKeyToAction(ACTION_MOVE_RIGHT, SDLK_RIGHT);
    Engine::InputManager::mapKeyToAction(ACTION_INTERACT, SDLK_E);
}

void init_all()
{
    init_keybinds();
}
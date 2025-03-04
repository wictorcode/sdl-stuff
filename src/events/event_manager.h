#include <SDL3/SDL.h>
#include <functional>
#include <vector>
#include <unordered_map>

namespace Engine {namespace Events  {
    void addEventListener(uint32_t type, std::function<void(const SDL_Event&)> callback);
    void addKeyListener(SDL_Keycode key, std::function<void(bool isDown)> callback);
    void removeKeyListener(SDL_Keycode key);
    void processEvents();
}}
#include <SDL3/SDL.h>
#include <functional>
#include <vector>
#include <unordered_map>

namespace engine {namespace events  {
    //== EVENT CALLBACKS ==//
    // basically a dictionnary where the key is the event type and the value is a list of functions to call
    // it's so simple that I struggled to get that right
    std::unordered_map<uint32_t, std::vector<std::function<void(const SDL_Event&)>>> listeners;
    
    //== KEY CALLBACKS ==//
    std::unordered_map<SDL_Keycode, std::vector<std::function<void()>>> keyListeners;
    
    void addEventListener(uint32_t type, std::function<void(const SDL_Event&)> callback) {
        listeners[type].push_back(callback);
    }

    void addKeyListener(SDL_Keycode key, std::function<void()> callback) {
        keyListeners[key].push_back(callback);
    }

    /* Example usage

    engine::events::addKeyListener(SDLK_SPACE, []() {
        printf("I clicked on the space key!\n");
    });

    */
    
    void processEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // key events
            if (event.type == SDL_EVENT_KEY_DOWN) {
                SDL_Keycode key = event.key.key;
                if (keyListeners.count(key) > 0) {
                    for (auto& callback : keyListeners[key]) {
                        callback();
                    }
                }
            }
            
            // other events
            if (listeners.count(event.type) > 0) {
                for (auto& callback : listeners[event.type]) {
                    callback(event);
                }
            }
        }
    }
}}
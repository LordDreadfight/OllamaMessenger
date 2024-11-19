#pragma once
#include <SDL2/SDL.h>

class UIElement {
public:
    virtual ~UIElement() = default;
    virtual void draw(SDL_Renderer* renderer) = 0;
    virtual void handleEvent(const SDL_Event& event) = 0;
};

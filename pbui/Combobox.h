#pragma once
#include "UIElement.h"
#include <functional>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

struct Combobox : public UIElement {
    int x, y, width, height;
    std::string text;
    bool isHovered;
    TTF_Font* font;
    std::vector<std::string>* dropdownList;
    bool dropdownListVisible;

    Combobox(int x, int y, int width, int height, const std::string& text);
    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& event) override;
    void addItem(const std::string& item);
    void removeItem(const std::string& item);
};
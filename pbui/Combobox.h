#pragma once
#include "UIElement.h"
#include <functional>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>

struct Combobox : public UIElement {
    Combobox(int x, int y, int width, int height, const std::vector<std::string>& options);
    void setOnSelectionChange(std::function<void(const std::string&)> callback);
    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& event) override;
    int x, y, width, height;
    std::vector<std::string> options; // List of options
    int selectedIndex;                // Index of the currently selected option
    bool isOpen;                      // Whether the dropdown is open
    std::function<void(const std::string&)> onSelectionChange;
    TTF_Font* font;
    void drawOption(SDL_Renderer* renderer, int index, int optionX, int optionY, int optionWidth, int optionHeight, bool isHovered);
};

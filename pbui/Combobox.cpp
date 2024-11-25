#include "Combobox.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

struct Combobox : public UIElement {
    int x, y, width, height;
    std::string text;
    bool isHovered;
    TTF_Font* font;
    std::vector<std::string>* dropdownList;
    bool dropdownListVisible;

    Combobox(int x, int y, int width, int height, const std::string& text)
        : x(x), y(y), width(width), height(height), text(text), isHovered(false) {
        font = TTF_OpenFont("Ubuntu-Regular.ttf", 14);
        if (!font) {
            std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        }
        // Initialize dropdown list
        dropdownList = new std::vector<std::string>();
        dropdownListVisible = false;
    }

    void draw(SDL_Renderer* renderer) override {
        // Draw combobox background
        SDL_Rect rect = { x, y, width, height };
        SDL_Color comboboxColor = isHovered ? SDL_Color{ 112, 220, 112, 255 } : SDL_Color{ 47, 211, 71, 255 };
        SDL_SetRenderDrawColor(renderer, comboboxColor.r, comboboxColor.g, comboboxColor.b, comboboxColor.a);
        SDL_RenderFillRect(renderer, &rect);

        // Draw text
        if (font) {
            SDL_Color textColor = { 255, 255, 255, 255 }; // White color for the text
            SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
            if (textSurface != nullptr) {
                SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                int textWidth = textSurface->w;
                int textHeight = textSurface->h;
                SDL_FreeSurface(textSurface);

                // Center the text within the combobox
                SDL_Rect textRect = { x + (width - textWidth) / 2, y + (height - textHeight) / 2, textWidth, textHeight };
                SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
                SDL_DestroyTexture(textTexture);
            }
        }

        // Draw dropdown arrow
        SDL_Rect arrowRect = { x + width - 20, y + (height - 20) / 2, 20, 20 };
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color for the arrow
        SDL_RenderFillRect(renderer, &arrowRect);
    }

    void handleEvent(const SDL_Event& event) override {
        if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
            int mouseX = event.motion.x;
            int mouseY = event.motion.y;
            bool inside = (mouseX > x && mouseX < x + width && mouseY > y && mouseY < y + height);

            if (inside) {
                isHovered = true;
                if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                    // Toggle dropdown list
                    if (dropdownListVisible) {
                        dropdownListVisible = false;
                    } else {
                        dropdownListVisible = true;
                    }
                }
            } else {
                isHovered = false;
            }
        }
    }

    void addItem(const std::string& item) {
        dropdownList->push_back(item);
    }

    void removeItem(const std::string& item) {
        // Implement removal logic
    }
};
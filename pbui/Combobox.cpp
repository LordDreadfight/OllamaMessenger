#include "Combobox.h"
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>

Combobox::Combobox(int x, int y, int width, int height, const std::string& text)
    : x(x), y(y), width(width), height(height), text(text), isHovered(false)
{
    font = TTF_OpenFont("Ubuntu-Regular.ttf", 14);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }
    // Initialize dropdown list
    dropdownList = new std::vector<std::string>();
    dropdownListVisible = false;
    onClick = [](const std::string& item) {}; // Default empty callback
}

void Combobox::draw(SDL_Renderer* renderer)
{
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
            SDL_Rect textRect = { x + (width - textWidth) / 2, y + (height - textHeight) / 2, textWidth, textHeight };
            SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
            SDL_DestroyTexture(textTexture);
        }
    }

    // Draw dropdown list if visible
    if (dropdownListVisible) {
        for (int i = 0; i < dropdownList->size(); i++) {
            SDL_Rect dropdownRect = { x, y + height + i * 20, width, 20 };
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &dropdownRect);

            // Draw dropdown text
            if (font) {
                SDL_Color dropdownTextColor = { 0, 0, 0, 255 }; // Black color for the text
                SDL_Surface* dropdownTextSurface = TTF_RenderText_Solid(font, (*dropdownList)[i].c_str(), dropdownTextColor);
                if (dropdownTextSurface != nullptr) {
                    SDL_Texture* dropdownTextTexture = SDL_CreateTextureFromSurface(renderer, dropdownTextSurface);
                    int dropdownTextWidth = dropdownTextSurface->w;
                    int dropdownTextHeight = dropdownTextSurface->h;
                    SDL_FreeSurface(dropdownTextSurface);

                    // Center the text within the dropdown
                    SDL_Rect dropdownTextRect = { x + (width - dropdownTextWidth) / 2, y + height + i * 20 + (20 - dropdownTextHeight) / 2, dropdownTextWidth, dropdownTextHeight };
                    SDL_RenderCopy(renderer, dropdownTextTexture, nullptr, &dropdownTextRect);
                    SDL_DestroyTexture(dropdownTextTexture);
                }
            }
        }
    }
}

void Combobox::handleEvent(const SDL_Event& event)
{
    if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX = event.motion.x;
        int mouseY = event.motion.y;
        bool inside = (mouseX > x && mouseX < x + width && mouseY > y && mouseY < y + height);

        if (inside) {
            isHovered = true;
            if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                dropdownListVisible = !dropdownListVisible;
            }
        } else {
            isHovered = false;
            dropdownListVisible = false;
        }

        // Handle dropdown list click
        if (dropdownListVisible) {
            for (int i = 0; i < dropdownList->size(); i++) {
                SDL_Rect dropdownRect = { x, y + height + i * 20, width, 20 };
                bool insideDropdown = (mouseX > dropdownRect.x && mouseX < dropdownRect.x + dropdownRect.w && mouseY > dropdownRect.y && mouseY < dropdownRect.y + dropdownRect.h);

                if (insideDropdown && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
                    onClick((*dropdownList)[i]);
                }
            }
        }
    }
}

void Combobox::addItem(const std::string& item)
{
    dropdownList->push_back(item);
    dropdownListVisible = true;
}

void Combobox::clearItems()
{
    dropdownList->clear();
    dropdownListVisible = false;
}

void Combobox::addItems(const std::vector<std::string>& items)
{
    for (const auto& item : items) {
        addItem(item);
    }
}
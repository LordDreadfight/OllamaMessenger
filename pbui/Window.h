#pragma once
#include <SDL2/SDL.h>
#include <vector>

class UIElement;

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();

    void addElement(UIElement* element);
    void mainLoop();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;

    std::vector<UIElement*> elements;

    void handleEvents();
    void render();
};

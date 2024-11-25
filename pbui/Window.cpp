#include "Window.h"
#include "UIElement.h"

Window::Window(const char* title, int width, int height)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    running = true;
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::addElement(UIElement* element)
{
    elements.push_back(element);
}

void Window::handleEvents()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
        for (auto& element : elements) {
            element->handleEvent(event);
        }
    }
}

void Window::render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (auto& element : elements) {
        element->draw(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Window::mainLoop()
{
    while (running) {
        handleEvents();
        render();
        SDL_Delay(16); // ~60 FPS
    }
}

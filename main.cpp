#include "pbui/Button.h"
#include "pbui/UIElement.h"
#include "pbui/Window.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "pbollama/OllamaFunction.h"
#include "pbui/Combobox.h"
#include "pbui/Label.h"
#include <vector>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    Window window("Ollama Messenger", 1280, 720);
    Button button(10, 10, 150, 50, "Start ollama Server");
    button.setOnClick([]() {
        startOllamaService();
    });
    Button button2(10, 70, 150, 50, "Button that definitely does something");
    button2.setOnClick([]() {
        saveOllamaModel();
    });
    button2.setTooltip("Starts nothing currently");

    std::vector<std::string> itemslist = {"test","stest","test3"};
    Combobox combi(170, 30, 250, 50, itemslist);
    Label fabel(170, 5, 250, 25, "Des is a combobox mit label drüber");
    window.addElement(&combi);
    window.addElement(&fabel);
    window.addElement(&button2);
    window.addElement(&button);
    window.mainLoop();
    TTF_Quit();
    SDL_Quit();
    return 0;
}
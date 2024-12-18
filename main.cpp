#include "pbui/Button.h"
#include "pbui/UIElement.h"
#include "pbui/Window.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "pbollama/OllamaFunction.h"
#include "pbui/Combobox.h"
#include "pbui/Label.h"
#include "pbui/TextInput.h"
#include "pbui/Listbox.h"
#include <vector>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" );
    Window window("Ollama Messenger", 1280, 720);
    Button button(10, 10, 150, 50, "Start ollama Server");
    button.setOnClick([]() {});
    Button button2(10, 70, 150, 50, "Button mit funktion");
    button2.setOnClick([]() {
        //SaveSetting("yuck","fou");
    });
    button2.setTooltip("Starts nothing currently");

    std::vector<std::string> itemslist = {"test","stest","test3"};
    Combobox combi(170, 10, 250, 50, itemslist);
    TextInput textinput(170, 70, 250, 50);
    textinput.setPlaceholder("Type message here....");
    
    
    window.addElement(&combi);
    window.addElement(&textinput);
    window.addElement(&button2);
    window.addElement(&button);
    window.mainLoop();
    TTF_Quit();
    SDL_Quit();
    return 0;
}
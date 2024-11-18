#include <iostream>
#include "ollama.hpp"
#include "pbui/Button.h"
#include "pbui/Window.h"
#include "pbui/UIElement.h"


int main(int argc, char* argv[]) {

    Window window("Basic UI Library", 800, 600);

    Button button(100, 100, 150, 50, "Click Me");
    button.setOnClick([]() {
        printf("Button Clicked!\n");
    });

    window.addElement(&button);
    window.mainLoop();

    return 0;
}

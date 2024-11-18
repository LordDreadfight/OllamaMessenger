#include "UIElement.h"
#include <functional>
#include <string>

class Button : public UIElement {
public:
    Button(int x, int y, int width, int height, const std::string& text);
    void setOnClick(std::function<void()> callback);

    void draw(SDL_Renderer* renderer) override;
    void handleEvent(const SDL_Event& event) override;

private:
    int x, y, width, height;
    std::string text;
    std::function<void()> onClick;
    bool isHovered;
};

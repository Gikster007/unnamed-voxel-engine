#include "app.h"

#include "../window/window.h"

void App::init(Window* _window, bool* _keys)
{
    window = _window;
    keys = _keys;
}

void App::update(float dt)
{
    if (keys[GLFW_KEY_ESCAPE])
        window->open = false;
}

void App::shutdown()
{
    
}
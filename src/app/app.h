#pragma once

class Window;

class App
{
  public:
    App() = default;
    ~App() = default;

    void init(Window* _window, bool* _keys);
    void update(float dt);
    void shutdown();

  private:
    bool* keys = nullptr;
    Window* window = nullptr;
};
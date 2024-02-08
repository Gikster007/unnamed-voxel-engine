#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include <atomic>

class Window
{
  public:
    Window(int w, int h, const char* title);
    ~Window();

    void set_vsync(bool on);
    void swap_buffers();

  public:
    int w = 0;
    int h = 0;

    std::atomic_bool open;

    GLFWwindow* glfw_window = nullptr;
};
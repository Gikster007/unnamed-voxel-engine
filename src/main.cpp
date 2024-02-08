#include <iostream>

#include <glad/glad.h>

#include "window/window.h"
#include "app/app.h"

bool keys[512] = {false};
bool buttons[3] = {false};
double mouse_x = 0.0, mouse_y = 0.0;
float deltaTime = 0.0f;

static void key_callback(GLFWwindow* _window, int key, int, int action, int)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(_window, true);
    if (key >= 0 && key < 512)
    {
        if (action == GLFW_PRESS)
            keys[key] = true;
        else if (action == GLFW_RELEASE)
            keys[key] = false;
    }
}

static void mouse_button_callback(GLFWwindow*, int button, int action, int)
{
    if (action == GLFW_PRESS)
        buttons[button] = true;
    else if (action == GLFW_RELEASE)
        buttons[button] = false;
}

int main()
{
    Window window = Window(WIN_WIDTH, WIN_HEIGHT, "Unnamed Voxel Engine");
    window.set_vsync(true);

    App app;
    app.init(&window, keys);

    glfwSetKeyCallback(window.glfw_window, key_callback);
    glfwSetMouseButtonCallback(window.glfw_window, mouse_button_callback);

    glViewport(0, 0, window.w, window.h);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    deltaTime = 0;
    double last_frame = 0;
    bool debug_draw = false;

    while (window.open)
    {
        glfwGetCursorPos(window.glfw_window, &mouse_x, &mouse_y);

        double curr_frame = glfwGetTime();
        deltaTime = static_cast<float>(curr_frame - last_frame);
        last_frame = curr_frame;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        app.update(deltaTime);

        window.swap_buffers();
        glfwPollEvents();
    }

    app.shutdown();
}
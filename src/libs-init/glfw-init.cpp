#include "glfw-init.h"

#include <stdio.h>

static void error_callback(int , const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

GLFWwindow* glfw_init(int w, int h, const char* title)
{
    // Init GLFW
    if (!glfwInit())
    {
        printf("GLFW Failed To Initialise \n");
        return nullptr;
    }

    // Set Error Callback
    glfwSetErrorCallback(error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    GLFWwindow* window = glfwCreateWindow(w, h, title, NULL, NULL);
    if (!window)
    {
        printf("GLFW Window Failed To Initialise \n");
        return nullptr;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGL())
    {
        printf("Failed to initialize GLAD! \n");
        return nullptr;
    }  

    return window;
}

void glfw_close(GLFWwindow* window)
{
    glfwDestroyWindow(window);
}

void glfw_vsync(int rate)
{
    glfwSwapInterval(rate);
}

void glfw_swap_buffers(GLFWwindow* window)
{
    glfwSwapBuffers(window);
}
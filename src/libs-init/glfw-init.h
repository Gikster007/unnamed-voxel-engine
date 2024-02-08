#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

GLFWwindow* glfw_init(int w, int h, const char* title);

void glfw_close(GLFWwindow* window);
void glfw_vsync(int rate);
void glfw_swap_buffers(GLFWwindow* window);
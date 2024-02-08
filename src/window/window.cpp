#include "window.h"

#include <stdio.h>

#include "../libs-init/glfw-init.h"

Window::Window(int w, int h, const char* title)
{
	this->w = w;
	this->h = h;

	glfw_window = glfw_init(w, h, title);
	open = true;
}

Window::~Window()
{
	glfw_close(glfw_window);
}

void Window::set_vsync(bool on)
{
	glfw_vsync(on);
}

void Window::swap_buffers()
{
	glfw_swap_buffers(glfw_window);
}
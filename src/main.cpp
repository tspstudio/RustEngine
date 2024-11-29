#include <iostream>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "Events.hpp"

#define WIDTH 1280
#define HEIGHT 720

int main() {
    Window::initalize(WIDTH, HEIGHT, "Window");
    Events::initialize();

    glClearColor(1, 1, 0, 1);

    while (!Window::isShouldClose()) {
        Events::pollEvents();

        if (Events::jpressed(GLFW_KEY_ESCAPE)) {
            Window::setShouldClose(true);
        }

        if (Events::jclicked(GLFW_MOUSE_BUTTON_1)) {
            glClearColor(1, 0, 0, 1);
        }

        glClear(GL_COLOR_BUFFER_BIT);

        Window::swapBuffers();
    }

    Window::terminate();
    return 0;
}
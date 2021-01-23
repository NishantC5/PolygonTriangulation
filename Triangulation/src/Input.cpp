#include "../headers/pch.h"
#include "../headers/Input.h"
#include "../headers/Transformations.h"

void Input::SetGLFWCallbacks(GLFWwindow* window) {
    glfwSetMouseButtonCallback(window, LeftClick);
}

void Input::LeftClick(GLFWwindow* window, int button, int action, int mods) {
    if ((button == GLFW_MOUSE_BUTTON_LEFT) && action == GLFW_PRESS) {
        double xpos, ypos, xogl, yogl;
        glfwGetCursorPos(window, &xpos, &ypos);
        Transformations::PixelToOpenGL(window, xpos, ypos, &xogl, &yogl);
        std::cout << xogl << "," << yogl << "\n";
    }
}
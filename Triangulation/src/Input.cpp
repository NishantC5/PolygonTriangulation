#include "../headers/pch.h"
#include "../headers/Input.h"

void Input::SetGLFWCallbacks(GLFWwindow* window) {
    glfwSetMouseButtonCallback(window, LeftClick);
}

void Input::LeftClick(GLFWwindow* window, int button, int action, int mods) {
    if ((button == GLFW_MOUSE_BUTTON_LEFT) && action == GLFW_PRESS) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos);
        std::cout << xpos << "," << ypos << "\n";
    }
}
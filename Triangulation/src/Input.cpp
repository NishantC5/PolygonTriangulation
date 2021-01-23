#include "../headers/pch.h"
#include "../headers/Input.h"
#include "../headers/Transformations.h"

int Input::oldState = GLFW_RELEASE;
double Input::leftClickx = 0;
double Input::leftClicky = 0;
void Input::SetGLFWCallbacks(GLFWwindow* window) {
    glfwSetMouseButtonCallback(window, LeftClick);
}

void Input::LeftClick(GLFWwindow* window, int button, int action, int mods) {
    if ((button == GLFW_MOUSE_BUTTON_LEFT) && action == GLFW_PRESS) {
        double xpos, ypos, xogl, yogl;
        glfwGetCursorPos(window, &xpos, &ypos);
        Transformations::PixelToOpenGL(window, xpos, ypos, &xogl, &yogl);
        Input::leftClickx = xogl;
        Input::leftClicky = yogl;
    }
}
bool Input::DetectLeftClick(GLFWwindow* window) {
    int newState = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
    if (newState == GLFW_RELEASE && oldState == GLFW_PRESS) {
        Input::oldState = newState;
        return true;
    }
    else {
        Input::oldState = newState;
        return false;
    }
}

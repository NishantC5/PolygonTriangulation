#pragma once
#include "../headers/pch.h"
class Input {
public:
	static void SetGLFWCallbacks(GLFWwindow* window);
private:
	static void LeftClick(GLFWwindow* window, int button, int action, int mods);
};
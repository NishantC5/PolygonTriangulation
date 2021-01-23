#pragma once
#include "../headers/pch.h"
class Input {
public:
	// x and y coordinates of the previous left click that has been performed
	static double leftClickx, leftClicky;
	static void SetGLFWCallbacks(GLFWwindow* window);
	static bool DetectLeftClick(GLFWwindow* window);
	
private:
	static int oldState;
	static void LeftClick(GLFWwindow* window, int button, int action, int mods);
};
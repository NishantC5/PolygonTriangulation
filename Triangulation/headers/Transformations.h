#pragma once
#include "../headers/pch.h"

class Transformations {
public:
	// Given the pixel coordinates for the window, it transforms it to opengl coordinates
	static void PixelToOpenGL(GLFWwindow* window, int x, int y, double* xogl, double* yogl);
};

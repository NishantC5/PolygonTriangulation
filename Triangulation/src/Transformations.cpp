#include "../headers/pch.h"
#include "../headers/Transformations.h"

void Transformations::PixelToOpenGL(GLFWwindow* window, int x, int y, double* xogl, double* yogl) {
	int w, h;
	glfwGetWindowSize(window, &w, &h);
	glm::mat4 T1;
	T1[0] = glm::vec4(1, 0, 0, 0);
	T1[1] = glm::vec4(0, -1, 0, 0);
	T1[2] = glm::vec4(0, 0, 1, 0);
	T1[3] = glm::vec4(0, 0, 0, 1);
	glm::mat4 T2;
	T2[0] = glm::vec4(1, 0, 0, 0);
	T2[1] = glm::vec4(0, 1, 0, 0);
	T2[2] = glm::vec4(0, 0, 1, 0);
	T2[3] = glm::vec4(-(double)w / 2, (double)h / 2, 0, 1);
	glm::mat4 T3;
	T3[0] = glm::vec4(2/ (double)w, 0, 0, 0);
	T3[1] = glm::vec4(0, 2/ (double)h, 0, 0);
	T3[2] = glm::vec4(0, 0, 1, 0);
	T3[3] = glm::vec4(0, 0, 0, 1);
	glm::vec4 pixelPoint = glm::vec4((double)x, (double)y, 0, 1);
	glm::vec4 oGLPoint = T3 * T2 * T1 * pixelPoint;
	*xogl = oGLPoint.x;
	*yogl = oGLPoint.y;
}
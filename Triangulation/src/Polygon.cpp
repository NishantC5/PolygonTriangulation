#include "../headers/pch.h"
#include "../headers/Polygon.h"

#define MAX_NO_OF_VERTICES 1000

Polygon::Polygon() {
	// Allocating memory for storing the vertex information
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 2 * MAX_NO_OF_VERTICES * sizeof(double), NULL, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE, sizeof(double) * 2, 0);
}
void Polygon::AddVertex(double x, double y) {
	try {
		if (points.size() == MAX_NO_OF_VERTICES)
			throw 0;
	}
	catch (int num) {
		std::cout << "Error " << num << ": Cannot add more vertices as number of vertices eexceeds the allocated space for this polygon";
		return;
	}
	double coordinates[] = { x,y };
	glBufferSubData(GL_ARRAY_BUFFER, points.size() * 2 * sizeof(double),
		2 * sizeof(double), coordinates);

	points.push_back(glm::vec2(x, y));
}
void Polygon::RenderPolygon() {
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glDrawArrays(GL_LINE_LOOP, 0, points.size());
}
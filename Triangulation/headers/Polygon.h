#pragma once
#include "../headers/pch.h"
class Polygon {
public :		
	/// <summary>
	/// Creates a polygon who can have at max n vertices
	/// </summary>
	Polygon();
	
	/// <summary>
	/// Adds a vertex with x, y coordinates into the polygon
	/// </summary>
	void AddVertex(double x, double y);
	
	/// <summary>
	/// Renders the polygon.
	/// </summary>
	void RenderPolygon();
	
private:
	std::vector<glm::vec2> points;
	GLuint buffer;
};
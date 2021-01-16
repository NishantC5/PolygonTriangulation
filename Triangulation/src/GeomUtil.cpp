#include "../headers/pch.h"
#include "../headers/GeomUtil.h"

/// <summary>
/// Checks the orientation of ordered set of points. -1 : CCW; 1 : CW; 0 : Colinear
/// </summary>
/// <param name="points">The points.</param>
/// <returns></returns>
int GeomUtil::CheckOrientation(std::vector<glm::vec2> points) {
	double sum = 0;
	int size = points.size();
	for (int i = 0; i < size; i++) {
		sum += (points.at((i + 1) % size).x - points.at(i % size).x) *
			(points.at((i + 1) % size).y + points.at(i % size).y);
	}
	if (sum < 0)
		return -1;
	else if (sum > 0)
		return 1;
	else
		return 0;
}
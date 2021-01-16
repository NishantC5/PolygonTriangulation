#pragma once
#include "../headers/pch.h"
class GeomUtil
{
public:
	/// <summary>
/// Checks the orientation of ordered set of points. -1 : CCW; 1 : CW; 0 : Colinear
/// </summary>
/// <param name="points">The points.</param>
/// <returns></returns>
	static int CheckOrientation(std::vector<glm::vec2> points);

};
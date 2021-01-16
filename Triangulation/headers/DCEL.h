#pragma once
#include "../headers/pch.h"
#include "HalfEdgeDCEL.h"
class DCEL {
public:
	std::vector<HalfEdgeDCEL*> E;
	std::vector<FaceDCEL*> F;
	std::vector<VertexDCEL*> V;
	DCEL(std::vector<glm::vec2> points);
};
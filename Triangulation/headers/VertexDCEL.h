#pragma once
#include "../headers/pch.h"
class HalfEdgeDCEL;
class VertexDCEL {
public:
	glm::vec2 V;
	HalfEdgeDCEL* incidentEdge;
	VertexDCEL(glm::vec2 point);
};
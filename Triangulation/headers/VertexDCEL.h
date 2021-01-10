#pragma once
#include <glm/glm/glm.hpp>
#include "HalfEdgeDCEL.h"
class VertexDCEL {
public:
	glm::vec2 V;
	HalfEdgeDCEL* incidentEdge;
	VertexDCEL(glm::vec2 point);
};
#pragma once
#include <glm/glm/glm.hpp>
class HalfEdgeDCEL;
class VertexDCEL {
public:
	glm::vec2 V;
	HalfEdgeDCEL* incidentEdge;
	VertexDCEL(glm::vec2 point);
};
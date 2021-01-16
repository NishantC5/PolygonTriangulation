#include "../headers/pch.h"
#include "../headers/VertexDCEL.h"

VertexDCEL::VertexDCEL(glm::vec2 point) {
	V = point;
	incidentEdge = nullptr;
}
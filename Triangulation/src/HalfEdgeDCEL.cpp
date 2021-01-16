#include "../headers/pch.h"
#include "../headers/HalfEdgeDCEL.h"

HalfEdgeDCEL::HalfEdgeDCEL() {
	prev = nullptr;
	next = nullptr;
	twin = nullptr;
	incidentFace = nullptr;
	origin = nullptr;
}
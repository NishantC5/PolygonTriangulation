#pragma once
#include "VertexDCEL.h"
#include "FaceDCEL.h"
class HalfEdgeDCEL {
public:
	HalfEdgeDCEL* next;
	HalfEdgeDCEL* prev;
	HalfEdgeDCEL* twin;
	VertexDCEL* origin;
	FaceDCEL* incidentFace;
	HalfEdgeDCEL();
};
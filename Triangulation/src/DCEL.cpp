#include "../headers/pch.h"
#include "../headers/DCEL.h"
#include "../headers/GeomUtil.h"

DCEL::DCEL(std::vector<glm::vec2> points) {

	// Making the points to be CCW
	int orientation = GeomUtil::CheckOrientation(points);
	if (orientation == 1)
		std::reverse(points.begin(),points.end());
	HalfEdgeDCEL* prevLeftEdge = nullptr;
	HalfEdgeDCEL* prevRightEdge = nullptr;
	FaceDCEL* f = new FaceDCEL();
	for (auto itr = points.begin(); itr != points.end(); ++itr) {
		HalfEdgeDCEL* left = new HalfEdgeDCEL();
		HalfEdgeDCEL* right = new HalfEdgeDCEL();

		VertexDCEL* vertex = new VertexDCEL(*itr);
		vertex->incidentEdge = left;
		V.push_back(vertex);
		
		left->origin = vertex;
		left->twin = right;
		left->prev = prevLeftEdge;
		left->next = nullptr;
		left->incidentFace = f;

		right->origin = nullptr;
		right->twin = left;
		right->next = prevRightEdge;
		right->prev = nullptr;
		right->incidentFace = nullptr;

		E.push_back(left);
		E.push_back(right);

		if (prevLeftEdge != nullptr) {
			prevLeftEdge->next = left;
		}
		if (prevRightEdge != nullptr) {
			prevRightEdge->origin = vertex;
			prevRightEdge->prev = right;
		}
		prevLeftEdge = left;
		prevRightEdge = right;
	}
	HalfEdgeDCEL* firstleft = E.front();
	prevLeftEdge->next = firstleft;
	firstleft->prev = prevLeftEdge;

	HalfEdgeDCEL* firstright = *(E.begin() + 1);
	prevRightEdge->prev = firstright;
	prevRightEdge->origin = V.front();
	firstright->next = prevRightEdge;

	f->incidentEdge = firstleft;
	F.push_back(f);
}
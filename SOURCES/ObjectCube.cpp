#include "ObjectCube.h"

ObjectCube::ObjectCube(const Vector3f& p, float width, float height, float depth, const Color& c) {
	p_vertex = Vector3f();
	scale(Vector3f(width, height, depth));
	translation(p);
	
	p_color = c;

	p_bounding_box = 
		std::pair<Vector3f, Vector3f>(p_vertex - Vector3f(0.5, 0.5, 0.5),
									  p_vertex + Vector3f(0.5, 0.5, 0.5));
}

void ObjectCube::onDraw() const{
	glColor4f(p_color.r, p_color.g, p_color.b, 1.0f);
	glutSolidCube(1);
}

#include "ObjectSphere.h"

ObjectSphere::ObjectSphere(const Vector3f& p, float radio, int faces, const Color& c) {
	p_vertex = Vector3f();
	p_radio = radio;
	p_faces = faces;
	translation(p);
	
	p_color = c;

	p_bounding_box = 
		std::pair<Vector3f, Vector3f>(p_vertex - Vector3f(p_radio, p_radio, p_radio),
									  p_vertex + Vector3f(p_radio, p_radio, p_radio));
}

void ObjectSphere::onDraw() const{
	glColor4f(p_color.r, p_color.g, p_color.b, 1.0f);
	glutSolidSphere(p_radio, p_faces, p_faces);
}

#include "ObjectCone.h"

ObjectCone::ObjectCone(const Vector3f& p, float radio, float height, int faces, const Color& c) {
	p_vertex = Vector3f();
	p_radio = radio;
	p_height = height;
	p_faces = faces;
	translation(p+Vector3f(0,0,p_height/2.0f));
	
	p_color = c;

	p_bounding_box = 
		std::pair<Vector3f, Vector3f>(p_vertex - Vector3f(p_radio, p_radio, 0),
									  p_vertex + Vector3f(p_radio, p_radio, p_height));
}

void ObjectCone::onDraw() const{
	glColor4f(p_color.r, p_color.g, p_color.b, 1.0f);
	glutSolidCone(p_radio, p_height, p_faces, p_faces);
}

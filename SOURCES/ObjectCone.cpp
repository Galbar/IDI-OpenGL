#include "ObjectCone.h"

void ObjectCone::init(const Vector3f& p, float radio, float height, int faces, const Color& color, float shininess) {
	p_radio = radio;
	p_height = height;
	p_faces = faces;
	translation(p+Vector3f(0,0,p_height/2.0f));
	
	p_color = color;
	p_shininess = shininess;

	p_bounding_box = 
		std::pair<Vector3f, Vector3f>(-Vector3f(p_radio, p_radio, 0),
									  Vector3f(p_radio, p_radio, p_height));
}

ObjectCone::ObjectCone(const Vector3f& p, float radio, float height, int faces, const Color& color) {
	init(p, radio, height, faces, color, 100.0f);
}

ObjectCone::ObjectCone(const Vector3f& p, float radio, float height, int faces, const Color& color, float shininess) {
	init(p, radio, height, faces, color, shininess);
}

void ObjectCone::drawMethod() const {
	glutSolidCone(p_radio, p_height, p_faces, p_faces);
}

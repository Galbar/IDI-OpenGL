#include "ObjectSphere.h"

void ObjectSphere::init(const Vector3f& p, float radio, int faces, const Color& color, float shininess) {
	p_radio = radio;
	p_faces = faces;
	translation(p);
	
	p_color = color;
	p_shininess = shininess;

	p_bounding_box = 
		std::pair<Vector3f, Vector3f>(Vector3f() - Vector3f(p_radio, p_radio, p_radio),
									  Vector3f(p_radio, p_radio, p_radio));
}

ObjectSphere::ObjectSphere(const Vector3f& p, float radio, int faces, const Color& color, float shininess) {
	init(p, radio, faces, color, shininess);
}

ObjectSphere::ObjectSphere(const Vector3f& p, float radio, int faces, const Color& color) {
	init(p, radio, faces, color, 100.0f);
}

void ObjectSphere::drawMethod() const{
	glutSolidSphere(p_radio, p_faces, p_faces);
}

#include "ObjectCube.h"

void ObjectCube::init(const Vector3f& p, float width, float height, float depth, const Color& color, float shininess) {
	scale(Vector3f(width, height, depth));
	translation(p);
	
	p_color = color;
	p_shininess = shininess;

	p_bounding_box = 
		std::pair<Vector3f, Vector3f>(Vector3f() - Vector3f(0.5, 0.5, 0.5),
									  Vector3f(0.5, 0.5, 0.5));
}

ObjectCube::ObjectCube(const Vector3f& p, float width, float height, float depth, const Color& color) {
	init(p, width, height, depth, color, 100.0f);
}

ObjectCube::ObjectCube(const Vector3f& p, float width, float height, float depth, const Color& color, float shininess) {
	init(p, width, height, depth, color, shininess);
}

void ObjectCube::drawMethod() const{
	glutSolidCube(1);
}

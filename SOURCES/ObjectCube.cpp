#include "ObjectCube.h"

void ObjectCube::init(const Vector3f& p, float width, float height, float depth, int subdivisions, const Color& color, float shininess) {
	translation(p);
	std::vector<Vector3f> l_vertex = std::vector<Vector3f>(8);
	l_vertex[0] = Vector3f(-width/2, height/2, -depth/2);
	l_vertex[1] = Vector3f(width/2, height/2, -depth/2);
	l_vertex[2] = Vector3f(width/2, height/2, depth/2);
	l_vertex[3] = Vector3f(-width/2, height/2, depth/2);
	l_vertex[4] = Vector3f(-width/2, -height/2, -depth/2);
	l_vertex[5] = Vector3f(width/2, -height/2, -depth/2);
	l_vertex[6] = Vector3f(width/2, -height/2, depth/2);
	l_vertex[7] = Vector3f(-width/2, -height/2, depth/2);
	add("top", new ObjectPlane(l_vertex[0], l_vertex[3], l_vertex[2], l_vertex[1], subdivisions, color, shininess));
	add("bottom", new ObjectPlane(l_vertex[4], l_vertex[7], l_vertex[6], l_vertex[5], subdivisions, color, shininess));
	add("left", new ObjectPlane(l_vertex[0], l_vertex[4], l_vertex[7], l_vertex[3], subdivisions, color, shininess));
	add("right", new ObjectPlane(l_vertex[1], l_vertex[2], l_vertex[6], l_vertex[5], subdivisions, color, shininess));
	add("front", new ObjectPlane(l_vertex[2], l_vertex[3], l_vertex[7], l_vertex[6], subdivisions, color, shininess));
	add("back", new ObjectPlane(l_vertex[0], l_vertex[1], l_vertex[5], l_vertex[4], subdivisions, color, shininess));
}

ObjectCube::ObjectCube(const Vector3f& p, float width, float height, float depth, const Color& color) {
	init(p, width, height, depth, 1, color, 100.0f);
}

ObjectCube::ObjectCube(const Vector3f& p, float width, float height, float depth, const Color& color, float shininess) {
	init(p, width, height, depth, 1, color, shininess);
}

ObjectCube::ObjectCube(const Vector3f& p, float width, float height, float depth, int subdivisions, const Color& color) {
	init(p, width, height, depth, subdivisions, color, 100.0f);
}

ObjectCube::ObjectCube(const Vector3f& p, float width, float height, float depth, int subdivisions, const Color& color, float shininess) {
	init(p, width, height, depth, subdivisions, color, shininess);
}

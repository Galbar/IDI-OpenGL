#include "ObjectPlane.h"

void ObjectPlane::init(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, const Color& color, float shininess) {
	p_vertex = std::vector<Vector3f>();
	p_vertex.push_back(p1);
	p_vertex.push_back(p2);
	p_vertex.push_back(p3);
	p_vertex.push_back(p4);
	
	p_normal = (p2 - p1).crossProduct(p3 - p1).normalized();

	p_color = color;
	p_shininess = shininess;

	Vector3f v = Vector3f(p_vertex[0].x, p_vertex[0].y, p_vertex[0].z);
	p_bounding_box = std::pair<Vector3f, Vector3f>(v,v);

	for (int i = 1; i < p_vertex.size(); ++i) {
		v = p_vertex[i];
		if (p_bounding_box.first.x > v.x) p_bounding_box.first.x = v.x;
		else if (p_bounding_box.second.x < v.x) p_bounding_box.second.x = v.x;
		if (p_bounding_box.first.y > v.y) p_bounding_box.first.y = v.y;
		else if (p_bounding_box.second.y < v.y) p_bounding_box.second.y = v.y;
		if (p_bounding_box.first.z > v.z) p_bounding_box.first.z = v.z;
		else if (p_bounding_box.second.z < v.z) p_bounding_box.second.z = v.z;
	}
	
}

ObjectPlane::ObjectPlane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, const Color& color) {
	init(p1, p2, p3, p4, color, 100.0f);
}

ObjectPlane::ObjectPlane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, const Color& color, float shininess) {
	init(p1, p2, p3, p4, color, shininess);
}

void ObjectPlane::drawMethod() const {
	glBegin(GL_QUADS);
	for (int i = 0; i < (int)p_vertex.size(); ++i) {
		std::vector<float> v = p_vertex[i].asStdVector();
		glNormal3f(p_normal.x, p_normal.y, p_normal.z);
		glVertex3fv(&v[0]);
	}
	glEnd();
}
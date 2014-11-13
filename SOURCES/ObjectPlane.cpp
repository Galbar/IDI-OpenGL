#include "ObjectPlane.h"

void ObjectPlane::init(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, int subdivisions, const Color& color, float shininess) {
	p_subdivisions = subdivisions;
	p_normal = (p2 - p1).crossProduct(p3 - p1).normalized();
	
	Vector3f increment1 = Vector3f(p2, p1)/subdivisions;
	Vector3f increment2 = Vector3f(p3, p2)/subdivisions;

	p_planes = std::vector<Vector3f>();
	Vector3f refp1 = p1;
	for (int i = 0; i <= subdivisions; ++i) {
		Vector3f refp2 = refp1;
		for (int j = 0; j <= subdivisions; ++j)
		{
			p_planes.push_back(refp2);
			refp2 += increment2;
		}
		refp1 += increment1;
	}

	p_color = color;
	p_shininess = shininess;

	std::vector<Vector3f> l_vertex = std::vector<Vector3f>();
	l_vertex.push_back(p1);
	l_vertex.push_back(p2);
	l_vertex.push_back(p3);
	l_vertex.push_back(p4);
	
	Vector3f v = l_vertex[0];
	p_bounding_box = std::pair<Vector3f, Vector3f>(v,v);
	for (int i = 1; i < l_vertex.size(); ++i) {
		v = l_vertex[i];
		if (p_bounding_box.first.x > v.x) p_bounding_box.first.x = v.x;
		else if (p_bounding_box.second.x < v.x) p_bounding_box.second.x = v.x;
		if (p_bounding_box.first.y > v.y) p_bounding_box.first.y = v.y;
		else if (p_bounding_box.second.y < v.y) p_bounding_box.second.y = v.y;
		if (p_bounding_box.first.z > v.z) p_bounding_box.first.z = v.z;
		else if (p_bounding_box.second.z < v.z) p_bounding_box.second.z = v.z;
	}

	translation((p_bounding_box.first + p_bounding_box.second)/2);
}

ObjectPlane::ObjectPlane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, const Color& color) {
	init(p1, p2, p3, p4, 1, color, 100.0f);
}

ObjectPlane::ObjectPlane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, const Color& color, float shininess) {
	init(p1, p2, p3, p4, 1, color, shininess);
}

ObjectPlane::ObjectPlane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, int subdivisions, const Color& color) {
	init(p1, p2, p3, p4, subdivisions, color, 100.0f);
}

ObjectPlane::ObjectPlane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, int subdivisions, const Color& color, float shininess) {
	init(p1, p2, p3, p4, subdivisions, color, shininess);
}

void ObjectPlane::drawMethod() const {
	int mod = p_subdivisions+1;
	for (int i = 0; i < (int)p_planes.size()-mod; ++i) {
	glBegin(GL_QUADS);
		if (i%mod != p_subdivisions) {
			std::vector<float> v = p_planes[i].asStdVector();
			glNormal3f(p_normal.x, p_normal.y, p_normal.z);
			glVertex3fv(&v[0]);
			v = p_planes[i+mod].asStdVector();
			glNormal3f(p_normal.x, p_normal.y, p_normal.z);
			glVertex3fv(&v[0]);
			v = p_planes[i+mod+1].asStdVector();
			glNormal3f(p_normal.x, p_normal.y, p_normal.z);
			glVertex3fv(&v[0]);
			v = p_planes[i+1].asStdVector();
			glNormal3f(p_normal.x, p_normal.y, p_normal.z);
			glVertex3fv(&v[0]);
		}
	glEnd();
	}
}
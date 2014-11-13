#ifndef OBJECT_PLANE
#define OBJECT_PLANE

#include <string>
#include "ObjectMonoColor.h"
#include "Color.h"

class ObjectPlane: public ObjectMonoColor {
private:
	std::vector<Vector3f> p_planes;
	int p_subdivisions;
	Vector3f p_normal;
	
	virtual void drawMethod() const;
	void init(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, int subdivisions, const Color& color, float shininess);

public:
	ObjectPlane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, const Color& color);
	ObjectPlane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, const Color& color, float shininess);
	ObjectPlane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, int subdivisions, const Color& color);
	ObjectPlane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, int subdivisions, const Color& color, float shininess);
};
#endif
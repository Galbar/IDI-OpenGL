#ifndef OBJECT_PLANE
#define OBJECT_PLANE

#include <string>
#include "Object.h"
#include "Color.h"

class ObjectPlane: public Object {
protected:
	std::vector<Vector3f> p_vertex;
	Color p_color;

public:
	ObjectPlane(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Vector3f& p4, const Color& c);

	void onDraw() const;
};
#endif
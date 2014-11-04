#ifndef OBJECT_SPHERE
#define OBJECT_SPHERE

#include <string>
#include "Object.h"
#include "Color.h"

class ObjectSphere: public Object {
protected:
	Vector3f p_vertex;
	float p_radio;
	int p_faces;
	Color p_color;

public:
	ObjectSphere(const Vector3f& p, float radio, int faces, const Color& c);

	void onDraw() const;
};
#endif
#ifndef OBJECT_CUBE
#define OBJECT_CUBE

#include <string>
#include "Object.h"
#include "Color.h"

class ObjectCube: public Object {
protected:
	Vector3f p_vertex;
	Color p_color;

public:
	ObjectCube(const Vector3f& p, float width, float height, float depth, const Color& c);

	void onDraw() const;
};
#endif
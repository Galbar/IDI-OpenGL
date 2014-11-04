#ifndef OBJECT_CONE
#define OBJECT_CONE

#include <string>
#include "Object.h"
#include "Color.h"

class ObjectCone: public Object {
protected:
	Vector3f p_vertex;
	float p_radio, p_height;
	int p_faces;
	Color p_color;

public:
	ObjectCone(const Vector3f& p, float radio, float height,int faces, const Color& c);

	void onDraw() const;
};
#endif
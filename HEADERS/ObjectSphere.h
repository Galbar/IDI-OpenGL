#ifndef OBJECT_SPHERE
#define OBJECT_SPHERE

#include <string>
#include "ObjectMonoColor.h"
#include "Color.h"

class ObjectSphere: public ObjectMonoColor {
private:
	float p_radio;
	int p_faces;

	virtual void drawMethod() const;
	void init(const Vector3f& p, float radio, int faces, const Color& color, float shininess);

public:
	ObjectSphere(const Vector3f& p, float radio, int faces, const Color& color);
	ObjectSphere(const Vector3f& p, float radio, int faces, const Color& color, float shininess);
};
#endif
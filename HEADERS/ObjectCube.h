#ifndef OBJECT_CUBE
#define OBJECT_CUBE

#include <string>
#include "ObjectMonoColor.h"
#include "Color.h"

class ObjectCube: public ObjectMonoColor {
private:
	void init(const Vector3f& p, float width, float height, float depth, const Color& color, float shininess);
	virtual void drawMethod() const;

public:
	ObjectCube(const Vector3f& p, float width, float height, float depth, const Color& color);
	ObjectCube(const Vector3f& p, float width, float height, float depth, const Color& color, float shininess);
};
#endif
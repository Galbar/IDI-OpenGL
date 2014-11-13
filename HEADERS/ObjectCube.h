#ifndef OBJECT_CUBE
#define OBJECT_CUBE

#include <string>
#include "ObjectGroup.h"
#include "ObjectPlane.h"
#include "Color.h"

class ObjectCube: public ObjectGroup {
private:
	void init(const Vector3f& p, float width, float height, float depth, int subdivisions, const Color& color, float shininess);

public:
	ObjectCube(const Vector3f& p, float width, float height, float depth, const Color& color);
	ObjectCube(const Vector3f& p, float width, float height, float depth, const Color& color, float shininess);
	ObjectCube(const Vector3f& p, float width, float height, float depth, int subdivisions, const Color& color);
	ObjectCube(const Vector3f& p, float width, float height, float depth, int subdivisions, const Color& color, float shininess);
};
#endif
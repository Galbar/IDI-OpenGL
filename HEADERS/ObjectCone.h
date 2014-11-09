#ifndef OBJECT_CONE
#define OBJECT_CONE

#include <string>
#include "ObjectMonoColor.h"
#include "Color.h"

class ObjectCone: public ObjectMonoColor {
private:
	float p_radio, p_height;
	int p_faces;

	void init(const Vector3f& p, float radio, float height, int faces, const Color& color, float shininess);
	virtual void drawMethod() const;
	
public:
	ObjectCone(const Vector3f& p, float radio, float height,int faces, const Color& color);
	ObjectCone(const Vector3f& p, float radio, float height, int faces, const Color& color, float shininess);
};
#endif
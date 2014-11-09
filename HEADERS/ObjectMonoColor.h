#ifndef OBJECT_MONO_COLOR
#define OBJECT_MONO_COLOR

#include <string>
#include "Object.h"
#include "Color.h"

class ObjectMonoColor: public Object {
protected:
	Color p_color;
	float p_shininess;

	virtual void drawMethod() const =0;

public:
	void onDraw() const;
};
#endif
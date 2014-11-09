#ifndef OBJECT_MODEL
#define OBJECT_MODEL

#include <string>
#include "Object.h"
#include "Model.h"

class ObjectModel: public Object {
private:
	Model p_model;
	std::pair<Vector3f, Vector3f> calcBoundingBox() const;
public:
	ObjectModel(const std::string& src);

	void onDraw() const;
};
#endif
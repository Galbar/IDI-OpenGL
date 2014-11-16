#ifndef OBJECT_MODEL
#define OBJECT_MODEL

#include <memory>
#include "Object.h"
#include "Model.h"

class ObjectModel: public Object {
private:
	std::shared_ptr<const Model> p_model;
	std::pair<Vector3f, Vector3f> calcBoundingBox() const;
public:
	ObjectModel(const Model* model);

	void onDraw() const;
};
#endif
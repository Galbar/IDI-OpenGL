#ifndef OBJECT_GROUP
#define OBJECT_GROUP

#include <string>
#include <map>
#include <memory>
#include "Object.h"
#include "Model.h"

class ObjectGroup: public Object {
private:
	std::map<std::string, std::unique_ptr<Object>> p_children;

public:
	ObjectGroup();

	bool add(Object* obj, std::string id);
	Object* get(std::string id);
	void remove(std::string id);
	std::map<std::string, std::unique_ptr<Object>>::const_iterator begin() const;
	std::map<std::string, std::unique_ptr<Object>>::const_iterator end() const;
	void onDraw() const;
	virtual void drawBoundingBox() const;
	std::pair<Vector3f, Vector3f> boundingBox() const;

	void setNormalMode(NormalMode mode);
};
#endif
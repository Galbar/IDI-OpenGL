
#include "ObjectGroup.h"
ObjectGroup::ObjectGroup(): Object() {
	p_children = std::map<std::string, std::unique_ptr<Object>>();
	//translation(Vector3f(-center().x, -center().y, -center().z));
}

std::pair<Vector3f, Vector3f> ObjectGroup::boundingBox() const{
	std::pair<Vector3f, Vector3f> l_bounding_box;

	if (p_children.empty()) {
		l_bounding_box = std::pair<Vector3f, Vector3f>(Vector3f(), Vector3f());
	}
	else {
		std::map<std::string, std::unique_ptr<Object>>::const_iterator it = p_children.begin();
		l_bounding_box = (it++)->second->boundingBox();
		for (; it!=p_children.end(); ++it) {
			std::pair<Vector3f, Vector3f> bb = it->second->boundingBox();
			if (l_bounding_box.first.x > bb.first.x) l_bounding_box.first.x = bb.first.x;
			if (l_bounding_box.first.y > bb.first.y) l_bounding_box.first.y = bb.first.y;
			if (l_bounding_box.first.z > bb.first.z) l_bounding_box.first.z = bb.first.z;

			if (l_bounding_box.second.x < bb.second.x) l_bounding_box.second.x = bb.second.x;
			if (l_bounding_box.second.y < bb.second.y) l_bounding_box.second.y = bb.second.y;
			if (l_bounding_box.second.z < bb.second.z) l_bounding_box.second.z = bb.second.z;
		}
	}
	l_bounding_box.first *= p_scale;
	l_bounding_box.first += p_translation;
	l_bounding_box.second *= p_scale;
	l_bounding_box.second += p_translation;
	return l_bounding_box;
}

bool ObjectGroup::add(Object* obj, std::string id) {
	return p_children.insert(std::pair<std::string, std::unique_ptr<Object>>(id, std::unique_ptr<Object>(obj))).second;
}

Object* ObjectGroup::get(std::string id) {
	return p_children.find(id)->second.get();
}

std::map<std::string, std::unique_ptr<Object>>::const_iterator ObjectGroup::begin() const{
	return p_children.begin();
}

std::map<std::string, std::unique_ptr<Object>>::const_iterator ObjectGroup::end() const{
	return p_children.end();
}

void ObjectGroup::remove(std::string id) {
	p_children.erase(id);
}

void ObjectGroup::onDraw() const{
	for (auto it = p_children.begin(); it!=p_children.end(); ++it) {
		it->second->draw();
	}
}	

void ObjectGroup::drawBoundingBox() const {
	Object::drawBoundingBox();
	for (auto it = p_children.begin(); it!=p_children.end(); ++it) {
		Vector3f t = it->second->translation();
		Vector3f s = it->second->scale();
		it->second->translation(t + translation());
		it->second->scale(s * scale());
		it->second->drawBoundingBox();
		it->second->translation(t);
		it->second->scale(s);
	}
}
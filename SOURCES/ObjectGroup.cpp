
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
	l_bounding_box.first *= scale();
	l_bounding_box.first += translation();
	l_bounding_box.second *= scale();
	l_bounding_box.second += translation();
	return l_bounding_box;
}

bool ObjectGroup::add(std::string id, Object* obj) {
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
	Vector3f l_center = (p_bounding_box.second + p_bounding_box.first)/2;
	glPushMatrix();
		glTranslatef(translation().x, translation().y, translation().z);
		glScalef(scale().x, scale().y, scale().z);
		glRotatef(rotation().x, 1, 0, 0);
		glRotatef(rotation().y, 0, 1, 0);
		glRotatef(rotation().z, 0, 0, 1);
		glTranslatef(-l_center.x, -l_center.y, -l_center.z);
		for (auto it = p_children.begin(); it!=p_children.end(); ++it) {
			it->second->drawBoundingBox();
		}
	glPopMatrix();
}

void ObjectGroup::setNormalMode(NormalMode mode) {
	p_normals_by_vertex = mode == NormalMode::BY_VERTEX? true : false;
	for (auto it = p_children.begin(); it!=p_children.end(); ++it) {
		it->second->setNormalMode(mode);
	}
}
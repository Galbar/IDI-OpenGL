#include "ObjectModel.h"

ObjectModel::ObjectModel(const std::string& src): Object() {
	p_model = Model();
	p_model.load(src);

	Vector3f v = Vector3f(p_model.vertices()[0], p_model.vertices()[1], p_model.vertices()[2]);
	p_bounding_box = std::pair<Vector3f, Vector3f>(v,v);
	for (int i = 3; i < p_model.vertices().size(); i += 3) {
		v = Vector3f(p_model.vertices()[i], p_model.vertices()[i+1], p_model.vertices()[i+2]);
		if (p_bounding_box.first.x > v.x) p_bounding_box.first.x = v.x;
		else if (p_bounding_box.second.x < v.x) p_bounding_box.second.x = v.x;
		if (p_bounding_box.first.y > v.y) p_bounding_box.first.y = v.y;
		else if (p_bounding_box.second.y < v.y) p_bounding_box.second.y = v.y;
		if (p_bounding_box.first.z > v.z) p_bounding_box.first.z = v.z;
		else if (p_bounding_box.second.z < v.z) p_bounding_box.second.z = v.z;
	}
}

void ObjectModel::onDraw() const{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < (int)p_model.faces().size(); ++i) {
		const Face& f = p_model.faces()[i];
		glColor4fv(Materials[f.mat].diffuse);
		glVertex3dv(&p_model.vertices()[f.v[0]]);
		glVertex3dv(&p_model.vertices()[f.v[1]]);
		glVertex3dv(&p_model.vertices()[f.v[2]]);
	}
	glEnd();
}
	

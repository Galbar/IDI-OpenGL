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
	bool is_lighting = (glIsEnabled(GL_LIGHTING) == GL_TRUE);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < (int)p_model.faces().size(); ++i) {
		const Face& f = p_model.faces()[i];
		if (is_lighting) {
			glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, Materials[f.mat].shininess);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, Materials[f.mat].ambient);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, Materials[f.mat].diffuse);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, Materials[f.mat].specular);
		}
		else {
			glColor4fv(Materials[f.mat].diffuse);
		}
		auto n00 = f.normalC[0];
		auto n01 = f.normalC[1];
		auto n02 = f.normalC[2];
		auto n10 = f.normalC[0];
		auto n11 = f.normalC[1];
		auto n12 = f.normalC[2];
		auto n20 = f.normalC[0];
		auto n21 = f.normalC[1];
		auto n22 = f.normalC[2];
		if (p_model.normals().size() != 0) {
			n00 = p_model.normals()[f.n[0]+0];
			n01 = p_model.normals()[f.n[0]+1];
			n02 = p_model.normals()[f.n[0]+2];
			n10 = p_model.normals()[f.n[1]+0];
			n11 = p_model.normals()[f.n[1]+1];
			n12 = p_model.normals()[f.n[1]+2];
			n20 = p_model.normals()[f.n[2]+0];
			n21 = p_model.normals()[f.n[2]+1];
			n22 = p_model.normals()[f.n[2]+2];
		}
		glNormal3d(n00, n01, n02);
		glVertex3dv(&p_model.vertices()[f.v[0]]);
		glNormal3f(n10, n11, n12);
		glVertex3dv(&p_model.vertices()[f.v[1]]);
		glNormal3f(n20, n21, n22);
		glVertex3dv(&p_model.vertices()[f.v[2]]);
	}
	glEnd();
}
	

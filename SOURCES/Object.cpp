#include "Object.h"

Object::Object() {
	p_translation  = Vector3f();
	p_rotation     = Vector3f();
	p_scale        = Vector3f(1.0f, 1.0f, 1.0f);
	p_bounding_box = std::pair<Vector3f, Vector3f>(Vector3f(),Vector3f());
}

void Object::draw() const{
	Vector3f l_center = (p_bounding_box.second + p_bounding_box.first)/2;
	glPushMatrix();
		glTranslatef(p_translation.x, p_translation.y, p_translation.z);
		glScalef(p_scale.x, p_scale.y, p_scale.z);
		glRotatef(p_rotation.x, 1, 0, 0);
		glRotatef(p_rotation.y, 0, 1, 0);
		glRotatef(p_rotation.z, 0, 0, 1);
		glTranslatef(-l_center.x, -l_center.y, -l_center.z);
		onDraw();
	glPopMatrix();
}

void Object::drawBoundingBox(const Vector3f& min, const Vector3f& max) {
	glBegin(GL_LINES);
		glColor3f(0, 1, 0);
		// eje y
		glVertex3f(max.x, max.y, max.z);
		glVertex3f(max.x, min.y, max.z);

		glVertex3f(min.x, max.y, min.z);
		glVertex3f(min.x, min.y, min.z);

		glVertex3f(min.x, max.y, max.z);
		glVertex3f(min.x, min.y, max.z);

		glVertex3f(max.x, max.y, min.z);
		glVertex3f(max.x, min.y, min.z);

		// eje x
		glVertex3f(max.x, max.y, max.z);
		glVertex3f(min.x, max.y, max.z);

		glVertex3f(max.x, min.y, min.z);
		glVertex3f(min.x, min.y, min.z);

		glVertex3f(max.x, max.y, min.z);
		glVertex3f(min.x, max.y, min.z);

		glVertex3f(max.x, min.y, max.z);
		glVertex3f(min.x, min.y, max.z);

		// eje z
		glVertex3f(max.x, max.y, max.z);
		glVertex3f(max.x, max.y, min.z);

		glVertex3f(min.x, min.y, max.z);
		glVertex3f(min.x, min.y, min.z);

		glVertex3f(max.x, min.y, max.z);
		glVertex3f(max.x, min.y, min.z);

		glVertex3f(min.x, max.y, max.z);
		glVertex3f(min.x, max.y, min.z);
	glEnd();
}

void Object::drawBoundingBox() const{
	std::pair<Vector3f, Vector3f> l_bounding_box = boundingBox();
	drawBoundingBox(l_bounding_box.first, l_bounding_box.second);
}

void Object::translation(const Vector3f& v) {
	p_translation = v;
}

void Object::rotation(const Vector3f& v) {
	p_rotation = v;
}

void Object::scale(const Vector3f& v) {
	p_scale = v;
}

const Vector3f& Object::translation() const{
	return p_translation;
}

const Vector3f& Object::rotation() const{
	return p_rotation;
}

const Vector3f& Object::scale() const{
	return p_scale;
}

const std::pair<Vector3f, Vector3f>& Object::initialBoundingBox() const {
	return p_bounding_box;
}

std::pair<Vector3f, Vector3f> Object::boundingBox() const{
	std::pair<Vector3f, Vector3f> l_bounding_box = p_bounding_box;

	Vector3f l_center = (l_bounding_box.second + l_bounding_box.first)/2;
	
	l_bounding_box.first -= l_center;
	l_bounding_box.first *= scale();
	l_bounding_box.first += translation();

	l_bounding_box.second -= l_center;
	l_bounding_box.second *= scale();
	l_bounding_box.second += translation();
	return l_bounding_box;
}
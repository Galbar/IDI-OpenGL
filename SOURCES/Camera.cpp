#include "Camera.h"
#include <assert.h>
Camera::Camera() {
	p_observer = Vector3f(0, 0, 1);
	p_up = Vector3f(0, 1, 0);
	p_view_reference_point = Vector3f();
	p_rotation = Vector3f();
	p_scale = Vector3f(1, 1, 1);
}

void Camera::lookAt(const Vector3f& from, const Vector3f& to, const Vector3f& up) {
	gluLookAt(from.x, from.y, from.z,
			  to.x, to.y, to.z,
			  up.x, up.y, up.z);
}

void Camera::setCameraOrtho(float left, float right, float bottom, float top, float zN, float zF) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(left, right, bottom, top, zN, zF);
	glMatrixMode(GL_MODELVIEW);
}

void Camera::setCameraPerspective(float fov, float aspect_ratio, float zN, float zF) {
	if (zN <= 0) zN = 0.01;
	if (fov <= 0) fov = 0.01;
	if (fov >= 180) fov = 175;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, aspect_ratio, zN, zF);
	glMatrixMode(GL_MODELVIEW);
}

void Camera::translate (const Vector3f& v) {
	p_observer += v;
	glTranslatef(v.x, v.y, v.z);
}

void Camera::rotate (float v, const Vector3f& dir) {
	p_rotation += (dir*v);
	glRotatef(v, dir.x, dir.y, dir.z);
}

void Camera::scale (const Vector3f& v) {
	p_scale += v;
	glScalef(v.x, v.y, v.z);
}

void Camera::reset() {
	p_observer = p_scale = p_rotation = Vector3f();
}

float Camera::FOV(float radius, float distance, float aspect_ratio) {
	if (aspect_ratio >= 1)
		return 2*asin(radius/distance)*(180/PI);
	else
		return 2*atan(tan(radius/distance)/aspect_ratio)*(180/PI);
}

const Vector3f& Camera::position() {
 return p_observer;
}

const Vector3f& Camera::rotation() {
	return p_rotation;
}

const Vector3f& Camera::scale() {
	return p_scale;
}

Vector3f& Camera::up() {
	return p_up;
}

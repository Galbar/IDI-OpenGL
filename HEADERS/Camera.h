#ifndef CAMERA
#define CAMERA

#if defined(__APPLE__)
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#else
#include <GL/gl.h>
#include <GL/freeglut.h>
#endif

#include "Vector3f.h"

class Camera {
private:
	Vector3f p_observer, p_view_reference_point, p_rotation, p_scale, p_up;
public:
	Camera();
	void reset();
	void lookAt(const Vector3f& from, const Vector3f& to, const Vector3f& up);
	const Vector3f& position();
	const Vector3f& rotation();
	const Vector3f& scale();
	float FOV(float radius, float distance, float aspect_ratio);
	void translate(const Vector3f& v);
	void rotate(float v, const Vector3f& dir);
	void scale(const Vector3f& v);
	Vector3f& up();
	void setCameraOrtho(float left, float right, float bottom, float top, float zN, float zF);
	void setCameraPerspective(float fov, float aspect_ratio, float zN, float zF);
};

#endif

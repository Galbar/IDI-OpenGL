#ifndef OBJECT
#define OBJECT

#if defined(__APPLE__)
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#else
#include <GL/gl.h>
#include <GL/freeglut.h>
#endif

#include <utility>
#include <vector>
#include "Vector3f.h"

class Object {
protected:
	Vector3f p_translation, p_rotation, p_scale;
	std::pair<Vector3f, Vector3f> p_bounding_box;

public:
	Object();
	void draw() const;
	static void drawBoundingBox(const Vector3f& max, const Vector3f& min);
	virtual void drawBoundingBox() const;
	virtual void onDraw() const =0;
	void translation(const Vector3f& v);
	void rotation(const Vector3f& v);
	void scale(const Vector3f& v);
	const Vector3f& translation() const;
	const Vector3f& rotation() const;
	const Vector3f& scale() const;
	virtual std::pair<Vector3f, Vector3f> boundingBox() const;
	const std::pair<Vector3f, Vector3f>& initialBoundingBox() const;
};

#endif
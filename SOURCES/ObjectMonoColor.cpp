#include "ObjectMonoColor.h"

void ObjectMonoColor::onDraw() const{
	if (glIsEnabled(GL_LIGHTING) == GL_TRUE) {
		GLfloat color[] = { p_color.r, p_color.g, p_color.b, 1.0f };
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, p_shininess);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
	}
	else {
		glColor3f(p_color.r, p_color.g, p_color.b);
	}
	drawMethod();
}

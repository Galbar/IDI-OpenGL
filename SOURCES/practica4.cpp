#if defined(__APPLE__)
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#else
#include <GL/gl.h>
#include <GL/freeglut.h>
#endif

#include <iostream>
#include <cmath>
#include "Vector3f.h"
#include "Color.h"
#include "Camera.h"
#include "Mouse.h"
#include "ObjectModel.h"
#include "ObjectPlane.h"
#include "ObjectCube.h"
#include "ObjectSphere.h"
#include "ObjectCone.h"
#include "ObjectGroup.h"
#include "Status.h"

#define DEBUG_INPUT false
bool smooth_shades = true;
Color* bkg_color;
Status* app_status;
ObjectGroup scene;
float vel_patricio;
bool display_boundingbox = false;
Camera* camera = new Camera();
int light0_vertex = 0;
Vector3f vertex_terra[4] = {
	Vector3f(-5, 0, -5),
	Vector3f(-5, 0, 5),
	Vector3f(5, 0, 5),
	Vector3f(5, 0, -5)
};

void initGlut(int argc, char const *argv[]) {
	glutInit(&argc, (char **)argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(app_status->window_width, app_status->window_height);
	glutCreateWindow("IDI: Practiques OpenGL");
}

void initGL() {
	glClearColor(bkg_color->r, bkg_color->g, bkg_color->b, 1);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_CULL_FACE);
	GLfloat scene_ambient_color[4] = {0.0f, 0.0f, 0.0f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, scene_ambient_color);
	// LIGHT0
	glEnable(GL_LIGHT0);
	GLfloat light0_ambient_color[4] = {0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat light0_diffuse_color[4] = {1.0f, 1.0f, 0.5f, 1.0f};
	GLfloat light0_specular_color[4] = {1.0f, 1.0f, 0.2f, 1.0f};
	glLightfv(GL_LIGHT0, GL_AMBIENT, light0_ambient_color);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse_color);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light0_specular_color);
	// LIGHT1
	GLfloat light1_ambient_color[4] = {0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat light1_diffuse_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat light1_specular_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light1_ambient_color);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse_color);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light1_specular_color);
	// LIGHT2
	GLfloat light2_ambient_color[4] = {0.0f, 0.0f, 0.0f, 1.0f};
	GLfloat light2_diffuse_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
	GLfloat light2_specular_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
	glEnable(GL_LIGHT2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient_color);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse_color);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular_color);
}

void initStatus() {
	app_status->mode = 0;
	app_status->submode = 0;

	app_status->scene_rotation = Vector3f(30, 30, 0);
	app_status->scene_translation = Vector3f();
	app_status->scene_scale = Vector3f(1, 1, 1);

	app_status->view_mode = 0;

	app_status->zoom = 1;
	app_status->view_walls = true;
	glutPostRedisplay();
}

void close() {
	delete bkg_color;
	delete app_status;
	delete camera;
	exit(0);
}

void printHelp() {
	std::cout << "--- IDI: Practiques OpenGL - Practica 3 ---" << std::endl
		  << "Accions en pressionar les tecles:" << std::endl
		  << "  h:     mostrar aquest text" << std::endl
		  << "  r:     reiniciar la càmera a l'estat inicial" << std::endl
		  << "  c:     entra/sortir del mode \"caminar\"" << std::endl
		  << "  b:     mostrar esfera contenidora de l'escena i tots els bounding box" << std::endl
		  << "  p:     canviar entre vista axonomètrica i perspectiva" << std::endl
		  << "  v:     amaga/mostra les parets de l'escena" << std::endl
		  << "  w:     fer que el patricio es mogui cap a davant"  << std::endl
		  << "  s:     fer que el patricio es mogui cap a darrere" << std::endl
		  << "  a:     fer que el patricio giri cap a l'esquerra" << std::endl
		  << "  d:     fer que el patricio giri cap a la dreta" << std::endl
		  << "  z:     augmentar la velocitat del patricio" << std::endl
		  << "  x:     disminuir la velocitat del patricio" << std::endl
		  << "  i:     activar/desactivar iluminació" << std::endl
		  << "  n:     intercanviar normal per cara/vertex" << std::endl
		  << "  m:     canviar la posició de la llum 0" << std::endl
		  << "  S:     intercanviar el shade model smooth/flat" << std::endl
		  << "  0:     activar/desactivar llum 0" << std::endl
		  << "  1:     activar/desactivar llum 1" << std::endl
		  << "  2:     activar/desactivar llum 2" << std::endl
		  << "  [Esc]: tancar aplicació" << std::endl
		  << "Accions amb el ratolí:" << std::endl
		  << "  LBtn:  arrosegar vertical i horitzontalment per girar al voltant de l'escena" << std::endl
		  << "  RBtn:  arrosegar verticalment per fer zoom" << std::endl << std::endl;
}

ObjectGroup* makeSnowMan() {
	ObjectGroup* obj = new ObjectGroup();
	obj->add("cuerpo", new ObjectSphere(Vector3f(0, 0.5, 0), 0.5, 15, Color(255, 255, 255), 128));
	obj->add("cara", new ObjectSphere(Vector3f(0, 1.2, 0), 0.25, 15, Color(255, 255, 255), 128));
	obj->add("nariz", new ObjectCone(Vector3f(0, 1.2, 0.25), 0.05, 0.2, 10, Color(1.0f, 0.2f, 0.2f), 128));
	return obj;
}

void drawCoordEdges(const Vector3f& center, const Vector3f& rotation, const Vector3f& scale) {
	glPushMatrix();
	glTranslatef(center.x, center.y, center.z);
	glScalef(scale.x, scale.y, scale.z);
	glRotatef(rotation.x, 1, 0, 0);
	glRotatef(rotation.y, 0, 1, 0);
	glRotatef(rotation.z, 0, 0, 1);
	glBegin(GL_LINES);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 1, 0);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(0, 0, 0);
		glVertex3f(0, 0, 1);
	glEnd();
	glPopMatrix();
}

void refresh(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	float radio = 1;
	Object* objs = scene.get("objetos");
	Vector3f center = ((scene.boundingBox().second + scene.boundingBox().first) / 2);
	radio = (scene.boundingBox().second - scene.boundingBox().first).length()/2;
	
	Object* patricio = scene.get("patricio");
	Vector3f dir_patricio = Vector3f(0, 0 , 1).rotateXZ(patricio->rotation().y).normalized();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	camera->reset();
	glPushMatrix();
		if (app_status->mode == 1) {
			camera->lookAt(patricio->translation()+Vector3f(0,0.25,0)+dir_patricio*0.1, patricio->translation()+dir_patricio+Vector3f(0,0.25,0), Vector3f(0,1,0));
			camera->setCameraPerspective(60.0/app_status->zoom, app_status->aspect_ratio, 0.01, 2*radio);
		}
		else {
			camera->translate(Vector3f(0, 0, -2*radio));
			camera->scale(Vector3f(app_status->scene_scale.x, app_status->scene_scale.y, app_status->scene_scale.z));
			camera->rotate(app_status->scene_rotation.z, Vector3f(0, 0, 1));
			camera->rotate(app_status->scene_rotation.x, Vector3f(1, 0, 0));
			camera->rotate(-app_status->scene_rotation.y, Vector3f(0, 1, 0));
			camera->translate(Vector3f(-center.x, -center.y, -center.z));
			
			if (app_status->view_mode == 0) {
				if (app_status->aspect_ratio >= 1)
					camera->setCameraOrtho((-radio*app_status->aspect_ratio)/app_status->zoom, (radio*app_status->aspect_ratio)/app_status->zoom, (-radio)/app_status->zoom,( radio)/app_status->zoom, (camera->position() + center).length() - radio, (camera->position() + center).length() + radio);
				else
					camera->setCameraOrtho((-radio)/app_status->zoom, (radio)/app_status->zoom, (-radio/app_status->aspect_ratio)/app_status->zoom, (radio/app_status->aspect_ratio)/app_status->zoom, (camera->position() + center).length() - radio, (camera->position() + center).length() + radio);
			}
			else {
				float FOV = camera->FOV(radio, (camera->position() + center).length(), app_status->aspect_ratio);
				camera->setCameraPerspective(FOV/app_status->zoom, app_status->aspect_ratio, (camera->position() + center).length() - radio, (camera->position() + center).length() + radio);
			}
		}
		
		// LIGHT0
		GLfloat light0_position[4] = {vertex_terra[light0_vertex].x, vertex_terra[light0_vertex].y+1.5f, vertex_terra[light0_vertex].z, 1.0f};
		glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
		// LIGHT2
		GLfloat light2_position[4] = {patricio->translation().x+dir_patricio.x*0.1f, patricio->translation().y+dir_patricio.y*0.1f+0.25f, patricio->translation().z+dir_patricio.z*0.1f, 1.0f};
		glLightfv(GL_LIGHT2, GL_POSITION, light2_position);

		if (app_status->mode != 1)
			patricio->draw();

		objs->draw();
		if (display_boundingbox) {
			scene.drawBoundingBox();
			// Dibuixar esfera contenidora
			glPushMatrix();
			if (glIsEnabled(GL_LIGHTING) == GL_TRUE) {
				GLfloat blue[] = { 0.0f, 1.0f, 1.0f, 1.0f };
				glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 128.0f);
				glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blue);
				glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blue);
				glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, blue);
			}
			else {
				glColor3f(0, 1, 1);
			}
			glTranslatef(center.x, center.y, center.z);
			glutWireSphere(radio, 15, 15);
			glPopMatrix();
		}
		Object* paredes = scene.get("paredes");
		if (app_status->view_walls) {
			paredes->draw();
		}

	glPopMatrix();
	glutSwapBuffers();
}

void keyboard(unsigned char c, int x, int y) {
#if DEBUG_INPUT
	std::cout << "[Keyboard]\tc:" << c << "\tx:" << x << "\ty:" << y << std::endl;
#endif
	if (c == '')
		close();
	else if (c == 'r') {
		initStatus();
		initGL();
	}
	else if (c == 'b') {
		display_boundingbox = not display_boundingbox;
		glutPostRedisplay();
	}
	else if (c == 'h')
		printHelp();
	else if (c == 'p') {
		app_status->view_mode = (app_status->view_mode+1)%2;
		glutPostRedisplay();
	}
	else if (c == 'c') {
		if (app_status->mode == 1) {
			initStatus();
		}
		else {
			app_status->mode = 1;
		}
		glutPostRedisplay();
	}
	else if (c == 'v') {
		app_status->view_walls = not app_status->view_walls;
		glutPostRedisplay();
	}
	else if (c == 'w') {
		Object* patricio = scene.get("patricio");
		Vector3f dir_patricio = Vector3f(0, 0 , 1).rotateXZ(patricio->rotation().y);
		patricio->translation(patricio->translation() + dir_patricio*0.1*vel_patricio);
		glutPostRedisplay();
	}
	else if (c == 's') {
		Object* patricio = scene.get("patricio");
		Vector3f dir_patricio = Vector3f(0, 0 , 1).rotateXZ(patricio->rotation().y);
		patricio->translation(patricio->translation() - dir_patricio*0.1*vel_patricio);
		glutPostRedisplay();
	}
	else if (c == 'a') {
		Object* patricio = scene.get("patricio");
		patricio->rotation(patricio->rotation() + Vector3f(0,3*vel_patricio,0));
		glutPostRedisplay();
	}
	else if (c == 'd') {
		Object* patricio = scene.get("patricio");
		patricio->rotation(patricio->rotation() + Vector3f(0,-3*vel_patricio,0));
		glutPostRedisplay();
	}
	else if (c == 'z') {
		vel_patricio *= 1.3;
	}
	else if (c == 'x') {
		vel_patricio /= 1.3;
	}
	else if (c == 'i') {
		glIsEnabled(GL_LIGHTING)? glDisable(GL_LIGHTING) : glEnable(GL_LIGHTING);
		glutPostRedisplay();
	}
	else if (c == 'n') {
		if (scene.getNormalMode() == Object::NormalMode::BY_VERTEX)
			scene.setNormalMode(Object::NormalMode::BY_FACE);
		else
			scene.setNormalMode(Object::NormalMode::BY_VERTEX);
		glutPostRedisplay();
	}
	else if (c == 'S') {
		if (smooth_shades)
			glShadeModel(GL_FLAT);
		else
			glShadeModel(GL_SMOOTH);
		smooth_shades = not smooth_shades;
		glutPostRedisplay();
	}
	else if (c == '0') {
		glIsEnabled(GL_LIGHT0)? glDisable(GL_LIGHT0) : glEnable(GL_LIGHT0);
		glutPostRedisplay();
	}
	else if (c == '1') {
		glIsEnabled(GL_LIGHT1)? glDisable(GL_LIGHT1) : glEnable(GL_LIGHT1);
		glutPostRedisplay();
	}
	else if (c == '2') {
		glIsEnabled(GL_LIGHT2)? glDisable(GL_LIGHT2) : glEnable(GL_LIGHT2);
		glutPostRedisplay();
	}
	else if (c == 'm') {
		light0_vertex++;
		if (light0_vertex > 3)
			light0_vertex = 0;
		glutPostRedisplay();
	}
}

void mouseClick(int button, int status, int x, int y) {
	bool is_down = (status == 0);
#if DEBUG_INPUT
	std::cout << "[MouseClick]\tbutton:" << button << "\tis_down:" << (is_down?"True":"False")
			  << "\tx:" << x << "\ty:" << y << std::endl;
#endif
	if (is_down) {
		Mouse::i()->pressed(button);
	} else {
		Mouse::i()->released(button);
	}
	Mouse::i()->update(x, y);
}

void mouseMotion(int x, int y) {
#if DEBUG_INPUT
	std::cout << "[MouseMotion]\tx:" << x << "\ty:" << y << std::endl;
#endif
	if (Mouse::i()->isPressed(0)) {
		app_status->scene_rotation += Vector3f( -(float)Mouse::i()->getDeltaY(y)/6.0f, (float)Mouse::i()->getDeltaX(x)/3.0f, 0);
	}
	else if (Mouse::i()->isPressed(2)) {
		app_status->zoom += (float)Mouse::i()->getDeltaY(y)/600.0f;
	}
	Mouse::i()->update(x, y);
	glutPostRedisplay();
}

void reshape(int width, int height) {
#if DEBUG_INPUT
	std::cout << "[Reshape]\twidth:" << width << "\theight:" << height << std::endl;
#endif
	app_status->aspect_ratio = (float) width/(float) height;
	glViewport(0, 0, width, height);
}


int main(int argc, char const *argv[]) {
	
	app_status = new Status(0, 0, 600, 600, 0, 0);
	bkg_color = new Color(100, 100, 100);
	////////////
	// Escena //
	////////////
	ObjectGroup objs = ObjectGroup();
	objs.add("terra",
			new ObjectPlane(
			vertex_terra[0],
			vertex_terra[1],
			vertex_terra[2],
			vertex_terra[3],
			10,
			Color(41, 128, 185)
		));
	
	vel_patricio = 1.0f;
	Model* patricio_model = new Model();
	patricio_model->load("DATA/Patricio.obj");
	ObjectModel* patricio = new ObjectModel(patricio_model);
	patricio->scale(Vector3f(
			 1.0/(patricio->boundingBox().second.y - patricio->boundingBox().first.y),
			 1.0/(patricio->boundingBox().second.y - patricio->boundingBox().first.y),
			 1.0/(patricio->boundingBox().second.y - patricio->boundingBox().first.y)));
	patricio->translation(Vector3f(0,0.5,0));
	patricio->rotation(Vector3f(0,-90,0));
	
	ObjectModel* patricio1 = new ObjectModel(patricio_model);
	patricio1->scale(Vector3f(
			 1.5/(patricio1->boundingBox().second.y - patricio1->boundingBox().first.y),
			 1.5/(patricio1->boundingBox().second.y - patricio1->boundingBox().first.y),
			 1.5/(patricio1->boundingBox().second.y - patricio1->boundingBox().first.y)));
	patricio1->translation(Vector3f(2.5,0.75,2.5));
	objs.add("patricio1", patricio1);

	Object* s = makeSnowMan();
	s->translation(s->translation() + Vector3f(2.5, 0, -2.5));
	objs.add("snowman0", s);
	s = makeSnowMan();
	s->translation(s->translation() + Vector3f(-2.5, 0, 2.5));
	objs.add("snowman1", s);
	s = makeSnowMan();
	s->translation(s->translation() + Vector3f(-2.5, 0, -2.5));
	objs.add("snowman2", s);

	ObjectGroup paredes = ObjectGroup();
	paredes.add("pared0", new ObjectCube(Vector3f(0,0.75,-4.9), 10, 1.5, 0.2, 10, Color(39, 201, 96), 0));
	paredes.add("pared1", new ObjectCube(Vector3f(1.5,0.75,2.5), 0.2, 1.5, 4, 10, Color(39, 201, 96), 0));

	scene = ObjectGroup();
	scene.add("objetos", &objs);
	scene.add("paredes", &paredes);
	scene.add("patricio", patricio);

	// Init GLUT
	initGlut(argc, argv);
	// Init OpenGL
	initGL();
	initStatus();
	// Keyboard input
	glutKeyboardFunc(keyboard);
	// Mouse input
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMotion);
	// Resize callback
	glutReshapeFunc(reshape);
	// Display callback
	glutDisplayFunc(refresh);
	glutMainLoop();
	return 0;
}

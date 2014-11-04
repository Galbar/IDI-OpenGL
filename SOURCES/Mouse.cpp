#include "Mouse.h"

Mouse* Mouse::instance = NULL;

Mouse::Mouse() {
	x = y = -1;
	for (int i = 0; i < 3; ++i)
		buttons[i] = false;
}

Mouse* Mouse::i() {
	if (instance == NULL) {
		instance = new Mouse();
	}
	return instance;
}

void Mouse::deleteInstance() {
	if (instance != NULL)
		delete instance;
}

int Mouse::getDiff(int val1, int val2) {
	if (val1 == -1) {
		return 0;
	} else {
		return val1 - val2;
	}
}

void Mouse::pressed(int i) {
	buttons[i%3] = true;
}

void Mouse::released(int i) {
	buttons[i%3] = false;
}

bool Mouse::isPressed(int i) {
	return buttons[i%3];
}

void Mouse::update(int x, int y) {
	this->x = x;
	this->y = y;
}

int Mouse::getDeltaX(int x) {
	return getDiff(this->x, x);
}

int Mouse::getDeltaY(int y) {
	return getDiff(this->y, y);
}
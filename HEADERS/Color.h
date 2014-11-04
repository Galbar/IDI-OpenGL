#ifndef COLOR
#define COLOR

#include <iostream>

struct Color {
	float r;
	float g;
	float b;

	Color() {
		this->r = 0.0f;
		this->g = 0.0f;
		this->b = 0.0f;
	}

	Color(float r, float g, float b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}

	Color(int r, int g, int b) {
		this->r = (float)r/255.0f;
		this->g = (float)g/255.0f;
		this->b = (float)b/255.0f;
	}

	void print() {
		std::cout << '(' << r << ", " << g << ", " << b << ')' << std::endl;
	}
};

#endif

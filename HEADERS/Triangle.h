#ifndef TRIANGLE
#define TRIANGLE

#include <iostream>
#include "Color.h"
#include "Vector3f.h"

struct Triangle {
	Vector3f p1;
	Vector3f p2;
	Vector3f p3;
	Color c;

	Triangle() {
		c = Color(1, 0, 0);
	}

	Triangle(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3) {
		this->p1 = p1;
		this->p2 = p2;
		this->p3 = p3;
		c = Color(1, 0, 0);
	}

	Triangle(const Vector3f& p1, const Vector3f& p2, const Vector3f& p3, const Color& c) {
		this->p1 = p1;
		this->p2 = p2;
		this->p3 = p3;
		this->c = c;
	}

	void print() {
		std::cout << '[' << std::endl;
		std::cout << '\t';
		p1.print();
		p2.print();
		p3.print();
		std::cout << ']' << std::endl;
		c.print();
	}
};

#endif

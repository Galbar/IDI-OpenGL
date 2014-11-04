#ifndef VECTOR3F
#define VECTOR3F

#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.14159265

class Vector3f {
public:
	float x;
	float y;
	float z;

	Vector3f(float x, float y, float z);
	Vector3f(const std::vector<float>& v);
	Vector3f();
	Vector3f& operator+= (const Vector3f& v);
	Vector3f& operator-= (const Vector3f& v);
	Vector3f& operator*= (const Vector3f& v);
	Vector3f& operator/= (const Vector3f& v);
	Vector3f& operator+= (const float& e);
	Vector3f& operator-= (const float& e);
	Vector3f& operator*= (const float& e);
	Vector3f& operator/= (const float& e);
	Vector3f normalize() const;
	float length() const;
	float dotProduct(const Vector3f& v) const;
	std::vector<float> asStdVector() const;
	void print() const;
};

// Operators
Vector3f operator+ (Vector3f u, const Vector3f& v);

Vector3f operator- (Vector3f u, const Vector3f& v);

Vector3f operator* (Vector3f u, const Vector3f& v);

Vector3f operator/ (Vector3f u, const Vector3f& v);

Vector3f operator+ (Vector3f v, const float& e);

Vector3f operator- (Vector3f v, const float& e);

Vector3f operator* (Vector3f v, const float& e);

Vector3f operator/ (Vector3f v, const float& e);

#endif

#ifndef VECTOR3F
#define VECTOR3F

#include <iostream>
#include <vector>
#include <cmath>

#define PI 3.14159265

class Vector3f {
private:
	float p_x;
	float p_y;
	float p_z;
	float p_length;

	static float module(float x, float y, float z);
	void init(float x, float y, float z);

public:
	float x;
	float y;
	float z;

	Vector3f(float xyz);
	Vector3f(float x, float y, float z);
	Vector3f(const Vector3f& v);
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
	Vector3f& normalize();
	Vector3f normalized() const;
	float length() const;
	float length();
	float dotProduct(const Vector3f& v) const;
	Vector3f crossProduct(const Vector3f& v) const;
	std::vector<float> asStdVector() const;
	Vector3f& rotateXZ(float degrees);
	Vector3f& rotateXY(float degrees);
	Vector3f& rotateYZ(float degrees);
	Vector3f rotatedXZ(float degrees) const;
	Vector3f rotatedXY(float degrees) const;
	Vector3f rotatedYZ(float degrees) const;
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

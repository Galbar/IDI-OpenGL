#include "Vector3f.h"

Vector3f::Vector3f(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3f::Vector3f(const std::vector<float>& v) {
	this->x = v[0];
	this->y = v[1];
	this->z = v[2];
}

Vector3f::Vector3f() {
	x = y = z = 0.0f;
}

std::vector<float> Vector3f::asStdVector() const {
	std::vector<float> r;
	r.push_back(x);
	r.push_back(y);
	r.push_back(z);
	return r;
}

void Vector3f::print() const {
	std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;
}

Vector3f& Vector3f::operator+= (const Vector3f& v) {
	*this = Vector3f(x + v.x, y + v.y, z + v.z);
	return *this;
}

Vector3f& Vector3f::operator-= (const Vector3f& v) {
	*this = Vector3f(x - v.x, y - v.y, z - v.z);
	return *this;
}

Vector3f& Vector3f::operator*= (const Vector3f& v) {
	*this = Vector3f(x * v.x, y * v.y, z * v.z);
	return *this;
*this = Vector3f(x - v.x, y - v.y, z - v.z);
	return *this;
}

Vector3f& Vector3f::operator/= (const Vector3f& v) {
	*this = Vector3f(x / v.x, y / v.y, z / v.z);
	return *this;
*this = Vector3f(x - v.x, y - v.y, z - v.z);
	return *this;
}

Vector3f& Vector3f::operator+= (const float& e) {
	*this = Vector3f(x + e, y + e, z + e);
	return *this;
}

Vector3f& Vector3f::operator-= (const float& e) {
	*this = Vector3f(x - e, y - e, z - e);
	return *this;
}

Vector3f& Vector3f::operator*= (const float& e) {
	*this = Vector3f(x * e, y * e, z * e);
	return *this;
}

Vector3f& Vector3f::operator/= (const float& e) {
	*this = Vector3f(x / e, y / e, z / e);
	return *this;
}

float Vector3f::length() const {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float Vector3f::dotProduct(const Vector3f& v) const {
	return x * v.x + y * v.y + z * v.z;
}

Vector3f Vector3f::normalize() const {
	return *this / length();
}

Vector3f operator+ (Vector3f u, const Vector3f& v) {
	return u += v;
}

Vector3f operator- (Vector3f u, const Vector3f& v) {
	return u -= v;
}

Vector3f operator* (Vector3f u, const Vector3f& v) {
	return u *= v;
}

Vector3f operator/ (Vector3f u, const Vector3f& v) {
	return u /= v;
}

Vector3f operator+ (Vector3f v, const float& e) {
	return v += e;
}

Vector3f operator- (Vector3f v, const float& e) {
	return v -= e;
}

Vector3f operator* (Vector3f v, const float& e) {
	return v *= e;
}

Vector3f operator/ (Vector3f v, const float& e) {
	return v /= e;
}
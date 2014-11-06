#include "Vector3f.h"

float Vector3f::module(float x, float y, float z) {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void Vector3f::init(float x, float y, float z) {
	this->x = this->p_x = x;
	this->y = this->p_y = y;
	this->z = this->p_z = z;
	p_length = module(x, y, z);
}

Vector3f::Vector3f(float x, float y, float z) {
	init(x, y, z);
}

Vector3f::Vector3f(float xyz) {
	init(xyz, xyz, xyz);
}

Vector3f::Vector3f(const Vector3f& v) {
	init(v.x, v.y, v.z);
}

Vector3f::Vector3f(const std::vector<float>& v) {
	init(v[0], v[1], v[2]);
}

Vector3f::Vector3f() {
	init(0.0f, 0.0f, 0.0f);
}

std::vector<float> Vector3f::asStdVector() const {
	std::vector<float> r = std::vector<float>(3);
	r[0] = x;
	r[1] = y;
	r[2] = z;
	return r;
}

void Vector3f::print() const {
	std::cout << '(' << x << ", " << y << ", " << z << ')' << std::endl;
}

Vector3f& Vector3f::normalize() {
	return *this /= length();
}

Vector3f& Vector3f::rotateXZ(float degrees) {
	degrees *= (PI/180.0);
	Vector3f tmp = *this;
	z = tmp.z * cos(degrees) - tmp.x * sin(degrees);
	x = tmp.z * sin(degrees) + tmp.x * cos(degrees);
	return *this;
}

Vector3f& Vector3f::rotateXY(float degrees) {
	degrees *= (PI/180.0);
	Vector3f tmp = *this;
	y = tmp.y * cos(degrees) - tmp.x * sin(degrees);
	x = tmp.y * sin(degrees) + tmp.x * cos(degrees);
	return *this;
}

Vector3f& Vector3f::rotateYZ(float degrees) {
	degrees *= (PI/180.0);
	Vector3f tmp = *this;
	z = tmp.z * cos(degrees) - tmp.y * sin(degrees);
	y = tmp.z * sin(degrees) + tmp.y * cos(degrees);
	return *this;
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

float Vector3f::length() {
	if (x != p_x or y != p_y or z != p_z) {
		p_x = x;
		p_y = y;
		p_z = z;
		p_length = module(x, y, z);
		std::cout << "hai" << std::endl;
	}
	return p_length;
}

float Vector3f::length() const {
	return module(x, y, z);
}

float Vector3f::dotProduct(const Vector3f& v) const {
	return x * v.x + y * v.y + z * v.z;
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
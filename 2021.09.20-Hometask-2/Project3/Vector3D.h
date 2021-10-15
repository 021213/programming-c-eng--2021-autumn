#pragma once
#include <ostream>

struct Vector3D
{
	double x;
	double y;
	double z;

	Vector3D();
	Vector3D(double, double, double);
	Vector3D(const Vector3D&);
	~Vector3D();

	Vector3D add(Vector3D);
	Vector3D mult(double);
	double dot(Vector3D);
	Vector3D cross(Vector3D);

	friend std::ostream& operator<<(std::ostream& stream, const Vector3D& vector);
};




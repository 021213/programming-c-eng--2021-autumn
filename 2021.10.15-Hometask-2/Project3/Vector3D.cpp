#include "Vector3D.h"

Vector3D::Vector3D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3D::Vector3D(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3D::Vector3D(const Vector3D& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
}

Vector3D::~Vector3D()
{

}

Vector3D Vector3D::add(Vector3D vector)
{
	return Vector3D(x + vector.x, y + vector.y, z + vector.z);
}

Vector3D Vector3D::mult(double m)
{
	return Vector3D(x * m, y * m, z * m);
}

double Vector3D::dot(Vector3D vector)
{
	return x * vector.x + y * vector.y + z * vector.z;
}

Vector3D Vector3D::cross(Vector3D vector)
{
	return Vector3D(y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x);
}

std::ostream& operator<<(std::ostream& stream, const Vector3D& vector)
{
	stream << "(" << vector.x << "; " << vector.y << "; " << vector.z << ")";
	return stream;
}

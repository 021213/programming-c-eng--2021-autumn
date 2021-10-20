#include "Vector3D.h"

Vector3D operator*(double mult, Vector3D vect)
{
	return Vector3D(mult * vect.x, mult * vect.y, mult * vect.z);
}

Vector3D Vector3D::operator*(double mult)
{
	return Vector3D(mult * x, mult * y, mult * z);
}

Vector3D Vector3D::operator=(Vector3D vect)
{
	x = vect.x;
	y = vect.y;
	z = vect.z;
	return (*this);
}

/*
Vector3D operator*(Vector3D vect, double mult)
{
	return mult * vect;
}
*/

Vector3D Vector3D::operator-()
{
	return Vector3D(-x, -y, -z);
}

std::ostream& operator<<(std::ostream& stream, const Vector3D& vect)
{
	stream << "{" << vect.x << "; " << vect.y << "; " << vect.z << "}";
	return stream;
}


Vector3D Vector3D::operator+(Vector3D vect)
{
	return Vector3D(x + vect.x, y + vect.y, z + vect.z);
}

Vector3D Vector3D::operator-(Vector3D vect)
{
	return (*this) + (-vect);
}
#pragma once
#include <ostream>

struct Vector3D
{
	double x;
	double y;
	double z;

	Vector3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {};
	Vector3D(const Vector3D& vector) : x(vector.x), y(vector.y), z(vector.z) {};
	//Vector3D(const Vector3D& vector) : Vector3D(vector.x, vector.y, vector.z) {};
	~Vector3D() {};

	Vector3D operator-();
	Vector3D operator*(double mult);
	//Vector3D operator*(Vector3D mult);
	Vector3D operator=(Vector3D vect);
	Vector3D operator+(Vector3D vect);
	Vector3D operator-(Vector3D vect);
	friend Vector3D operator*(double mult, Vector3D vect);
	friend std::ostream& operator<<(std::ostream& stream, const Vector3D& vect);

	//friend Vector3D operator*(Vector3D vect, double mult);
};
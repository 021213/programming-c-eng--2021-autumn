#include<iostream>
#include"Vector3D.h"

using namespace std;

int main(int argc, char* argv[])
{
	Vector3D vect1(4, 2, 1);
	Vector3D vect2(6, -2, 3);
	Vector3D vect3(vect1.add(vect2));
	Vector3D vect4(vect1.cross(vect2));
	Vector3D vect5(vect4.mult(vect2.dot(vect3)));
	cout << vect1 << endl;
	cout << vect2 << endl;
	cout << vect3 << endl;
	cout << vect4 << endl;
	cout << vect5 << endl;
	return EXIT_SUCCESS;
}
#include<iostream>
#include"Vector3D.h"

using namespace std;

int main()
{
	/*
	* Object Oriented Programming
	* 1. Abstraction
	* 2. Incapsulation
	* 3. Inheritance
	* 4. Polymorphism
	*/

	Vector3D v1(1, 2, 3);
	Vector3D v2(-2, 3, -5);
	Vector3D v3;
	cout << v3.x << " " << v3.y << " " << v3.z << endl;
	v3 = v1;
	cout << v3.x << " " << v3.y << " " << v3.z << endl;
	v3 = 5.4 * v3;
	cout << v3.x << " " << v3.y << " " << v3.z << endl;
	v3 = v3 * 9;
	cout << v3.x << " " << v3.y << " " << v3.z << endl;
	v3 = -v3;
	cout << v3.x << " " << v3.y << " " << v3.z << endl;

	v3 = v1 * 2 - 5 * v2;
	cout << v1 << " * 2 - 5 * " << v2 << " = " << v3 << endl;

	/*
	cout << 5 << " " << 3 << endl;
	int a = 3;
	int b = 5;
	int c = 3;
	a = b = c = 15;
	*/
	return EXIT_SUCCESS;
 }
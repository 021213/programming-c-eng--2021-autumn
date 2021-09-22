#pragma once
#include <iostream> //TODO : avoid using external libraries if you can

using namespace std;

struct Complex {
	//fields
	int re;
	int im;

	//constructor
	Complex(); //default constructor

	Complex(int re, int im = 0); //parametrized constructor

	Complex(const Complex& z); //copying constructor

	//destructor
	~Complex();

	//methods
	void print();
};
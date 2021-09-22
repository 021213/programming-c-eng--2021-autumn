#include "Complex.h"

//constructor
Complex::Complex() //default constructor
{
	this->re = 0;
	this->im = 0;
}

Complex::Complex(int re, int im) //parametrized constructor
{
	this->re = re;
	this->im = im;
}

Complex::Complex(const Complex& z) //copying constructor
{
	this->re = z.re;
	this->im = z.im;
}

//destructor
Complex::~Complex()
{

}

//methods
void Complex::print()
{
	cout << re;
	if (im < 0)
	{
		cout << " - " << -im;
	}
	else
	{
		cout << " + " << im;
	}
	cout << " * i" << endl;
}
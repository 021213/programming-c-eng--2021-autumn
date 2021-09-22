#include<iostream>

using namespace std;

struct Complex {
	//fields
	int re = 0;
	int im = 0;

	//constructor
	Complex()
	{
		this->re = 0;
		this->im = 0;
	}

	Complex(int re, int im)
	{
		this->re = re;
		this->im = im;
	}

	Complex(const Complex& z)
	{
		this->re = z.re;
		this->im = z.im;
	}

	//methods
	void print()
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
};

void printComplexNumber(Complex z)
{
	z.im = 1000;
	z.print();
}

int main(int argc, char* argv[])
{
	Complex z2;
	z2.print();

	Complex z1(4, -9);
	z1.print();
	
	printComplexNumber(z1);
	z1.print();

	return EXIT_SUCCESS;
}
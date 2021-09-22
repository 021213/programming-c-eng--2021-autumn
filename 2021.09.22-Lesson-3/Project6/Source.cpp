#include<iostream>

using namespace std;

struct Complex {
	//fields
	int re;
	int im;

	//constructor
	Complex() //default constructor
	{
		this->re = 0;
		this->im = 0;
	}

	Complex(int re, int im) //parametrized constructor
	{
		this->re = re;
		this->im = im;
	}

	Complex(const Complex& z) //copying constructor
	{
		this->re = z.re;
		this->im = z.im;
	}

	//destructor
	~Complex()
	{

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
	z.print();
}

int main(int argc, char* argv[])
{
	Complex z(2, 3);
	printComplexNumber(z);

	int* a = new int[100]{ 0 };
	delete[] a;

	return EXIT_SUCCESS;
}
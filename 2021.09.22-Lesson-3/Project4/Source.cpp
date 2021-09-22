#include<iostream>

using namespace std;

struct Complex {
	//fields
	int re = 0;
	int im = 0;

	//constructor
	Complex(int re = 0, int im = 0) : re(re), im(im) { } //just a demo
	/*
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
	*/

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

int main(int argc, char* argv[])
{
	Complex z1(4, -9);
	z1.print();

	return EXIT_SUCCESS;
 }
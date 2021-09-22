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

void print(int a, int b)
{
	cout << a << " + " << b << "*i" << endl;
}
void print(Complex z)
{
	cout << z.re << " + " << z.im << "*i" << endl;
}

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	cin >> a >> b;
	print(a, b);

	Complex z1;
	z1.re = 34;
	z1.im = -53;
	print(z1);

	Complex z2(4, -9);
	z2.print();

	//Complex z3 = z1 + z2;

	return EXIT_SUCCESS;
}
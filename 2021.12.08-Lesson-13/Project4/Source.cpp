#include<iostream>

using namespace std;

class A
{
public:
	int dataA;
	A(int a = 0) : dataA(a) {}
	virtual void print() = 0;
};

class B : public A
{
public:
	int dataB;
	B(int a = 0, int b = 0) : A(a), dataB(b) {}
	virtual void print()
	{
		cout << "Hello from B class" << endl;
	}
};

class C : public A
{
public:
	int dataC;
	C(int a = 0, int c = 0) : A(a), dataC(c) {}
	virtual void print()
	{
		cout << "Hello from C class" << endl;
	}
};

int main(int argc, char* argv[])
{
	const int n = 10;
	A** a = new A * [n];
	for (int i = 0; i < n; ++i)
	{
		if (rand() % 2)
		{
			a[i] = new B(45, 23);
		}
		else
		{
			a[i] = new C(93, 12);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		a[i]->print();
	}

	delete[] a;
	return 0;
}
#include<iostream>

using namespace std;

//abstract class
class APrintable
{
public:
	int a = 0;
	virtual void print() = 0;
	virtual int id() = 0;
};

class A : public APrintable
{
public:

	virtual void print() override
	{
		cout << "Hello from A" << a << endl;
	}

	virtual int id() override
	{
		return rand() % 10;
	}
};

class B : public APrintable
{
public:
	// Inherited via IPrintable
	virtual void print() override
	{
		cout << "Hello from B" << a << endl;
	}
	virtual int id() override
	{
		return rand() % 10;
	}
};

void outputGraterId(APrintable* i1, APrintable* i2)
{
	if (i1->id() > i2->id())
	{
		i1->print();
	}
	else
	{
		i2->print();
	}
}

int main(int argc, char* argv[])
{
	A* a = new A();
	B* b = new B();
	for (int i = 0; i < 10; ++i)
	{
		outputGraterId(a, b);
	}
	return EXIT_SUCCESS;
}
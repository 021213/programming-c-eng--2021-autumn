#include<iostream>

using namespace std;

//interface - only abstract functions
class IPrintable
{
public:
	virtual void print() = 0;
	virtual int id() = 0;
};

class A : public IPrintable
{
public:

	virtual void print() override
	{
		cout << "Hello from A" << endl;
	}

	virtual int id() override
	{
		return rand() % 10;
	}
};

class B : public IPrintable
{
public:
	// Inherited via IPrintable
	virtual void print() override
	{
		cout << "Hello from B" << endl;
	}
	virtual int id() override
	{
		return rand() % 10;
	}
};

void outputGraterId(IPrintable* i1, IPrintable* i2)
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
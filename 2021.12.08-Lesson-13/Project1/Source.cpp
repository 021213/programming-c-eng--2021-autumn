#include<iostream>

using namespace std;

class A
{
public:
	int dataA;
	A(int a = 0) : dataA(a) {}
	void print()
	{
		cout << "Hello from A class" << endl;
	}
};

class B : public A
{
public:
	int dataB;
	B(int a = 0, int b = 0) : A(a), dataB(b) {}
	void print()
	{
		cout << "Hello from B class" << endl;
	}
};

int main(int argc, char* argv[])
{
	A a(4);
	B b(5, 3);
	A a1;
	a1 = a;
	cout << a1.dataA;
	a1 = b;
	cout << a1.dataA;
	//b = a1;
	//cout << b.dataA;

	cout << endl;
	A* pa = new A(10);
	B* pb = new B(20, 30);
	cout << pa->dataA << endl;
	pa->print();
	delete pa;
	pa = pb;
	pa->print();
	((B*)pa)->print();
	cout << pa->dataA << endl;
	pb = (B*)pa;
	((B*)pa)->dataB = 40;
	cout << pb->dataA << " " << pb->dataB << endl;

	pa = new B(50, 20);
	pa->print();
	((B*)pa)->print();

	pb->A::print();
	pb->B::print();

	delete pa;
	delete pb;

	return 0;
}
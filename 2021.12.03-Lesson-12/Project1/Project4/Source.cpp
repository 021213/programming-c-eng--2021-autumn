#include<iostream>

using namespace std;

class A;

class B
{
private:
	int b;

public:
	B(int b) : b(b) {};

	int func(A& a);
};

class A
{
private:
	int a;

public:
	A(int a) : a(a) {};

	friend int B::func(A& a);
};

int B::func(A& a)
{
	return b + a.a;
}

int main(int argc, char* argv[])
{
	A a(5);
	B b(8);
	cout << b.func(a);

	return EXIT_SUCCESS;
}
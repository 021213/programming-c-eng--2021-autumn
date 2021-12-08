#include<iostream>

using namespace std;

class B;

class A
{
private:
	int a;

public:
	A(int a) : a(a) {};

	friend int func(A& a, B& b);
};

class B
{
private:
	int b;

public:
	B(int b) : b(b) {};

	friend int func(A& a, B& b);
};

int func(A& a, B& b)
{
	return a.a + b.b;
}

int main(int argc, char* argv[])
{
	A a(5);
	B b(8);
	cout << func(a, b) << endl;

	return EXIT_SUCCESS;
}
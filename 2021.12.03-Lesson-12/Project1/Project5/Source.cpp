#include<iostream>

using namespace std;

class A
{
protected:
	int a;
};

class B : public A
{
public:
	int b;

	void setA(int a)
	{
		this->a = a;
	}

	int getA()
	{
		return a;
	}
};

int main(int argc, char* argv[])
{
	B instB;
	instB.b = 5;

	instB.setA(10);
	cout << instB.getA();

	return EXIT_SUCCESS;
}
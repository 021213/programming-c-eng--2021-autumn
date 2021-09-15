#include<iostream>

using namespace std;

int f(int a = 0);	//declaration of function
int g(int a = 0);

int f(int a)	//definition of function
{
	if (a < 2)
	{
		return 1;
	}
	return f(a - 1) + g(a - 2);
}

int g(int a)
{
	if (a < 2)
	{
		return 1;
	}
	return f(a - 2) + g(a - 1);
}

int main()
{
	cout << f(12);
	return 0;
}
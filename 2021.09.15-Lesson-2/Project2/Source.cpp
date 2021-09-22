#include<iostream>

using namespace std;

/*
int sum(int a, int b = 0, int c = 0)
{
	return a + b + c;
}
*/

int sum(int a, int b, int c)
{
	return a + b + c;
}
int sum(int a, int b)
{
	return sum(a, b, 0);
}
int sum(int a)
{
	return sum(a, 0);
}

int main()
{
	cout << sum(2, 4) << endl;
	cout << sum(4, 2, 1) << endl;
	return 0;
}
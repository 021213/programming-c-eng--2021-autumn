#include<iostream>

using namespace std;

int sum(int a = 2, int b = 1)
{
	return a + b;
}

int main()
{
	int a = 0;
	a = 4;
	int b = 0;
	b = 8;

	cout << sum(a, b) << endl; // 12
	cout << sum(a) << endl; // 5
	cout << sum() << endl; // 3

	return 0;
}
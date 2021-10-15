#include<iostream>

using namespace std;

int gcd(int a, int b)
{
	if (a == b)
	{
		return a;
	}
	if (a > b)
	{
		return gcd(a - b, b);
	}
	else
	{
		return gcd(a, b - a);
	}
}

int gcd1(int a, int b)
{
	if (a * b == 0)
	{
		return a + b;
	}
	if (a > b)
	{
		return gcd(a % b, b);
	}
	else
	{
		return gcd(a, b % a);
	}
}


int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	cin >> a >> b;
	cout << gcd(a, b);
	return EXIT_SUCCESS;
}
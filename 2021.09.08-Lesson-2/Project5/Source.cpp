#include<iostream>

using namespace std;

unsigned long long factorial(unsigned long long n)
{
	if (n < 2)
	{
		return 1;
	}
	return n * factorial(n - 1);
}

unsigned long long fib(unsigned long long n)
{
	int first = 1;
	int second = 1;
	while (n > 1)
	{
		int temp = second + first;
		first = second;
		second = temp;
		--n;
	}
	return second;
}

int main()
{
	unsigned long long a = 0;
	cin >> a;
	cout << a << "! = " << factorial(a) << endl;
	cout << "fib(" << a << ") = " << fib(a) << endl;
	cout << a << "! = " << factorial(a) << endl;
	cout << "fib(" << a << ") = " << fib(a) << endl;
	cout << a << "! = " << factorial(a) << endl;
	cout << "fib(" << a << ") = " << fib(a) << endl;
	return 0;
}
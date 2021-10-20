#include<iostream>

using namespace std;

int fib(int n)
{
	if (n < 2)
	{
		return 1;
	}
	return fib(n - 1) + fib(n - 2);
}

int fib1(int n)
{
	int a0 = 1;
	int a1 = 1;
	while (n > 1)
	{
		int t = a1 + a0;
		a0 = a1;
		a1 = t;
		--n;
	}
	return a1;
}

int fib2(int n, int* fibs, int& count)
{
	if (count <= n)
	{
		fibs[n] = fib2(n - 1, fibs, count) + fib2(n - 2, fibs, count);
		count = n + 1;
	}
	return fibs[n];
}

int main(int argc, char* argv[])
{
	int* fibs = new int[100]{ 1, 1 }; // 1 1 0 0 0 0 0 0 
	int count = 2;
	for (int i = 0; i < 5; ++i)
	{
		cout << fib(i) << " " << fib1(i) << " " << fib2(i, fibs, count) << endl;
	}
	return EXIT_SUCCESS;
}
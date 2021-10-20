#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main(int argc, char** argv)
{
	//static array
	int a[5]{ 0 };

	for (int i = 0; i < sizeof(a)/ sizeof(int); ++i)
	{
		a[i] = i;
	}

	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	const int N = 10;
#define M 20

	int b[N]{ 0 };
	for (int i = 0; i < N; ++i)
	{
		b[i] = N - 1 - i;
	}
	for (int i = 0; i < sizeof(b) / sizeof(int); ++i)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	int c[M]{ 0 };
	for (int i = 0; i < M; ++i)
	{
		c[i] = M / 2 - 1 - i;
	}
	for (int i = 0; i < sizeof(c) / sizeof(int); ++i)
	{
		cout << c[i] << " ";
	}
	cout << endl;

	return 0;
}
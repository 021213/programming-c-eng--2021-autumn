#include<iostream>

using namespace std;

void randomizeArray(int* a, int n, int min = 10, int max = 99)
{
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % (max - min + 1) + min;
	}
}

void printArray(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void reverseArray(int* a, int n, int start, int end)
{
	for (int i = 0; i < (end - start + 1) / 2; ++i)
	{
		int c = a[start + i];
		a[start + i] = a[end - i];
		a[end - i] = c;
	}
}

void changeElements(int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		a[i] = i - 2;
	}
}

void expandArray(int* &a, int &n, int rate = 1)
{
	int* newA = new int[n + rate]{ 0 };
	for (int i = 0; i < n; ++i)
	{
		newA[i] = a[i];
	}
	delete[] a;
	a = newA;
	n += rate;
}

int main(int argc, char* argv[])
{
	int n = 0;
	cin >> n;
	int* a = new int[n] { 0 };
	
	randomizeArray(a, n);
	printArray(a, n);
	changeElements(a, n);
	printArray(a, n);
	expandArray(a, n);
	printArray(a, n);
	randomizeArray(a, n, 1, 9);
	printArray(a, n);

	delete[] a;
	return EXIT_SUCCESS;
}
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

int main(int argc, char* argv[])
{
	int n = 0;
	cin >> n;
	int* a = new int[n] { 0 };
	int k = 0;
	cin >> k;
	k = (k % n + n) % n;

	randomizeArray(a, n);
	printArray(a, n);
	reverseArray(a, n, 0, n - k - 1);
	reverseArray(a, n, n - k, n - 1);
	reverseArray(a, n, 0, n - 1);
	printArray(a, n);

	delete[] a;
	return EXIT_SUCCESS;
}
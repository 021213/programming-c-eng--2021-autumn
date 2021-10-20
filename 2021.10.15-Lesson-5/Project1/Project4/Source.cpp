#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char* argv)
{
	int n = 4;
	//cin >> n;

	//alloc, realloc, calloc
	int* a = (int*)malloc(n * sizeof(int));

	*(a + 0) = 4;
	*(a + 1) = 3;
	*(a + 2) = 2;
	*(a + 3) = 1;

	cout << a + 0 << " = " << (*(a + 0)) << endl;
	cout << a + 1 << " = " << (*(a + 1)) << endl;
	cout << a + 2 << " = " << (*(a + 2)) << endl;
	cout << a + 3 << " = " << (*(a + 3)) << endl;

	a[0] = 5;
	a[1] = 6; // *(a + 1)
	a[2] = 7;
	a[3] = 8;

	free(a);

	cin >> n;
	a = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	int maxIndex = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > a[maxIndex])
		{
			maxIndex = i;
		}
	}
	int minIndex = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < a[minIndex])
		{
			minIndex = i;
		}
	}

	int c = a[maxIndex];
	a[maxIndex] = a[minIndex];
	a[minIndex] = c;

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	return EXIT_SUCCESS;
}
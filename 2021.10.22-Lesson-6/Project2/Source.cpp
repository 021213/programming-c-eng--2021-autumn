#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	cin >> n;
	int* a = new int[n] { 0 };

	int min = 10;
	int max = 99;
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % (max - min + 1) + min; //random number from [min; max]
	}
	
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	int firstMinIndex = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[firstMinIndex] > a[i])
		{
			firstMinIndex = i;
		}
	}
	cout << "First min index : " << firstMinIndex << endl;

	delete[] a;
	return EXIT_SUCCESS;
}
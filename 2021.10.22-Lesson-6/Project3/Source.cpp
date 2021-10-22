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
		//a[i] = rand() % (max - min + 1) + min; //random number from [min; max]
		a[i] = i + 1;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	//shifting an array of N elements by K places;
	//n = 10;
	//a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//k = 4;
	//-> a = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
	//k = -4; -> k = 6;
	//-> a = {5, 6, 7, 8, 9, 10, 1, 2, 3, 4};

	int k = 0;
	cin >> k;
	k = (k % n + n) % n;

	/*
	for (int j = 0; j < k; ++j)
	{
		int last = a[n - 1];
		for (int i = n - 1; i > 0; --i)
		{
			a[i] = a[i - 1];
		}
		a[0] = last;
	}
	*/

	int start = 0;
	int end = 0;
	//a = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//start = 2;
	//end = 7;
	//a = { 1, 2, 8, 7, 6, 5, 4, 3, 9, 10 };
	start = 0;
	end = n - k - 1;
	for (int i = 0; i < (end - start + 1) / 2; ++i)
	{
		int c = a[start + i];
		a[start + i] = a[end - i];
		a[end - i] = c;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;


	start = n - k;
	end = n - 1;
	for (int i = 0; i < (end - start + 1) / 2; ++i)
	{
		int c = a[start + i];
		a[start + i] = a[end - i];
		a[end - i] = c;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	start = 0;
	end = n - 1;
	for (int i = 0; i < (end - start + 1) / 2; ++i)
	{
		int c = a[start + i];
		a[start + i] = a[end - i];
		a[end - i] = c;
	}

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	delete[] a;
	return EXIT_SUCCESS;
}
#include "MyArrayFunctions.h"

int* createArray(int n)
{
	return new int[n] { 0 };
}

void printArray(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void randomizeArray(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 90 + 10;
	}
}

int sumOfArray(int* arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
	}
	return sum;
}

void deleteArray(int* &arr)
{
	delete[] arr;
	arr = nullptr;
}

#include<iostream>
#include"MyArrayFunctions.h"

int main()
{
	int n = 10;
	int* arr = createArray(n);
	randomizeArray(arr, n);
	printArray(arr, n);
	randomizeArray(arr, n);
	printArray(arr, n);
	deleteArray(arr);
	int a[10]{ 0 };
	int* b = (int*)malloc(sizeof(int) * 10);
	free(b);
	b = new int[10]{ 0 };
	delete[] b;
	return 0;
}
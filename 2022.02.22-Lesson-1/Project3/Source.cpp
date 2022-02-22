#include<iostream>
#include"ArrayList.h"

using namespace std;

void randomizeArrayList(ArrayList& list, int start = 10, int end = 99)
{
	for (int i = 0; i < list.size(); ++i)
	{
		list[i] = rand() % (end - start + 1) + start;
	}
}

void linearSort(ArrayList& a)
{
	int count[100]{ 0 };
	for (int i = 0; i < a.size(); ++i)
	{
		++count[a[i]];
	}
	for (int i = 0, k = 0; i < 100; ++i)
	{
		for(int j = 0; j < count[i]; ++j, ++k)
		{
			a[k] = i;
		}
	}
}

int main()
{
	ArrayList a(100);

	randomizeArrayList(a);
	cout << a;

	linearSort(a);

	cout << a;

	return EXIT_SUCCESS;
}
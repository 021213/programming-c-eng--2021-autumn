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

int main()
{
	ArrayList a(10);

	randomizeArrayList(a);
	cout << a;

	a.bitwiseSort();

	cout << a;

	return EXIT_SUCCESS;
}
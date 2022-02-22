#include<iostream>
#include<cstdlib>
#include<ctime>
#include"ArrayList.h"

using namespace std;

void randomizeArrayList(ArrayList& list, int start = 10, int end = 90)
{
	for (int i = 0; i < list.size(); ++i)
	{
		list[i] = rand() % (end - start + 1) + start;
	}
}

void monkeySort(ArrayList& list)
{
	while (!list.isSorted())
	{
		list.mix();
	}
}

void bubbleSort(ArrayList& list)
{
	for (int i = 0; i < list.size(); ++i)
	{
		for (int j = 0; j < list.size() - 1 - i; ++j)
		{
			if (list[j] > list[j + 1])
			{
				swap(list[j], list[j + 1]);
			}
		}
	}
}

/*
void insertSort(ArrayList& list)
{

}

void selectionSort(ArrayList& list)
{

}

void gnomeSort(ArrayList& list)
{

}
*/

int main()
{
	srand(time(0));
	ArrayList a(7);

	randomizeArrayList(a);
	cout << a;
	
	bubbleSort(a);

	cout << a;


	return 0;
}
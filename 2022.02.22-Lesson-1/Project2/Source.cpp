#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include"ArrayList.h"

using namespace std;

void randomizeArrayList(ArrayList& list, int start = 10, int end = 90)
{
	for (int i = 0; i < list.size(); ++i)
	{
		list[i] = rand() % (end - start + 1) + start;
	}
}

int main()
{
	srand(time(0));
	ArrayList a(7);

	randomizeArrayList(a);
	cout << a;

	sort(&a[0], &a[a.size() - 1]); //O(n * ln(n))

	cout << a;


	return 0;
}
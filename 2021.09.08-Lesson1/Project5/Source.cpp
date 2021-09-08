#include<iostream>

using namespace std;

int main()
{
	for (int a = 0; a < 10; ++a)
	{
		cout << a << " ";
	}
	cout << endl;

	for (int i = 0, j = 10; i < 10; ++i, --j)
	{
		cout << i << " " << j << endl;
	}

	int a[10];
	for (auto i = 0; i < 10; ++i)
	{
		a[i] = rand()%100;
	}

	for (auto i = 0; i < 10; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	for (auto el : a) //for each element (named el) from collection a 
	{
		cout << el << " ";
	}
	cout << endl;

	int i = 0;
	while (i < 10)
	{
		cout << a[i] << " ";
		++i;
	}
	cout << endl;

	i = 0;
	do
	{
		cout << a[i] << " ";
		++i;
	} while (i < 10);
	cout << endl;

	i = 0;
	for(;i < 10;)
	{
		cout << a[i] << " ";
		++i;
	}
	cout << endl;

	return 0;
}
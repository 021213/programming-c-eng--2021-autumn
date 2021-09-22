#include<iostream>

using namespace std;

int main()
{

	//srand(time(0));

	int a[10] = { 0 };
	int* b = (int*)malloc(sizeof(int) * 10);
	for (int i = 0; i < 10; ++i)
	{
		if (b != nullptr)
		{
			b[i] = rand() % 100;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		if (b != nullptr)
		{
			cout << b[i] << " ";
		}
	}
	cout << endl;
	free(b);

	b = new int[10]{ 0 };
	for (int i = 0; i < 10; ++i)
	{
		b[i] = rand() % 100;
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	delete[] b;

	return 0;
}
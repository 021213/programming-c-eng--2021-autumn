#include<iostream>

using namespace std;

int main()
{
	int a = 5;
	int b = 7;

	if (a > b)
	{
		cout << a << endl;
	}
	else
	{
		cout << b << endl;
	}

	cout << (a > b ? a : b) << endl;

	switch (a % 2)
	{
	case 1:
		cout << "a is odd" << endl;
		break;
	default:
		cout << "a is even" << endl;
		break;
	}

	if (a % 2 == 0) goto banana1; else goto bananaend;
banana1:
	if (a % 3 == 0) goto banana2; else goto bananaend;
banana2:
	if (a % 36 == 0) goto bananaend;
bananaend:



	return 0;
}
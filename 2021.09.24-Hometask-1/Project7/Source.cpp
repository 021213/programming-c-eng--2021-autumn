#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	cin >> a >> b >> c;

	//a >= b && b >= c
	while (!(a >= b && b >= c))
	{
		if (a < b)
		{
			int t = a;
			a = b;
			b = t;
		}
		if (b < c)
		{
			int t = c;
			c = b;
			b = t;
		}
	}
	if (a * a == b * b + c * c)
	{
		cout << "rectangular" << endl;
	}
	else if (a * a < b * b + c * c)
	{
		cout << "acute" << endl;
	}
	else
	{
		cout << "obtuse" << endl;
	}
	return EXIT_SUCCESS;
}
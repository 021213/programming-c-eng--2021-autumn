#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{

	int a = 0;
	int b = 0;
	int c = 0;
	cin >> a >> b >> c;

	while (!(a <= b && b <= c))
	{
		if (a > b)
		{
			int t = a;
			a = b;
			b = t;
		}
		if (b > c)
		{
			int t = c;
			c = b;
			b = t;
		}
	}

	cout << a << " " << b << " " << c << endl;

	return EXIT_SUCCESS;
}
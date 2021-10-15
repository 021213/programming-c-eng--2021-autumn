#include<iostream>

using namespace std;

bool canGetNumber(int n = 1)
{
	if (n < 1)
	{
		return false;
	}
	if (n == 1)
	{
		return true;
	}

	return canGetNumber(n - 5) || canGetNumber(n - 3);
}

int main(int argc, char* argv[])
{
	int n = 0;
	cin >> n;
	cout << (canGetNumber(n) ? "YES" : "NO");

	return EXIT_SUCCESS;
}
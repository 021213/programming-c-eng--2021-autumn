#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a = 0;
	cin >> a;
	int a1 = a / 1000 % 10;
	int a2 = a / 100 % 10;
	int a3 = a / 10 % 10;
	int a4 = a % 10;
	int res = a - 1000 * a4 - 100 * a3 - 10 * a2 - a1 + 1;
	res = 1 + (a1 - a4) + (a2 - a3) * 100;
	cout << res << endl;
	return EXIT_SUCCESS;
}
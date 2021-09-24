#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	cin >> a >> b >> c;
	int rest = a % 2 + b % 2 + c % 2;
	cout << ((rest > 0 && rest < 3) ? "YES" : "NO");
	return EXIT_SUCCESS;
}
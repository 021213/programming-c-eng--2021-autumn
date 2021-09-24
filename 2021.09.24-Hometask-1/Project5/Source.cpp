#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	cout << (n % m) * (m % n) + 1;
	return EXIT_SUCCESS;
}
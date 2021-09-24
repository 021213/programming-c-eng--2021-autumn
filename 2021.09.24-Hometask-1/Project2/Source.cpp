#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	cin >> n;
	int h = n / 60 / 60 % 24;
	int m = n / 60 % 60;
	int s = n % 60;
	cout << h << ":" << m / 10 << m % 10 << ":" << s / 10 << s % 10 << endl;
	return EXIT_SUCCESS;
}
#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int ab1 = abs(a - b);
	cout << (a + b + ab1) / 2 << endl;
	cout << ((a / b * a + b / a * b) / (a % b + b % a)) << endl;
	return EXIT_SUCCESS;
}
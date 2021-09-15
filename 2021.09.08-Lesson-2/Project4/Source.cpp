#include<iostream>

using namespace std;

int printMenu()
{
	cout << "OUR OWESOME PROGRAMM" << endl;
	return 0;
}

void print(int a)
{
	cout << a << " + " << a << " = " << 2 * a << endl;
}

int calcSumDiff(int a, int b, int& resultSum, int& resultDiff)
{
	resultSum = a + b;
	resultDiff = a - b;
	return 0;
}

int main(int argc, char* argv[])
{
	int val1 = 0;
	int val2 = 0;
	val1 = 4;
	val2 = 9;
	int sum = 0;
	int diff = 0;
	printMenu();
	calcSumDiff(val1, val2, sum, diff);
	cout << val1 << " + " << val2 << " = " << sum << endl;
	cout << val1 << " - " << val2 << " = " << diff << endl;

	return EXIT_SUCCESS;
}
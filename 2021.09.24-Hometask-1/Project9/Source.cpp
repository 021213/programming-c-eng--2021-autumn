#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n = 0;
	//M = 1000;
	//D = 500;
	//C = 100;
	//L = 50;
	//X = 10;
	//V = 5;
	//I = 1;
	cin >> n; // n < 1000
	while (n > 500)
	{
		cout << "D";
		n -= 500;
	}
	while (n > 400)
	{
		cout << "CD";
		n -= 400;
	}
	while (n > 100)
	{
		cout << "C";
		n -= 100;
	}
	while (n > 90)
	{
		cout << "XC";
		n -= 90;
	}
	while (n > 50)
	{
		cout << "L";
		n -= 50;
	}
	while (n > 40)
	{
		cout << "XL";
		n -= 40;
	}
	while (n > 10)
	{
		cout << "X";
		n -= 10;
	}
	while (n > 9)
	{
		cout << "IX";
		n -= 9;
	}
	while (n > 5)
	{
		cout << "V";
		n -= 5;
	}
	while (n > 4)
	{
		cout << "IV";
		n -= 4;
	}
	while (n > 0)
	{
		cout << "I";
		n -= 1;
	}
	return EXIT_SUCCESS;
}
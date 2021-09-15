#include<iostream>

using namespace std;

void swap(int &a, int &b)
{
	//a ^= b ^= a ^= b;
	/*
	int c = a;
	a = b;
	b = c;
	*/
	a = a + b;
	b = a - b;
	a = a + b;
	//TELL ME THE VALUES THAT CANNOT BE PROCESSED THIS WAY
}

int main()
{
	int a = 0;
	int b = 0;
	a = 5;
	b = 7;
	cout << a << " " << b << endl;
	swap(a, b);
	cout << a << " " << b << endl;
	return 0;
}
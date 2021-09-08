#include<iostream>

using namespace std;

int main()
{
	int a = 3;
	int b = 5;
	int c = 0;
	c = a + b;
	c = a - b;
	c = a * b;
	c = a / b;
	c = a % b;

	a += b;
	a *= b;
	a /= b; // a = a / b;
	a %= b; // a = a / b;
	a -= b; // a = a - b;

	float f = 0;
	a = 5;
	b = 2;
	f = a / b; // 2.0
	f = (float)a / b;
	f = 1.0f * a / b;

	c = a | b;
	c = a & b;
	c = a ^ b;

	cout << a << " " << b << endl;
	a ^= b ^= a ^= b;
	cout << a << " " << b << "\n";

	a = 7;		// 0000 0111
	a = a << 2; // 0001 1100
	cout << a << endl;
	a = 7;		// 0000 0111
	a = a >> 1; // 0000 0011
	cout << a << endl;

	a++;
	++a;
	a--;
	--a;

	a = 7;
	//  7   +   9 +  10 + 10   
	a = a++ + ++a + ++a + a++;
	cout << a << endl; //38

	a = 7;
	a = ~a; // -8

	a = 9;
	a = ~a; // -10
	
	//      1 1111 111
	//  9 =   0000 1001
	// -9 =   1111 0111
	//9-9 = 1 0000 0000

	//  9    =   0000 1001
	// ~9    =   1111 0110 == -10
	// ~9+1  =   1111 0111 == -9

	bool bA = true;
	bool bB = true;
	bool bC = true;

	bC = bA && bB;
	bC = bA || bB;
	bC = bA ^ bB;
	bC = bA == bB;
	bC = !bA;

	a = 10;
	b = 19;
	c = (a > b ? a : b);
	if (a > b)
	{
		c = a;
	}
	else
	{
		c = b;
	}

	return EXIT_SUCCESS;
}
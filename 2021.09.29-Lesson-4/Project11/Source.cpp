#include<iostream>
#include<iomanip>

using namespace std;


void print(int field[10][10], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << setw(2) << field[i][j] << " ";
		}
		cout << endl;
	}
}


void fill(int field[10][10], int n, int circle = 0, int current = 1)
{
	if (circle * 2 >= n)
	{
		if (n % 2 == 1)
		{
			field[circle - 1][circle - 1] = current;
		}
		return;
	}

	for (int i = circle; i < n - 1 - circle; ++i, ++current)
	{
		field[circle][i] = current;
	}
	for (int i = circle; i < n - 1 - circle; ++i, ++current)
	{
		field[i][n - 1 - circle] = current;
	}
	for (int i = n - 1 - circle; i > circle; --i, ++current)
	{
		field[n - 1 - circle][i] = current;
	}
	for (int i = n - 1 - circle; i > circle; --i, ++current)
	{
		field[i][circle] = current;
	}
	fill(field, n, circle + 1, current);
}
/*
  1  2  3  4  5  6
 20              7
 19              8
 18              9
 17             10
 16 15 14 13 12 11
 */

int main(int argc, char* argv[])
{
	int field[10][10]{ 0 };
	int n = 0;
	cin >> n;

	fill(field, n);
	print(field, n);
	return EXIT_SUCCESS;
}
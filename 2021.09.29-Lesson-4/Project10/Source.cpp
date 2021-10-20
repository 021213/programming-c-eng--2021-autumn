#include<iostream>

using namespace std;
/*
5
*****
**..*
*.***
*...*
*****
2 4
*/
/*
-------
-*****-
-**..*-
-*.*.*-
-*...*-
-*****-
-------
*/

int area(char field[12][12], int n, int x, int y)
{
	if (field[x][y] == '*')
	{
		return 0;
	}

	int result = 1;
	field[x][y] = '*';
	result += area(field, n, x - 1, y);
	result += area(field, n, x + 1, y);
	result += area(field, n, x, y - 1);
	result += area(field, n, x, y + 1);
	return result;
}

int main(int argc, char* argv[])
{
	char field[12][12];
	for (int i = 0; i < 12; ++i)
	{
		for (int j = 0; j < 12; ++j)
		{
			field[i][j] = '*';
		}
	}

	int n = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> field[i][j];
		}
	}

	int x = 0;
	int y = 0;
	cin >> x >> y;
	cout << area(field, n, x, y);

	return EXIT_SUCCESS;
}
#include<iostream>

using namespace std;

/*
The first line of the input file INPUT.TXT contains 3 numbers: N and M – the number of rows and columns of
the matrix (1 ≤ N, M ≤ 1000) and K – the number of requests (1 ≤ K ≤ 105).
Each of the next N lines contains M numbers - elements Aij of the corresponding row of the matrix (1 ≤ Aij ≤ 104).
The next K lines contain 4 integers each - y1, x1, y2 and x2 - a query for the sum of elements
in the rectangle (1 ≤ y1 ≤ y2 ≤ N, 1 ≤ x1 ≤ x2 ≤ M).
*/


/*
3 4 1
1 2 3 4
5 6 7 8
9 10 11 12
2 3 3 4

>> 38
*/

class QueryMatrix
{
private:
	int** data;
	int** sumdata;
	int n;
	int m;

	void updateSum()
	{
		for (int i = 1; i < n + 1; ++i)
		{
			for (int j = 1; j < m + 1; ++j)
			{
				sumdata[i][j] = data[i - 1][j - 1] + sumdata[i - 1][j] + sumdata[i][j - 1] - sumdata[i - 1][j - 1];
			}
		}
		/*
		for (int i = 0; i < n + 1; ++i)
		{
			for (int j = 0; j < m + 1; ++j)
			{
				cout << sumdata[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
	}

public:
	QueryMatrix(int** data, int n, int m) : data(data), n(n), m(m)
	{
		sumdata = new int*[n + 1];
		for (int i = 0; i < n + 1; ++i)
		{
			sumdata[i] = new int[m + 1];
			for (int j = 0; j < m + 1; ++j)
			{
				sumdata[i][j] = 0;
			}
		}
		updateSum();
	}
	~QueryMatrix()
	{
		for (int i = 0; i < m + 1; ++i)
		{
			delete[] sumdata[i];
		}
		delete[] sumdata;
	}

	int sum(int x1, int y1, int x2, int y2)
	{
		if (x1 > x2)
		{
			return sum(x2, y1, x1, y2);
		}
		if (y1 > y2)
		{
			return sum(x1, y2, x2, y1);
		}
		//cout << sumdata[x2][y2] << " ";
		//cout << sumdata[x1 - 1][y1 - 1] << " ";
		//cout << sumdata[x2][y1 - 1] << " ";
		//cout << sumdata[x1 - 1][y2] << endl;
		return sumdata[x2][y2] + sumdata[x1 - 1][y1 - 1] - sumdata[x2][y1 - 1] - sumdata[x1 - 1][y2];
	}

};

int main()
{

	int n = 0;
	int m = 0;
	int k = 0;
	cin >> n >> m >> k;

	int** data = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		data[i] = new int[m];
		for (int j = 0; j < m; ++j)
		{
			cin >> data[i][j];
		}
	}

	QueryMatrix qm(data, n, m);

	for (int i = 0; i < k; ++i)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << qm.sum(x1, y1, x2, y2);
	}

	for (int i = 0; i < m; ++i)
	{
		delete[] data[i];
	}
	delete[] data;
	return 0;
}

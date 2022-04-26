#include<iostream>

using namespace std;

/*
The first line of the input file INPUT.TXT contains the number N, the dimension of the array.
The second line contains N numbers - array elements.
The third line contains the number M, the number of requests for the sum.
The next M lines contain pairs of numbers L and R (L ≤ R ≤ N) describing the segments.
All numbers in the input are natural numbers not exceeding 10^5.
*/

class QueryArray
{
private:
	int* data;
	int* sumdata;
	int n;

	void updateSum(int invalidIndex = 1)
	{
		for (int i = invalidIndex; i <= n; ++i)
		{
			sumdata[i] = sumdata[i - 1] + data[i - 1];
		}
	}

public:
	QueryArray(int* data, int n) : data(data), n(n)
	{
		sumdata = new int[n + 1];
		for (int i = 0; i < n + 1; ++i)
		{
			sumdata[i] = 0;
		}
		updateSum();
	}
	~QueryArray()
	{
		delete[] data;
		delete[] sumdata;
	}

	int sum(int l, int r)
	{
		return sumdata[r] - sumdata[l - 1];
	}

	int update(int index, int newelement)
	{
		data[index - 1] = newelement;
		updateSum(index);
	}
};

int main()
{
	int n = 0;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	QueryArray qa(a, n);

	int m = 0;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int l = 0;
		int r = 0;
		cin >> l >> r;
		cout << qa.sum(l, r);
	}
	return 0;
}
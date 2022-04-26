#include<iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	int* sum = new int[n + 1];
	for(int i = 0; i < n; ++i)
	{
		sum[i] = 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		sum[i] = sum[i - 1] + a[i - 1];
	}
	cout << endl;
	for (int i = 0; i <= n; ++i)
	{
		cout << sum[i] << " ";
	}
	cout << endl;

	int m = 0;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int l = 0;
		int r = 0;
		cin >> l >> r;
		cout << endl << sum[r] - sum[l - 1] << endl;
	}
	delete[] a;
	delete[] sum;
	return 0;
}
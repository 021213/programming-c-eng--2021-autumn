#include<iostream>

using namespace std;

int C(int n, int k)
{
	if (k == 0 || k == n)
	{
		return 1;
	}
	return C(n - 1, k) + C(n - 1, k - 1);
}

int Ccalced(int n, int k, int** Ccalc)
{
	if (Ccalc[n - k][k] == 0)
	{
		Ccalc[n - k][k] = Ccalced(n - 1, k, Ccalc) + Ccalced(n - 1, k - 1, Ccalc);
	}
	return Ccalc[n - k][k];
}

int main(int argc, char* argv[])
{
	int dim = 100;
	int** Ccalc = new int* [dim];
	for (int i = 0; i < dim; ++i)
	{
		Ccalc[i] = new int[dim - i]{ 0 };
	}
	for (int i = 0; i < dim; ++i)
	{
		Ccalc[i][0] = Ccalc[0][i] = 1;
	}

	int n = 0;
	int k = 0;
	cin >> n >> k;
	cout << C(n, k) << " " << Ccalced(n, k, Ccalc);

	for (int i = 0; i < dim; ++i)
	{
		delete[] Ccalc[i];
	}
	delete[] Ccalc;

	return EXIT_SUCCESS;
}
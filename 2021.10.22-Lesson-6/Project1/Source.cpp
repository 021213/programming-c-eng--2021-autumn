#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	//static array C-version
#define M 10
	int a[M]{ 0 };

	//static array C++-version
	const int N = 10;
	int b[N]{ 0 };

	//dynamic array C-version
	int m = 0;
	scanf_s("%d", &m);
	int* c = (int*)malloc(sizeof(int) * m);
	free(c);

	//dynamic array C++-version
	int n = 0;
	cin >> n;
	int* d = new int[n] { 0 };

	delete[] d;

	return EXIT_SUCCESS;
}
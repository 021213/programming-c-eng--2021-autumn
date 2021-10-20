#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int main(int argc, char** argv)
{
	int n = 0;
	cin >> n;
	int* a = new int[n] { 0 };

	delete[] a;
	return 0;
}
#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int h = 0;
	int a = 0;
	int b = 0;
	cin >> h >> a >> b;
	int hh = h - a;
	int aa = a - b;
	int n = 0;
	n = 1 + hh / aa + (hh % aa + aa - 1) / aa;
	return EXIT_SUCCESS;
}
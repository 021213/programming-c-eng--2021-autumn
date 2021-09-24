#include<iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int t = 0;
	int v = 0;
	const int S = 109;
	cin >> v >> t;
	cout << (v * t % S + S) % S;
	return EXIT_SUCCESS;
}
#include<iostream>

using namespace std;

void hanoy(int count, int from = 1, int to = 3)
{
	if (count == 0)
	{
		return;
	}

	int reserve = 6 - from - to;
	hanoy(count - 1, from, reserve);
	cout << count << " " << from << " " << to << endl;
	hanoy(count - 1, reserve, to);
}

int main(int argc, char* argv[])
{
	int n = 0;
	cin >> n;
	hanoy(n);
	return EXIT_SUCCESS;
}
#include<iostream>
#include<string>

using namespace std;

int maxN(int a, int b)
{
	return (a > b ? a : b);
}

int maxDigit(string& str, int max = -1, int index = 0)
{
	if (str.length() <= index)
	{
		return max;
	}
	max = maxN(max, str[index] - '0');
	return maxDigit(str, max, index + 1);
}

int main(int argc, char* argv[])
{
	string str = "";
	cin >> str;

	cout << maxDigit(str);

	return EXIT_SUCCESS;
}
#include<iostream>
#include<string>

using namespace std;

int isDigit(char c)
{
	return (c >= '0' && c <= '9' ? 1 : 0);
}

int numberOfDigits(string& str, int index = 0)
{
	if (str.length() <= index)
	{
		return 0;
	}

	return isDigit(str[index]) + numberOfDigits(str, index + 1);
}

int main(int argc, char* argv[])
{
	string str = "";
	cin >> str;
	
	cout << numberOfDigits(str) << endl;

	return EXIT_SUCCESS;
}
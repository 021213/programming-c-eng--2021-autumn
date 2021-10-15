#include<iostream>
#include<string>

using namespace std;

void outputWithBrackets(string& str, int index = 0)
{
	cout << str[index];

	if ((index + 1) * 2 < str.length())
	{
		cout << '(';
		outputWithBrackets(str, index + 1);
		cout << ')';
	}

	if (index * 2 + 1 != str.length())
	{
		cout << str[str.length() - 1 - index];
	}
}

int main(int argc, char* argv[])
{
	string str = "";
	cin >> str;
	outputWithBrackets(str);
	return EXIT_SUCCESS;
}
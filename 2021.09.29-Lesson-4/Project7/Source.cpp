#include<iostream>
#include<string>

using namespace std;

void outputNotSymmetric(string& str, int index = 0)
{
	if (str.length() / 2 <= index)
	{
		if (index * 2 + 1 == str.length())
		{
			cout << str[index];
		}
		return;
	}

	if (str[index] != str[str.length() - 1 - index])
	{
		cout << str[index];
	}

	outputNotSymmetric(str, index + 1);

	if (str[index] != str[str.length() - 1 - index])
	{
		cout << str[str.length() - 1 - index];
	}
}

int main(int argc, char* argv[])
{
	string str = "";
	cin >> str;
	outputNotSymmetric(str);
	return EXIT_SUCCESS;
}
#include<iostream>
#include<string>

using namespace std;

void outputWithAsterisks(string& str, int index = 0)
{
	cout << str[index];
	if (index == str.length() - 1)
	{
		return;
	}
	cout << "*";
	outputWithAsterisks(str, index + 1);
}

int main(int argc, char* argv[])
{
	string str = "";
	cin >> str;
	outputWithAsterisks(str);
	return EXIT_SUCCESS;
}
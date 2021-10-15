#include<iostream>
#include<string>

using namespace std;

void outputWithMirrored(string& str, int index = 0)
{
	if (str.length() <= index)
	{
		return;
	}
	
	cout << str[index];
	outputWithMirrored(str, index + 1);
	cout << (str[index] == '(' ? ')' : str[index]);
}

int main(int argc, char* argv[])
{
	string str = "";
	cin >> str;
	outputWithMirrored(str);
	return EXIT_SUCCESS;
}
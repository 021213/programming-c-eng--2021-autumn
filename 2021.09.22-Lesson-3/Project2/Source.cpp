#include<iostream>
#include<string>

using namespace std;

// a(b
// a(b b(a

//(abc(def(g
//(abc(def(g

void output(string str, int current = 0)
{
	if (current == str.length())
	{
		return;
	}

	cout << str[current];
	output(str, current + 1);
	cout << (str[current] == '(' ? ')': str[current]);
	/*
	if (str[current] == '(')
	{
		cout << ')';
	}
	else
	{
		cout << str[current];
	}
	*/
}

int main(int argc, char* argv[])
{
	string str = "";
	cin >> str;
	output(str);
	return EXIT_SUCCESS;
}

#include<iostream>
#include<cmath>

using namespace std;

namespace Scope
{
	const int NAME = 1 << 0;
	const int MESSAGES = 1 << 3;
	const int GROUPS = 1 << 8;
	const int VIDEO = 1 << 12;
}

enum EScope
{
	NAME = 1,
	MESSAGES = 1 << 3,
	GROUPS = 1 << 8,
	VIDEO = 1 << 12
};

int main(int argc, char* argv[])
{
	int c = 0;
	int a = 2;
	int b = 3;
	cout << b << endl;
	{
		cout << b << endl;
		int b = 6;
		cout << b << endl;
	}
	cout << b << endl;

	{
		int c = a;
		a = b;
		b = c;
	}

	{
		int c = a;
		a = b;
		b = c;
	}

	const int ACONST = 24;
	int avariable = 40;

	{
		int scope = 1 | 1 << 12 | 1 << 3 | 256;
	}
	{
		int scope = Scope::NAME | Scope::VIDEO | Scope::MESSAGES | Scope::GROUPS;
	}

	return EXIT_SUCCESS;
}
#include<iostream>

enum EXITCODE{
	WRONG_NUMBER1 = 1,
	WRONG_NUMBER2 = 2,
	WRONG_OPERATION = 3,
	UNEXPECTED_ERROR = 4,
	SUCCESS = 0
};

EXITCODE func(int a, char c, int b, int &data)
{
	if (a < 0 || a > 99)
	{
		data = a;
		return WRONG_NUMBER1;
	}
	if (b < 0 || b > 99)
	{
		data = b;
		return WRONG_NUMBER2;
	}
	if (c != '+' && c != '-')
	{
		data = c;
		return WRONG_OPERATION;
	}
	if (a + b > 99)
	{
		data = a + b;
		return UNEXPECTED_ERROR;
	}
	data = a + b;
	return SUCCESS;
}

int main()
{
	exit(7);

	return EXIT_SUCCESS;
	return EXIT_FAILURE;
}
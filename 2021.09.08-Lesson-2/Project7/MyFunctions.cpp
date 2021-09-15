#include "MyFunctions.h"

int f(int a)
{
	if (a < 2)
	{
		return 1;
	}
	return f(a - 1) + g(a - 2);
}

int g(int a)
{
	if (a < 2)
	{
		return 1;
	}
	return f(a - 2) + g(a - 1);
}
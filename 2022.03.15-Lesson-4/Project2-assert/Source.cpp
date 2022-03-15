#include<iostream>
#include<cassert>
#define NDEBUG

int banana(int a)
{
	assert(a < 10);
	assert(a > 0 && a < 10 && "something wrong");

	return a + 4;
}

int main()
{
	static_assert(sizeof(long) == 4, "long must be 4 bytes"); //C++11 -> compiling
	static_assert(sizeof(int) == 4, "int must be 4 bytes");
	banana(5);
	return 0;
}
#include<iostream>
#include "Complex.h"

using namespace std;

void printComplexNumber(Complex z)
{
	z.print();
}

int main(int argc, char* argv[])
{
	Complex z(2, 3);
	printComplexNumber(z);

	return EXIT_SUCCESS;
}
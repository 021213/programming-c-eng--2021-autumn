#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

struct IntException : std::exception
{
	int number;
	IntException(int num = 5) : std::exception(std::to_string(num).c_str()), number(num) {}
	IntException(const IntException& e) : std::exception(e.what()), number(e.number) {}
};

int one()
{
	if (rand() % 2 == 0)
	{
		throw std::exception("banana");
	}
	else
	{
		throw IntException(5);
	}
}

int main()
{
	srand(time(0));
	std::cout << "Start main\n";
	try
	{
		one();
	}
	catch (double)
	{
		std::cerr << "main caught int exception\n";
	}
	catch (std::exception e)
	{
		std::cerr << "main caught std::exception : " << e.what() << std::endl;
	}
	std::cout << "End main\n";
	
	return 0;
}
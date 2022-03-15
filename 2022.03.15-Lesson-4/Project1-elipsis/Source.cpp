#include <iostream>
#include <cstdarg>
#include <string>

double findAverage(int count, ...) //... - ellipsis
{
    double sum = 0;

    va_list list;

    va_start(list, count);

    for (int arg = 0; arg < count; ++arg)
    {
        sum += va_arg(list, int);
    }

    va_end(list);

    return sum / count;
}

double findAverageC(int first, ...)
{
	double sum = first;

	va_list list;

	va_start(list, first);

	int count = 1;

	while (1)
	{
		int arg = va_arg(list, int);

		if (arg == -1)
		{
			break;
		}

		sum += arg;
		count++;
	}

	va_end(list);

	return sum / count;
}

double findAverageF(std::string decoder, ...)
{
	double sum = 0;

	va_list list;

	va_start(list, decoder);

	int count = 0;

	while (1)
	{
		char codetype = decoder[count];
		switch (codetype)
		{
		default:
		case '\0':
			va_end(list);
			return sum / count;

		case 'i':
			sum += va_arg(list, int);
			count++;
			break;

		case 'd':
			sum += va_arg(list, double);
			count++;
			break;
		}
	}
}

int main()
{
    std::cout << findAverage(4, 1, 2, 3, 4) << '\n';
	std::cout << findAverage(5, 1, 2, 3, 4, 5) << '\n';
	std::cout << findAverageC(1, 2, 3, -1) << '\n';
	std::cout << findAverageC(1, 2, 3, 4, 5, -1) << '\n';
	std::cout << findAverageF("iiii", 1, 2, 3, 4) << '\n';
	std::cout << findAverageF("iiiii", 1, 2, 3, 4, 5) << '\n';
	std::cout << findAverageF("ididdi", 1, 2.2, 3, 3.5, 4.5, 5) << '\n';

	printf("%d + %d = %d\n", 4, 7, 4 + 7);
	return 0;
}
#include<iostream>
#include<vector>
#include<set>

int main()
{
	std::vector<int> vect{ 1, 2, 3, 4, 5, 6 };

	for (int i = 0; i < 6; ++i)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << std::endl;

	std::vector<int>::iterator it = vect.begin();
	while (it != vect.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;

	for (auto it = vect.begin(); it != vect.end(); it++)
	{
		*it = *it + 5;
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	for (auto element : vect)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;

	for (auto it = vect.cbegin(); it != vect.cend(); it++)
	{
		int element = *it;
		std::cout << element << " ";
	}
	std::cout << std::endl;

	std::set<int> myset;
	myset.insert(111); myset.insert(222); myset.insert(333); myset.insert(444); myset.insert(555);

	std::set<int>::iterator its = myset.begin();
	for (auto element : myset)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;

	for (auto it = vect.rend(); it != vect.rbegin(); it--)
	{;
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}
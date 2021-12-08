#include<iostream>

using namespace std;

class Student
{
public:
	static const int banana = 5;
	static int count;
	string name;
	int age;

	void print()
	{
		cout << name << "(" << age << ")" << endl;
	}
};

int Student::count = 0;

void print()
{
	static int banana = 5;
	++banana;
	cout << "BANANA : " << banana << endl;
}

int main(int argc, char* argv[])
{
	//int a = 0;
	Student st1{ "Bob", 32 };
	Student st2{ "John", 42 };
	Student st3{ "Bim", 59 };
	st1.count += 5;
	st2.count += 3;
	st3.count += 1;
	cout << st1.count << endl;
	Student::count = 5;

	cout << Student::count << endl;


	print();
	print();
	print();
	print();
	print();


	return EXIT_SUCCESS;
}
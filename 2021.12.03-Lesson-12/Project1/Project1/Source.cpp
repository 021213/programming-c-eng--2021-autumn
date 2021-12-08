#include<iostream>
#include<stdio.h>
#include<cstdio>

using namespace std;

class Student
{
public:
	string name;
	int age;

	Student(string name = "bob", int age = 20) : name(name), age(age)
	{
	}

	void print()
	{
		cout << name << "(" << age << ")" << endl;
	}

	void cprint() const
	{
		cout << name << "(" << age << ")" << endl;
	}
};

void printFunction(const Student& student)
{
	student.cprint();
}

int main(int argc, char* argv[])
{
	const int a = 5;
	Student st1("John");
	Student st2{"Tim", 42};

	const Student st3("Josh");

	st1.print();
	st2.print();
	st3.cprint();

	printFunction(st1);
	printFunction(st3);


	return EXIT_SUCCESS;
}
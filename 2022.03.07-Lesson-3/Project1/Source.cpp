#include<iostream>
#include<string>

using namespace std;

struct Student
{
	int id;
	string name;
	int birthDate;
	int* marks;
	int markscount;
	int markslength;

	Student(int id = 0, string name = "", int birthDate = 0)
	{
		this->id = id;
		this->name = name;
		this->birthDate = birthDate;
		this->markscount = 0;
		this->markslength = 10;
		this->marks = new int[this->markslength]{ 0 };
	}

	Student(Student& student)
	{
		this->id = student.id;
		this->name = student.name;
		this->birthDate = student.birthDate;
	}

	~Student()
	{
		delete[] this->marks;
	}
};

int main(int argc, char* argv)
{
	Student student1[10000];
	for (int i = 0; i < 10; ++i)
	{
		student1[i].id = i;
	}

	Student* student2 = new Student[10000];
	student2[44].id = 200;
	student2[44].name = "Barabana";
	student2[44].birthDate = 43245;
	delete[] student2;

	Student* student3 = new Student(100, "Banana", 43);

	student3[0].id = 300;
	(*student3).id = 400;
	student3->id = 500;

	delete student3;

	return 0;
}
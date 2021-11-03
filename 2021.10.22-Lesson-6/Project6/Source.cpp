#include<iostream>

using namespace std;

struct ArrayList {
	int* data;
	int length;
	int count;

	ArrayList(int length = 10)
		: data(new int[length] { 0 }), length(length), count(0)
	{
	}
	
	ArrayList(ArrayList& list)
		: data(new int[list.length]), length(list.length), count(list.count)
	{
		for (int i = 0; i < length; ++i)
		{
			data[i] = list.data[i];
		}
	}
	
	~ArrayList()
	{
		delete[] data;
	}

	void print()
	{
		cout << "[" << count << "/" << length << "] { ";
		for (int i = 0; i < count; ++i)
		{
			cout << data[i] << " ";
		}
		cout << "}" << endl;
	}

	void expand(int rate = 0)
	{
		if (rate == 0)
		{
			rate = length;
		}
		int* newA = new int[length + rate]{ 0 };
		for (int i = 0; i < length; ++i)
		{
			newA[i] = data[i];
		}
		delete[] data;
		data = newA;
		length += rate;
	}

	void push_back(int element)
	{
		if (count == length)
		{
			expand();
		}
		data[count] = element;
		++count;
	}
};

int main(int argc, char* argv[])
{
	ArrayList list(2);
	list.print();
	list.push_back(5);
	list.push_back(3);
	list.print();
	list.push_back(7);
	list.push_back(1);
	list.print();
	list.push_back(98);
	list.print();
	list.push_back(45);
	list.print();
	return EXIT_SUCCESS;
}
#include<iostream>
#include<string>

using namespace std;

/*
1. Abstraction
2. Incapsulation
*/

class ArrayList {
private:
	int count;
	int capacity;
	int* data;

	void assignArrayList(ArrayList& list)
	{
		this->capacity = list.count;
		this->count = list.count;
		this->data = new int[list.count]{ 0 };
		for (int i = 0; i < list.count; ++i)
		{
			this->data[i] = list.data[i];
		}
	}

	bool indexValid(int index)
	{
		return (index >= 0 && index < count);
	}

	void expand(int expandRate = 0)
	{
		if (expandRate == 0)
		{
			expandRate = capacity;
		}
		int* newData = new int[capacity + expandRate]{ 0 };
		for (int i = 0; i < count; ++i)
		{
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		capacity += expandRate;
	}

public:
	ArrayList(int capacity = 10) : count(0), capacity(capacity), data(new int[capacity] { 0 }) {};

	ArrayList(ArrayList& list)
	{
		assignArrayList(list);
	}

	~ArrayList()
	{
		delete[] this->data;
	}

	bool operator==(ArrayList& list)
	{
		if (list.count != count)
		{
			return false;
		}
		for (int i = 0; i < count; ++i)
		{
			if (list.data[i] != data[i])
			{
				return false;
			}
		}
		return true;
	}

	ArrayList& operator=(ArrayList& list)
	{
		delete[] this->data;
		assignArrayList(list);
		return *this;
	}
	
	void push_back(int value)
	{
		if (count == capacity)
		{
			expand();
		}
		data[count] = value;
		++count;
	}

	void push_forward(int value)
	{
		if (count == capacity)
		{
			expand();
		}
		for (int i = count; i > 0; --i)
		{
			data[i] = data[i - 1];
		}
		++count;
		data[0] = value;
	}

	ArrayList& operator+= (int value)
	{
		push_back(value);
		return (*this);
	}

	ArrayList& operator+= (ArrayList& list)
	{
		int length = list.count;
		if (capacity < count + list.count)
		{
			expand(count + list.count - capacity + 1);
		}

		for (int i = 0; i < length; ++i)
		{
			push_back(list.data[i]);
		}

		return (*this);
	}

	friend ArrayList& operator+= (int value, ArrayList& list)
	{
		list.push_forward(value);
		return list;
	}

	int& operator[](int index)
	{
		int a = 4;
		if (!indexValid(index))
		{
			if (index < 0)
			{
				index = 0;
			}
			if (index >= count)
			{
				index = count;
				if (count == capacity)
				{
					expand();
				}
				++count;
			}
		}
		return data[index];
	}

	friend ostream& operator<< (ostream& stream, const ArrayList& list)
	{
		stream << "[" << list.count << "/" << list.capacity << "] { ";
		for (int i = 0; i < list.count; ++i)
		{
			stream << list.data[i] << " ";
		}
		stream << "}";
		return stream;
	}

	int getCount() //getter
	{
		return count;
	}

	void setCount(int newCount) //setter
	{
		if (count >= newCount)
		{
			count = newCount;
		}
	}
};

int main()
{
	ArrayList list(2);
	list += 3;
	list += 5;
	ArrayList list2(5);
	list2 += 8;
	cout << list2 << endl;
	list2 = list;
	cout << list2 << endl;
	list += 4;
	list += 3;

	for (int i = 0; i < list.getCount(); ++i)
	{
		cout << list[i] << " ";
	}
	cout << endl;
	list += 3;
	list += 3;
	list += 3;
	list += 3;
	list += 3;
	cout << list << endl;
	list.setCount(6);
	cout << list << endl;
	return EXIT_SUCCESS;
}
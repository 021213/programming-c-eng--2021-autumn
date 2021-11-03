#include<iostream>
#include<string>

using namespace std;

struct ArrayList {
	int count;
	int capacity;
	int* data;

	ArrayList(int capacity = 10) : count(0), capacity(capacity), data(new int[capacity] { 0 }) {};
	
	ArrayList(ArrayList& list)
	{
		this->capacity = list.capacity;
		this->count = list.count;
		this->data = new int[list.capacity]{ 0 };
		for (int i = 0; i < list.count; ++i)
		{
			this->data[i] = list.data[i];
		}
	}
	
	~ArrayList()
	{
		delete[] this->data;
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

	void print()
	{
		cout << "[" << count << "/" << capacity << "] { ";
		for (int i = 0; i < count; ++i)
		{
			cout << data[i] << " ";
		}
		cout << "}" << endl;
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

	string toString()
	{
		string str;
		str += "[";
		str += capacity;
		str += "/";
		str += count;
		str += "] {";
		str += "}";
		return str;
	}
};

int main()
{
	ArrayList list(2);
	cout << list << endl;
	list += 2;
	cout << list << endl;
	list += 3;
	cout << list << endl;
	list += 4;
	cout << list << endl;
	(list += 5) += 6;
	cout << list << endl;
	list += list;
	cout << list << endl;
	list[10] = 7;
	cout << list << endl;
	list[11] = 3;
	cout << list << endl;
	list[50] = 9;
	4 += list;
	cout << list << endl;
	return EXIT_SUCCESS;
}
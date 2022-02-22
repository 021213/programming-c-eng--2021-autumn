#pragma once
#include<ostream>

typedef unsigned long long ulong;

class ArrayList
{
private:
	ulong* data;
	int length;

public:
	ArrayList(int length = 10) : data(new ulong[length]{ 0 }), length(length) {}
	ArrayList(const ArrayList& list);
	~ArrayList() { delete[] data; }

	int size();
	void mix();
	bool isSorted();
	ulong& operator[](int i);
	static void swap(ulong& a, ulong& b);
	friend std::ostream& operator<<(std::ostream& stream, ArrayList& list)
	{
		stream << "[" << list.length << "] : ";
		for (int i = 0; i < list.length; ++i)
		{
			stream << list.data[i] << " ";
		}
		stream << std::endl;
		return stream;
	}
};


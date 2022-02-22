#include "ArrayList.h"

void ArrayList::swap(ulong& a, ulong& b)
{
	ulong c = a;
	a = b;
	b = c;
}

ulong ArrayList::getBit(ulong a, int bitCount)
{
	/*
			  2
			  !  
		0011 0111
			  !
		0011 0111 << (8 - 1 - 2)
		!
		1110 0000 >> (8 - 1)
			    !
		0000 0001
	*/
	ulong bit = a << (8 * sizeof(ulong) - 1 - bitCount);
	bit = bit >> (8 * sizeof(ulong) - 1);
	return bit;
}

ArrayList::ArrayList(const ArrayList& list)
{
	this->length = list.length;
	data = new ulong[length];
	for (int i = 0; i < length; ++i)
	{
		data[i] = list.data[i];
	}
}

void ArrayList::bitwiseSort()
{
	ulong* buffer = new ulong[length]{ 0 };

	for (int bit = 0; bit < 8 * sizeof(ulong); ++bit)
	{
		int count = 0;
		for (int i = 0; i < length; ++i)
		{
			count += getBit(data[i], bit);
		}
		int index[2]{ 0, length - count };

		for (int i = 0; i < length; ++i)
		{
			buffer[index[getBit(data[i], bit)]++] = data[i];
		}
		ulong* temp = buffer;
		buffer = data;
		data = temp;
	}

	delete[] buffer;
}

int ArrayList::size()
{
	return length;
}

void ArrayList::mix()
{
	for (int i = 0; i < length; ++i)
	{
		swap(data[i], data[rand() % length]);
	}
}

bool ArrayList::isSorted()
{
	for (int i = 0; i < length - 1; ++i)
	{
		if (data[i] > data[i + 1])
		{
			return false;
		}
	}
	return true;
}

ulong& ArrayList::operator[](int i)
{
	return data[i];
}

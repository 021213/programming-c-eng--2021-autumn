#include "ArrayList.h"

void ArrayList::swap(ulong& a, ulong& b)
{
	ulong c = a;
	a = b;
	b = c;
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
		if(data[i] > data[i + 1])
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

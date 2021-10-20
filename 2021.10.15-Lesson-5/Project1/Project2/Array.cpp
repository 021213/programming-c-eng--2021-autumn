#include "Array.h"

Array::~Array()
{
	delete[] data;
}

Array::Array(Array& arr)
{
	this->length = arr.length;
	this->data = new int[arr.length]{ 0 };
}
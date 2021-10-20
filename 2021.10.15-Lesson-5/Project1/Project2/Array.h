#pragma once

struct Array
{
	int* data;
	int length;

	Array(int length = 10) : data(new int[length] { 0 }), length(length) {};
	Array(Array& arr);
	~Array();

};


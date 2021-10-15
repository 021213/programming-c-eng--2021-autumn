#include<iostream>

using namespace std;
/*

7
1 0
2 0
3 2
4 2
5 3
6 3
7 4
3

0
	1
	2
		3
			5
			6
		4
			7
*/

int countMessages(int** messages, int n, int sourceMessage)
{
	int count = 0;

	for (int i = 0; i < n; ++i)
	{
		if (sourceMessage == messages[i][0])
		{
			++count;
		}
		if (sourceMessage == messages[i][1])
		{
			count += countMessages(messages, n, messages[i][0]);
		}
	}

	return count;
}

int main(int argc, char* argv[])
{
	int n = 0;
	cin >> n;

	/*
	int message[1000][2];
	for (int i = 0; i < n; ++i)
	{
		cin >> message[i][0] >> message[i][1];
	}
	*/

	int** messages = nullptr;
	messages = new int* [n] { 0 };
	for (int i = 0; i < n; ++i)
	{
		int a = 0;
		int b = 0;
		cin >> a >> b;
		messages[i] = new int[2]{ a, b };
	}
	
	int sourceMessage = 0;
	cin >> sourceMessage;

	cout << countMessages(messages, n, sourceMessage);

	for (int i = 0; i < n; ++i)
	{
		delete[] messages[i];
	}
	delete[] messages;

	return EXIT_SUCCESS;
}
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	//string rpn = "12+4*3+";
	string rpn = "13+4*23-5*-";
	stack<int> s;
	for (int i = 0; i < rpn.length(); ++i)
	{
		char c = rpn[i];
		if (isdigit(c))
		{
			int num = c - '0';
			s.push(num);
		}
		else
		{
			int op1 = s.top();
			s.pop();
			int op2 = s.top();
			s.pop();
			switch (c)
			{
			case '+': s.push(op2 + op1); break;
			case '-': s.push(op2 - op1); break;
			case '*': s.push(op2 * op1); break;
			case '/': s.push(op2 / op1); break;
			}
		}
	}
	cout << s.top();

	return 0;
}
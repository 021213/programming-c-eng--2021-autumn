#include<iostream>
#include<stack>
#include<string>

/*
(1+2)*4+3 -> 2 1 + 4 * 3 + -> 15
(1+3)*4-(2-3)*5 -> 1 3 + 4 * 2 3 - 5 * - -> 21
*/

using namespace std;

int main()
{
	// rpn -> number
	//string rpn = "21+4*3+";
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
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();
			int res = 0;
			switch (c)
			{
			case '+': res = op1 + op2; break;
			case '-': res = op1 - op2; break;
			case '*': res = op1 * op2; break;
			case '/': res = op1 / op2; break;
			case '%': res = op1 % op2; break;
			}
			s.push(res);
		}
	}
	cout << rpn << " -> " << s.top();
	return EXIT_SUCCESS;
}
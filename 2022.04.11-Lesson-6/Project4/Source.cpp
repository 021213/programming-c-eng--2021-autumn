#include<iostream>
#include<stack>
#include<string>

/*
(1+2)*4+3 -> 21+4*3+ -> 15
(1+3)*4-(2-3)*5 -> 13+4*23-5*- -> 21
*/

using namespace std;

int priority(char op)
{
	switch (op)
	{
	case '+': case '-':
		return 2;
	case '*': case '/': case '%':
		return 1;
	default:
		return 0;
	}
}

int main()
{
	//string expr = "(2+1)*4+3";
	string expr = "(3-2*4-5)*3-(1*4+5)%2";
	string rpn1 = "324*-5-3*14*5+2%-";
	string rpn = "";
	stack<int> s;
	for (int i = 0; i < expr.length() + 1; ++i)
	{
		char c = expr[i];
		if (isdigit(c))
		{
			rpn += c;
		}
		else if (c == '(')
		{
			s.push(c);
		}
		else if (c == '\0')
		{
			while (!s.empty())
			{
				rpn += s.top();
				s.pop();
			}
		}
		else if (c == ')')
		{
			while (s.top() != '(')
			{
				rpn += s.top();
				s.pop();
			}
			s.pop();
		}
		else
		{
			while (!s.empty() && s.top() != '(' && priority(c) >= priority(s.top()))
			{
				rpn += s.top();
				s.pop();
			}
			s.push(c);
		}
	}
	cout << rpn1 << endl;
	cout << rpn << endl;
	return EXIT_SUCCESS;
}
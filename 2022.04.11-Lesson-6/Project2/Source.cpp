#include<iostream>
#include<stack>
#include<string>

using namespace std;

int priority(char op)
{
	if (op == '(') return 3;
	if (op == '+') return 2;
	if (op == '-') return 2;
	if (op == '/') return 1;
	if (op == '*') return 1;
	return 0;
}

int main()
{
	string str = "(1+3)*4-(2-3)*5";
	string rpn = "";
	cout << str << endl;
	stack<char> sop;
	for (int i = 0; i < str.length() + 1; ++i)
	{
		char c = str[i];
		if (isdigit(c))
		{
			rpn += c;
		}
		else
		{
			if (c == '(')
			{
				sop.push(c);
			}
			else if (c == ')')
			{
				while (sop.top() != '(')
				{
					rpn += sop.top();
					sop.pop();
				}
				sop.pop();
			}
			else if (c == '\0')
			{
				while (!sop.empty())
				{
					rpn += sop.top();
					sop.pop();
				}
			}
			else
			{
				while (!sop.empty() && priority(c) > priority(sop.top()) && sop.top() != '(')
				{
					rpn += sop.top();
					sop.pop();
				}
				sop.push(c);
			}
		}
	}
	cout << rpn << endl;

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
#include<iostream>
#include<stack>
#include<queue>
#include<string>

using namespace std;

enum MathType {
	VALU,
	OPER,
	NONE
};

struct MathElement
{
private:
	MathType type;
	char oper;
	int value;

public:
	MathElement()
	{
		oper = ' ';
		value = 0;
		type = NONE;
	}

	MathElement(char op)
	{
		oper = op;
		value = 0;
		type = OPER;
	}

	MathElement(int val)
	{
		oper = ' ';
		this->value = val;
		type = VALU;
	}

	MathElement(const MathElement& el) : oper(el.oper), value(el.value), type(el.type) {}

	~MathElement()
	{
		oper = ' ';
		value = 0;
		type = NONE;
	}

	char getOper()
	{
		return oper;
	}

	MathType getType()
	{
		return type;
	}

	int priority()
	{
		switch (oper)
		{
		case '+': case '-':
			return 2;
		case '*': case '/': case '%':
			return 1;
		default:
			return 0;
		}
	}

	MathElement calc(MathElement& op1, MathElement& op2)
	{
		switch (oper)
		{
		case '+': return MathElement(op1.value + op2.value);
		case '-': return MathElement(op1.value - op2.value);
		case '*': return MathElement(op1.value * op2.value);
		case '/': return MathElement(op1.value / op2.value);
		case '%': return MathElement(op1.value % op2.value);
		default: return 0;
		}
	}

	int getValue()
	{
		return value;
	}

	bool isValue()
	{
		return type == VALU;
	}

	bool isOper()
	{
		return type == OPER;
	}
};

/*create a class that turns expression string into a number using the Reverse Polish notation*/

queue<MathElement> ExprToMathElementQueue(string expr)
{
	queue<MathElement> res;
	bool flag = false;
	int num = 0;
	for (int i = 0; i < expr.length() + 1; ++i)
	{
		if (expr[i] == ' ')
		{
			continue;
		}
		if (isdigit(expr[i]))
		{
			num = 10 * num + expr[i] - '0';
			flag = true;
		}
		else
		{
			if (flag)
			{
				res.push(MathElement(num));
				flag = false;
				num = 0;
			}
			if (expr[i] != '\0')
			{
				res.push(MathElement(expr[i]));
			}
		}
	}
	return res;
}

queue<MathElement> ElementQueueToRpnQueue(queue<MathElement> expQ)
{
	queue<MathElement> res;
	stack<MathElement> ops;
	while (!expQ.empty())
	{
		MathElement el = expQ.front();
		expQ.pop();
		if (el.isValue())
		{
			res.push(el);
		}
		else if (el.getOper() == '(')
		{
			ops.push(el);
		}
		else if (el.getOper() == ')')
		{
			while (ops.top().getOper() != '(')
			{
				res.push(ops.top());
				ops.pop();
			}
			ops.pop();
		}
		else
		{
			while (!ops.empty() && ops.top().getOper() != '(' && el.priority() >= ops.top().priority())
			{
				res.push(ops.top());
				ops.pop();
			}
			ops.push(el);
		}
	}
	while (!ops.empty())
	{
		res.push(ops.top());
		ops.pop();
	}
	return res;
}

int CalcRpn(queue<MathElement> rpnQ)
{
	stack<MathElement> s;
	while(!rpnQ.empty())
	{
		MathElement el = rpnQ.front();
		rpnQ.pop();
		if (el.isValue())
		{
			s.push(el);
		}
		else
		{			
			MathElement op2 = s.top();
			s.pop();
			MathElement op1 = s.top();
			s.pop();
			s.push(el.calc(op1, op2));
		}
	}
	return s.top().getValue();
}

int main()
{
	string expr = "12 + 51 * (100 - 94)";
	queue<MathElement> expQ = ExprToMathElementQueue(expr);
	queue<MathElement> rpnQ = ElementQueueToRpnQueue(expQ);
	cout << CalcRpn(rpnQ) << endl;
	return EXIT_SUCCESS;
}
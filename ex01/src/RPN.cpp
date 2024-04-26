#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &a) {
	std::cout << "copy contructor called" << std::endl;
	*this = a;
}

RPN	&RPN::operator=(const RPN &a) {
	std::cout << "copy assignment operator called" << std::endl;
	this->stack = a.stack;
	return (*this);
}

RPN::~RPN() {}

void	RPN::plus(int a, int b)
{
	stack.push(a + b);
}

void	RPN::minus(int a, int b)
{
	stack.push(a - b);
}

void	RPN::multiply(int a, int b)
{
	stack.push(a * b);
}

void	RPN::divide(int a, int b)
{
	stack.push(a * b);
}

bool isNum(const std::string &a)
{
	std::string::const_iterator it = a.begin();
	while (it != a.end() && std::isdigit(*it))
		++it;
	return (!a.empty() && it == a.end());
}

bool isValid(const char c)
{
	if (c < 48 || c > 57)
	{
		if (c != 42 && c != 43 && c != 45 && c != 47)
			throw RPN::Error();
	}
	return (1);
}

RPN::RPN(std::string &arg)
{
	std::string str;
	int i, a, b = 0;
	void	(RPN::*funct[])(int a, int b) = {&RPN::plus, &RPN::minus, &RPN::multiply, &RPN::divide};
	std::string arr[] = {"+", "-", "*", "/"};
	for (int x = 0; x < (int)arg.size() + 1; x++)
	{
		if (arg[x] != ' ' && arg[x])
		{
			if (isValid(arg[x]))
				str.push_back(arg[x]);
			i = 0;
			while (i < 4 && arr[i].compare(str))
				i++;
			if (i < 4)
			{
				a = stack.top();
				stack.pop();
				b = stack.top();
				stack.pop();
				(this->*funct[i])(b, a);
			}
		}
		else
		{
			if (isNum(str))
				stack.push(std::atoi(str.c_str()));
			str.clear();
		}
	}
	std::cout << stack.top() << std::endl;
}

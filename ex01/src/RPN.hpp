#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <stack>

class RPN {
	private:
		std::stack<int>stack;

	public:
		RPN();
		RPN(std::string &arg);
		RPN(const RPN &a);
		RPN	&operator=(const RPN &a);
		~RPN();
		void	plus(int a, int b);
		void	minus(int a, int b);
		void	multiply(int a, int b);
		void	divide(int a, int b);
		class Error	: public std::exception
		{
			virtual const char *what() const throw()
			{
				return "Error!";
			}
		};
};

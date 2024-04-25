#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
	private:
			std::map<std::string, double> _record;

	public:
			BitcoinExchange();
			BitcoinExchange(std::string filename);
			BitcoinExchange(const BitcoinExchange &a);
			BitcoinExchange	&operator=(const BitcoinExchange &a);
			~BitcoinExchange();
			void	openFile();
			class	OpenFail : public std::exception
			{
				virtual	const char *what() const throw()
				{
					return "Unable to open file.";
				}
			};
};

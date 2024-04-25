#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string filename) {
	BitcoinExchange::openFile();
	int x = 0;
	std::ifstream file (filename.c_str());
	if (!file)
		throw	BitcoinExchange::OpenFail();
	std::string line;
	while (std::getline(file, line))
	{
		if (x++ == 0)
			continue;
		std::stringstream ss(line);
		std::string date;
		double	value;
		if (std::getline(ss, date, '|') && ss >> value)
		{
			std::map<std::string, double>::reverse_iterator rit(_record.lower_bound(date));
			if (rit == _record.rend())
			{
				std::cout << date << "not found in the map." << std::endl;
			}
			else if (value < 0)
				std::cout << "Error: not positive number." << std::endl;
			else if (value > 1000)
				std::cout << "Error: too large a number." << std::endl;
			else
				std::cout << date << "=> " << value << " = " << rit->second * value << std::endl;
		}
		else
			std::cout << "Error: bad input => " << date << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &a) {
	std::cout << "Copy contructor called" << std::endl;
	*this = a;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &a) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &a) {
		this->_record = a._record;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::openFile() {
	int x = 0;
	std::fstream file;
	file.open("./data.csv", std::ios::in);
	std::map<std::string, double> row;
	std::string temp, key, word;
	while (file >> temp)
	{
		if (x++ == 0)
			continue;
		bool iskey = false;
		std::stringstream s(temp);
		while (getline(s, word, ','))
		{
			if (iskey == false)
			{
				key = word;
				iskey = true;
			}
			else
				row[key] = std::atof(word.c_str());
		}
	}
	this->_record = row;
}


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string nameDB, std::string inputFile)
{
	this->_nameDB = nameDB;
	this->_inputFile = inputFile;
	this->databaseFilling(",");
	this->processInputFileAndPrintProduct("|");
}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	this->_sql = other._sql;
	return (*this); 
}

std::string const &BitcoinExchange::getNameDB() const
{
	return this->_nameDB;
}

std::string const &BitcoinExchange::getInputFile() const
{
	return this->_inputFile;
}

void BitcoinExchange::setNameDB(std::string const &nameDB)
{
	this->_nameDB = nameDB;
}

void BitcoinExchange::setInputFile(std::string const &inputFile)
{
	this->_nameDB = inputFile;
}


void BitcoinExchange::databaseFilling(const std::string &split)
{
	time_t dataF;
    std::ifstream archivo(_nameDB);
    if (!archivo.is_open()) {
        std::cout << "Error loading file Data";
        return;
    }

    std::string line;
	std::getline(archivo, line);
    while (std::getline(archivo, line))
    {
        size_t splitPos = line.find(split);
        std::string date = line.substr(0, splitPos);
        std::string value_str = line.substr(splitPos + split.length());
        float value = std::atof(value_str.c_str());
		dataF = this->formatData(date);
		if (dataF > 0)
        	this->InsertDat(dataF, value);
    }

    archivo.close();
}

time_t BitcoinExchange::formatData(const std::string& date)
{
    struct tm tm;
    memset(&tm, 0, sizeof(struct tm));
    char* result = strptime(date.c_str(), "%Y-%m-%d", &tm);

    if (result == NULL || *result != '\0')
        return -1;

    time_t time = mktime(&tm);

    if (time == (time_t)-1)
        return -1;

    return time;
}

void BitcoinExchange::InsertDat(time_t date, float price)
{
	this->_sql.insert(std::pair<time_t, float>(date, price));
}

float BitcoinExchange::searchByDate(time_t date) {
    if (_sql.empty()) {
        return 0.0;
    }
    
    std::map<time_t, float>::iterator iter = _sql.lower_bound(date);

    if (iter == _sql.begin()) {
        return iter->second;
    }

    if (iter == _sql.end() || iter->first != date) {
        --iter;
    }

    return iter->second;
}

//

void BitcoinExchange::processInputFileAndPrintProduct(std::string split)
{
	float result;
	time_t dataF;
    std::ifstream archivo(_inputFile);

    if (!archivo.is_open()) {
        std::cout << "Error loading Input";
        return;
    }

    std::string line;
	std::getline(archivo, line);
    while (std::getline(archivo, line))
    {
        size_t splitPos = line.find(split);
        std::string date = this->trim(line.substr(0, splitPos));
        std::string value_str = line.substr(splitPos + split.length());
        float value = std::atof(value_str.c_str());
		dataF = this->formatData(date);
		if (dataF > 0)
		{
			result = this->searchByDate(dataF) * value;
			if (value > 1000)
			{
				std::cout << "Error: too large a number." << std::endl;
			}
			else if (result >= 0)
				std::cout << date << " => " << value << " = " << result << std::endl;
			else
				std::cout << "Error: not a positive number." << std::endl;
		} else  {
			std::cout << "Error: bad input => " << date << std::endl;
		}
    }
    archivo.close();
}

std::string BitcoinExchange::trim(const std::string& str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && std::isspace(*it)) {
        ++it;
    }

    std::string::const_reverse_iterator rit = str.rbegin();
    while (rit.base() != it && std::isspace(*rit)) {
        ++rit;
    }

    return std::string(it, rit.base());
}
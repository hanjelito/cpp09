#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <ctime>
#include <map>
#include <fstream>

class BitcoinExchange
{
	private:
		std::string _nameDB;
		std::string _inputFile;
		std::map<time_t, float> _sql;
		BitcoinExchange();
	public:
		BitcoinExchange(std::string nameDB, std::string inputFile);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		std::string const &getNameDB() const;
		std::string const &getInputFile() const;

		void setNameDB(std::string const &nameDB);
		void setInputFile(std::string const &inputFile);

		//DB time
		time_t formatData(std::string const &date);
		void InsertDat(time_t date, float price);
		void databaseFilling(const std::string& split);
		float searchByDate(time_t date);
		//compare
		void processInputFileAndPrintProduct(std::string split);
		std::string trim(const std::string& str);
};

#endif
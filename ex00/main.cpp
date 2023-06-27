#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: could not open file.\n";
		return (1);
	}

	BitcoinExchange data("data.csv", argv[1]);
	return (0);
}

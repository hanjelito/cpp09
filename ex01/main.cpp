#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: invalid arguments." << std::endl;
		return (1);
	}
	RPN operation(argv[1]);
	std::cout << operation << std::endl;
	return (0);
}
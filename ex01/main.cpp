#include "RPN.hpp"

int main(int narg, char **xarg)
{
	if (narg != 2)
	{
		std::cout << "Error: invalid arguments." << std::endl;
		return (1);
	}
	RPN operation(xarg[1]);
	std::cout << operation << std::endl;
	return (0);
}
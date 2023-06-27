#ifndef RPN_HPP
#define RPN_HPP

#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include <sstream>

class RPN
{
private:
	std::stack<int> _stck;

	void clearStack();
	bool isOperator(const std::string &token);
	int calculateOperation(const std::string &operation);

public:
	RPN();
	RPN(const std::string &data);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	virtual ~RPN();

	int calculator(const std::string &data);
	std::stack<int> getInfo() const;
};

std::ostream& operator<<(std::ostream &out, const RPN &rpn);

#endif
#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(char *data)
{
	char *token = std::strtok(data, " ");

	while (token != NULL)
	{
		if (this->calculator(token))
		{
			this->clearStck();
			return ;
		}
		token = std::strtok(NULL, " ");
	}
}

RPN::RPN(RPN const &other)
{
	*this = other;
}

RPN &RPN::operator=(RPN const &other)
{
	if (this != &other)
	{
		this->_stck = other.getInfo();
	}
	return (*this);
}

RPN::~RPN() { }

int RPN::calculator(char *data)
{
	int err = 0;

	// Validate element.
	if (this->validate(data))
	{
		this->clearStck();
		return (1);
	}
	
	// Choose operation.
	char element = data[0];
	if (element == '+')
		err = this->addition();
	else if (element == '-')
		err = this->subtraction();
	else if (element == '*')
		err = this->multiplication();
	else if (element == '/')
		err = this->division();
	else
		this->_stck.push(atoi(data));

	// Manage operator errors.
	if (err != 0)
	{
		this->clearStck();
		return (1);
	}

	return (0);
}

int RPN::validate(char *token)
{
	char c;
	if(strlen(token) > 1)
		return (1);
	c = token[0];
	if ((c < '0' || c > '9') && (c != '+' && c != '-' && c != '*' && c != '/'))
		return (1);
	return (0);
}

int RPN::addition()
{
	int first;
	int last;

	// Checking valid number of elements to operate.
	if (this->_stck.size() < 2)
		return (1);

	last = this->_stck.top();
	this->_stck.pop();
	first = this->_stck.top();
	this->_stck.pop();
	this->_stck.push(first + last);
	return (0);
}

int RPN::subtraction()
{
	int first;
	int last;

	// Checking valid number of elements to operate.
	if (this->_stck.size() < 2)
		return (1);

	last = this->_stck.top();
	this->_stck.pop();
	first = this->_stck.top();
	this->_stck.pop();
	this->_stck.push(first - last);
	return (0);
}

int RPN::multiplication()
{
	int first;
	int last;

	// Checking valid number of elements to operate.
	if (this->_stck.size() < 2)
		return (1);

	last = this->_stck.top();
	this->_stck.pop();
	first = this->_stck.top();
	this->_stck.pop();
	this->_stck.push(first * last);
	return (0);
}

int RPN::division()
{
	int first;
	int last;

	// Checking valid number of elements to operate.
	if (this->_stck.size() < 2)
		return (1);

	last = this->_stck.top();
	this->_stck.pop();
	first = this->_stck.top();
	this->_stck.pop();

	// Checking for indertemination in division.
	if (last == 0)
		return (1);

	this->_stck.push(first / last);
	return (0);
}

std::stack<int> RPN::getInfo() const
{
	return (this->_stck);
}

void RPN::clearStck()
{
	while (!this->_stck.empty())
		this->_stck.pop();
	return ;
}

std::ostream& operator << (std::ostream &out, const RPN &rpn)
{
	std::stack<int> aux = rpn.getInfo();

	if (!aux.empty())
	{
		if  (aux.size() > 1)
			out << "Error";
		while (!aux.empty())
		{
			out << aux.top();
			aux.pop();
		}
	}
	else
		out << "Error";
	return (out);
}
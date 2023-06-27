#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(const std::string &data)
{
    std::istringstream iss(data);
    std::string token;
    
    while (iss >> token)
    {
        if (this->calculator(token)) 
        {
            this->clearStack();
            return;
        }
    }
}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->_stck = other.getInfo();
    }
    return *this;
}

RPN::~RPN() { }

int RPN::calculator(const std::string &data)
{
    try {
        if (!isOperator(data)) {
            this->_stck.push(std::stoi(data));
            return 0;
        }
    } catch (const std::invalid_argument& ia) {
        return 1;
    }
    
    return this->calculateOperation(data);
}

bool RPN::isOperator(const std::string &token)
{
    return token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

int RPN::calculateOperation(const std::string &operation)
{
    if (_stck.size() < 2)
        return 1;

    int last = _stck.top();
    _stck.pop();
    int first = _stck.top();
    _stck.pop();

    if(operation == "+") 
        _stck.push(first + last); 
    else if(operation == "-") 
        _stck.push(first - last);
    else if(operation == "*") 
        _stck.push(first * last); 
    else if(operation == "/") {
        if (last == 0)
            return 1;
        _stck.push(first / last); 
    }
    else 
        return 1;

    return 0;
}

void RPN::clearStack()
{
    while (!_stck.empty())
        _stck.pop();
}

std::stack<int> RPN::getInfo() const
{
    return _stck;
}

std::ostream& operator<<(std::ostream &out, const RPN &rpn)
{
    std::stack<int> aux = rpn.getInfo();

    if (aux.empty())
        out << "Error";
    else if (aux.size() > 1)
        out << "Error";
    else
        out << aux.top();
    
    return out;
}
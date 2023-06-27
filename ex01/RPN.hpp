#ifndef RPN_HPP
# define RPN_HPP

# include <cstdlib>
# include <iostream>
# include <string>
# include <cctype>

# include <stack>

class RPN
{
	private:
		std::stack<int> _stck;

		void clearStck();

	public:
		RPN();
		RPN(char *data);
		RPN(RPN const &other);
		RPN &operator=(RPN const &other);
		virtual ~RPN();

		int calculator(char *data);
		int validate(char *token);

		int addition();
		int subtraction();
		int multiplication();
		int division();

		std::stack<int> getInfo() const;
};

std::ostream& operator << (std::ostream &out, const RPN &rpn);

#endif
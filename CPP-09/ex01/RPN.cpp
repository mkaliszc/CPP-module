# include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

void	RPN::handleTIME() {
	if (_value.size() < 2)
		throw RPN::NotEnoughValue();
	
	double nb1 = _value.top();
	_value.pop();

	double nb2 = _value.top();
	_value.pop();

	_value.push(nb1 * nb2);
}

void	RPN::handleSUB() {
	if (_value.size() < 2)
		throw RPN::NotEnoughValue();
	
	double nb1 = _value.top();
	_value.pop();

	double nb2 = _value.top();
	_value.pop();

	_value.push(nb1 - nb2);
}

void	RPN::handleDIVIDE() {
	if (_value.size() < 2)
		throw RPN::NotEnoughValue();
	
	double nb1 = _value.top();
	_value.pop();

	double nb2 = _value.top();
	_value.pop();

	if (nb1 == 0)
		throw RPN::DivideBy0();
	_value.push(nb2 / nb1);
}

void	RPN::handleADD() {
	if (_value.size() < 2)
		throw RPN::NotEnoughValue();
	
	double nb1 = _value.top();
	_value.pop();

	double nb2 = _value.top();
	_value.pop();

	_value.push(nb1 + nb2);
}

const char*	RPN::NotEnoughValue::what() const throw() {
	return("Error: Not enough value in stack.\n");
}

const char*	RPN::InvalidInput::what() const throw() {
	return("Error: invalid input.\n");
}

const char*	RPN::DivideBy0::what() const throw() {
	return("Error: Trying division by 0 !\n");
}

void	RPN::calculate(std::string args)
{
	try
	{
		if (args.empty())
			throw RPN::InvalidInput();

		char	operations[] = {'+', '-', '/', '*'};
		void	(RPN::*Func[])() = { &RPN::handleADD, &RPN::handleSUB, &RPN::handleDIVIDE, &RPN::handleTIME};

		for (size_t i = 0; i < args.size(); i++)
		{
			if (args[i] && args[i] != '-' && args[i] != '/' && args[i] != '+' && args[i] != '*' && !std::isdigit(args[i]) && args[i] != ' ')
				throw RPN::InvalidInput();
			else if (args[i] && args[i] == ' ')
				continue;
			else if (std::isdigit(args[i]))
				_value.push(args[i] - '0');
			else
			{
				for (size_t test = 0; test < 4; test++)
					if (args[i] == operations[test])
						(this->*Func[test])();
			}
		}
		if (_value.size() != 1)
			std::cout << "Error: Too much value in stack\n";
		else
		{
			std::cout << "Result = " << _value.top() << std::endl;
			_value.pop();
		}
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
}
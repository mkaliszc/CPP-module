/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:50:52 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/25 17:28:51 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

Span::Span() : _size(10) {
}

Span::Span(unsigned int N) : _size(N) {
}

Span::Span(const Span &other) 
{
	this->_size = other._size;
	for (size_t i = 0; i < _size; i++)
		_span[i] = other._span[i];
}

Span&	Span::operator=(const Span &src)
{
	if(this != &src)
	this->_size = src._size;
	for (size_t i = 0; i < _size; i++)
		_span[i] = src._span[i];
	return (*this);
}

Span::~Span() {
}

const char*	Span::NoSpaceLeft::what() const throw() {
	return ("Array is full\n");
}

const char*	Span::TooShort::what() const throw() {
	return ("Array too small for span calculation\n");
}

void	Span::addNumber(int N)
{
	if (this->_span.size() == this->_size)
		throw Span::NoSpaceLeft();
	else
		this->_span.push_back(N);
}

static int my_absolute(int value) {
	return (value < 0) ? value * -1 : value;
}

int	Span::shortestSpan()
{
	if (_span.size() < 2)
		throw Span::TooShort();

	int					ShortestSpan = std::numeric_limits<int>::max();
	std::vector<int>	_copy = this->_span;

	std::sort(_copy.begin(), _copy.end());
	for (size_t i = 0; i < _copy.size() - 1; i++)
	{
		if (my_absolute(_copy[i + 1] - _copy[i]) < ShortestSpan)
			ShortestSpan = my_absolute(_copy[i + 1] - _copy[i]);
	}
	
	return(ShortestSpan);
}

int	Span::longestSpan() {
	if (_span.size() < 2)
		throw Span::TooShort();
	return(*std::max_element(_span.begin(), _span.end()) - *std::min_element(_span.begin(), _span.end()));
}
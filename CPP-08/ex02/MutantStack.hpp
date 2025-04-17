/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:12:53 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/16 13:56:40 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <stack>
# include <deque>
# include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef	typename std::stack<T>::container_type::iterator	iterator;
		MutantStack() {}
		MutantStack(const MutantStack &src) : std::stack<T>(src) {
			*this = src;
		}
		MutantStack	&operator=(const MutantStack &src) {
			if (this != &src) {
				*this + src;
			}
			return(*this);
		}
		~MutantStack() {}

		iterator	begin();
		iterator	end();
		
};

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return(std::stack<T>::c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return(std::stack<T>::c.end());
}
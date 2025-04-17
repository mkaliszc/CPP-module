/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:44:23 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/17 17:41:31 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <cstdlib>
# include <ctime>


template<typename T>
class Array
{
	private:
		T				*array;
		const unsigned int	_size;

	public:
		Array() : array(NULL), _size(0) {
			this->array = new T[this->_size];
		}
		Array(unsigned int n) : _size(n) {
			this->array = new T[n]();
		}
		~Array() {
			delete [] this->array;
		}

		Array(const Array &src) : _size(src.size())
		{
			this->array = new T[src.size()];
			for (unsigned int i = 0; i < src.size(); i++)
				this->array[i] = src.array[i];
		}

		Array&	operator=(const Array &src)
		{
			if(this->array != NULL)
				delete (this->array);
			if(src.size() != 0 && this != &src)
			{
				this->_size = src.size();
				this->array = new T[src.size()];
				for (unsigned int i = 0; i < src.size(); i++)
					this->array[i] = src.array[i];
			}
			return(*this);	
		}

		T	&operator[](unsigned int index)
		{
			if (index >= this->_size)
				throw std::exception();
			return (array[index]);
		}

		const T	&operator[](unsigned int index) const
		{
			if (index >= this->_size)
				throw std::exception();
			return (array[index]);
		}

		unsigned int	size() const {
			return (this->_size);
		}
};
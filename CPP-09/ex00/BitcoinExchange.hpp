/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:09:43 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/17 20:18:55 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once 

# include <string>
# include <map>
# include "Date.hpp"

class BitcoinExchange
{
	private:
		std::map<Date, float> _data;
	public:
		BitcoinExchange(/* args */);
		~BitcoinExchange();
};

BitcoinExchange::BitcoinExchange(/* args */)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

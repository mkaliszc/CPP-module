/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Date.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:16:23 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/17 20:18:30 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>

class Date
{
	private:
		int	_year;
		int	_month;
		int	_day;

	public:
		Date();
		~Date();
};

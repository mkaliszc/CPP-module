/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:11:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/28 19:22:39 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <sstream>
# include <ctime>
# include <deque>
# include <vector>
# include <string>
# include <algorithm>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		time_t	_vectime;
		time_t	_deqtime;

		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);
	public:	
		PmergeMe();
		~PmergeMe();

		void	parsing(char **argv);
		void	vecSort();
		void	MergeVec(std::vector<int> &vec);
		void	deqSort();
};

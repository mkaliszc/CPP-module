/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:11:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/05/01 16:16:05 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <algorithm>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		double	_vectime;
		double	_deqtime;

		PmergeMe(const PmergeMe &src);
		PmergeMe& operator=(const PmergeMe &src);
	public:	
		PmergeMe();
		~PmergeMe();

		void	parsing(char **argv);
		void	vecSort();
		void	MergeVec(std::vector<int> &vec);
		void 	insertJacobSthal(std::vector<std::pair<int, int> >& pairs, std::vector<int>& result, std::vector<bool>& inserted);


		void	deqSort();
};

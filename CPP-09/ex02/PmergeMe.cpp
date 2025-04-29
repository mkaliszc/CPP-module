/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:11:50 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/28 20:11:19 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void	PmergeMe::parsing(char **argv)
{
	int	i = 0;

	std::cout << "Before: ";
	while (argv[i])
	{
		std::string	arg = argv[i];
		std::istringstream	test;
		int	nb;
		
		if (!(test >> nb) || nb < 0)
		{
			std::cout << "Error: invalid input: " << arg << std::endl;
			exit(1);
		}
		std::cout << nb;
		_vec.push_back(nb);
		_deq.push_back(nb);
	}
	std::cout << std::endl;
}

void	PmergeMe::vecSort()
{
	MergeVec(_vec);
}

void	PmergeMe::MergeVec(std::vector<int>& vec)
{
	std::vector<std::pair<int, int>>	pairs;
	
	for (size_t i = 0; i + 1< vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
		else
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}
	
	int	odd = -1;
	if (vec.size() % 2 != 0)
		odd = vec.back();
	
	std::vector<int>	bigs;
	for (size_t i = 0; i < pairs.size(); i++)
		bigs.push_back(pairs[i].second);

	MergeVec(bigs);
}
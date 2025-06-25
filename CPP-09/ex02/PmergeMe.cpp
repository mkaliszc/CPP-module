/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:11:50 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/06/25 18:13:24 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

void	PmergeMe::parsing(char **argv)
{
	int	i = 1;

	std::cout << "Before: ";
	while (argv[i])
	{
		std::string	arg = argv[i];
		std::istringstream	test(arg);
		int	nb;
		
		if (!(test >> nb) || nb < 0)
		{
			std::cout << "Error: invalid input: " << arg << std::endl;
			exit(1);
		}
		std::cout << nb << " ";
		_vec.push_back(nb);
		_deq.push_back(nb);
		i++;
	}
	std::cout << std::endl << std::endl;
}

template<typename Container>
Container getJacobsthalSequence(size_t n) {
    if (n == 0) return Container();
    
    Container order;
    
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(1);
    jacobsthal.push_back(3);
    
    size_t i = 2;
    while (jacobsthal.back() < n) {
        size_t next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        jacobsthal.push_back(next);
        i++;
    }
    
    size_t inserted = 0;
    for (size_t j = 0; j < jacobsthal.size() && inserted < n; j++) {
        size_t end = std::min(jacobsthal[j], n);
        size_t start = (j == 0) ? 1 : jacobsthal[j-1] + 1;
        
        for (size_t k = end; k >= start && k > 0; k--) {
            if (inserted < n) {
                order.push_back(k - 1);
                inserted++;
            }
        }
    }
    
    return order;
}

void    PmergeMe::DisplayResult()
{
    std::vector<int>::iterator	it = _vec.begin();
	std::cout << "After : ";
	while(it != _vec.end())
	{
		std::cout << *it << " ";
		it++;
	}
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : " 
              << std::fixed << std::setprecision(5) << _vectime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size() << " elements with std::deque : " 
              << std::fixed << std::setprecision(5) << _deqtime << " us" << std::endl;
}

/* 
* |||||||||||||| vector |||||||||||||||||||||||
*/

void	PmergeMe::vecSort()
{
    clock_t start = clock();
	MergeVec(_vec);
    clock_t end = clock();
    _vectime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void	PmergeMe::MergeVec(std::vector<int>& vec)
{
    if (vec.size() <= 1)
        return;

    // 1) et 2) paires
    std::vector<std::pair<int, int> > pairs;
    bool hasOdd = false;
    int oddElement = 0;

    for (size_t i = 0; i < vec.size(); i += 2) 
    {
        if (i + 1 < vec.size()) 
        {
            int first = vec[i];
            int second = vec[i + 1];
            if (first < second)
                pairs.push_back(std::make_pair(second, first));
            else
                pairs.push_back(std::make_pair(first, second));
        } 
        else 
        {
            hasOdd = true;
            oddElement = vec[i];
        }
    }

    // 3) Trie recursif des plus grands
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    MergeVec(mainChain);


    // 4) on remet les petit avant leur grands des paire dans les grands trier 
    int minElement = *std::min_element(mainChain.begin(), mainChain.end());

    int associatedSmall = 0;
    size_t indexOfMinPair = 0;
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        if (pairs[i].first == minElement) 
        {
            associatedSmall = pairs[i].second;
            indexOfMinPair = i;
            break;
        }
    }

    std::vector<int>::iterator it = mainChain.begin();
    while (it != mainChain.end() && *it != minElement)
        ++it;
    mainChain.insert(it, associatedSmall);

    std::vector<bool> inserted(pairs.size(), false);
    inserted[indexOfMinPair] = true;

	// 5) jacobsthal
    insertJacobSthalV(pairs, mainChain, inserted);

    if (hasOdd) 
    {
        std::vector<int>::iterator it = mainChain.begin();
        while (it != mainChain.end() && *it < oddElement)
            ++it;
        mainChain.insert(it, oddElement);
    }
    vec = mainChain;
}

void PmergeMe::insertJacobSthalV(std::vector<std::pair<int, int> >& pairs, 
                                 std::vector<int>& result, 
                                 std::vector<bool>& inserted) {
    
    std::vector<int> insertionOrder = getJacobsthalSequence<std::vector<int> >(pairs.size());
    
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        int idx = insertionOrder[i];
        if (idx < static_cast<int>(pairs.size()) && !inserted[idx]) {
            std::vector<int>::iterator it = std::lower_bound(
                result.begin(), result.end(), pairs[idx].second);
            result.insert(it, pairs[idx].second);
            inserted[idx] = true;
        }
    }
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (!inserted[i]) {
            std::vector<int>::iterator it = std::lower_bound(
                result.begin(), result.end(), pairs[i].second);
            result.insert(it, pairs[i].second);
        }
    }
}

/* 
* |||||||||||||| deque |||||||||||||||||||||||
*/

void	PmergeMe::deqSort()
{
    clock_t start = clock();
	MergeDeq(_deq);
    clock_t end = clock();
    _deqtime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

void	PmergeMe::MergeDeq(std::deque<int>& vec)
{
    if (vec.size() <= 1)
        return;

    // 1) et 2) paires
    std::deque<std::pair<int, int> > pairs;
    bool hasOdd = false;
    int oddElement = 0;

    for (size_t i = 0; i < vec.size(); i += 2) 
    {
        if (i + 1 < vec.size()) 
        {
            int first = vec[i];
            int second = vec[i + 1];
            if (first < second)
                pairs.push_back(std::make_pair(second, first));
            else
                pairs.push_back(std::make_pair(first, second));
        } 
        else 
        {
            hasOdd = true;
            oddElement = vec[i];
        }
    }

    // 3) Trie recursif des plus grands
    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); ++i)
        mainChain.push_back(pairs[i].first);

    MergeDeq(mainChain);


    // 4) on remet les petit avant leur grands des paire dans les grands trier 
    int minElement = *std::min_element(mainChain.begin(), mainChain.end());

    int associatedSmall = 0;
    size_t indexOfMinPair = 0;
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        if (pairs[i].first == minElement) 
        {
            associatedSmall = pairs[i].second;
            indexOfMinPair = i;
            break;
        }
    }

    std::deque<int>::iterator it = mainChain.begin();
    while (it != mainChain.end() && *it != minElement)
        ++it;
    mainChain.insert(it, associatedSmall);

    std::deque<bool> inserted(pairs.size(), false);
    inserted[indexOfMinPair] = true;

	// 5) jacobsthal
    insertJacobSthalD(pairs, mainChain, inserted);

    if (hasOdd) 
    {
        std::deque<int>::iterator it = mainChain.begin();
        while (it != mainChain.end() && *it < oddElement)
            ++it;
        mainChain.insert(it, oddElement);
    }
    vec = mainChain;
}

void PmergeMe::insertJacobSthalD(std::deque<std::pair<int, int> >& pairs, 
                                 std::deque<int>& result, 
                                 std::deque<bool>& inserted) {
    
    std::deque<int> insertionOrder = getJacobsthalSequence<std::deque<int> >(pairs.size());
    
    for (size_t i = 0; i < insertionOrder.size(); ++i) {
        int idx = insertionOrder[i];
        if (idx < static_cast<int>(pairs.size()) && !inserted[idx]) {
            std::deque<int>::iterator it = std::lower_bound(
                result.begin(), result.end(), pairs[idx].second);
            result.insert(it, pairs[idx].second);
            inserted[idx] = true;
        }
    }
    
    for (size_t i = 0; i < pairs.size(); ++i) {
        if (!inserted[i]) {
            std::deque<int>::iterator it = std::lower_bound(
                result.begin(), result.end(), pairs[i].second);
            result.insert(it, pairs[i].second);
        }
    }
}
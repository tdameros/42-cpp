#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>

class PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);
	~PmergeMe(void);

	PmergeMe &operator=(const PmergeMe &other);

	void	insertionSort(std::vector<int>& vector);
};

#endif

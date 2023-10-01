#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>

# define INSERTION_SORT_THRESHOLD 25

class PmergeMe
{
public:
	PmergeMe(void);
	PmergeMe(const PmergeMe &other);
	~PmergeMe(void);

	PmergeMe &operator=(const PmergeMe &other);

	static void	mergeInsertSortVector(std::vector<int>& vector);
	static void	insertionSortVector(std::vector<int>& vector);

	static void	mergeInsertSortList(std::list<int>& list);
	static void	insertionSortList(std::list<int>& list);

	static void	benchmarkMergeInsertSortVector(std::vector<int>& vector);
	static void	benchmarkMergeInsertSortList(std::list<int>& list);

	template <typename T>
	static void	printContainer(T& container)
	{
		for (typename T::iterator it = container.begin(); it != container.end(); it++)
			std::cout << *it << ", ";
		std::cout << std::endl;
	}
};

#endif

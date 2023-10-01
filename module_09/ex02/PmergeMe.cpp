#include <algorithm>
#include <sys/time.h>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{

}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe::~PmergeMe(void)
{

}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{

	}
	return (*this);
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vector)
{
	std::vector<int>::iterator	mid = vector.begin() + vector.size() / 2;

	if (vector.size() <= INSERTION_SORT_THRESHOLD)
	{
		insertionSortVector(vector);
		return ;
	}
	std::vector<int> left(vector.begin(), mid);
	std::vector<int> right(mid, vector.end());
	mergeInsertSortVector(left);
	mergeInsertSortVector(right);
	std::merge(left.begin(), left.end(),
			   right.begin(), right.end(),
			   vector.begin());
}

void PmergeMe::insertionSortVector(std::vector<int>& vector)
{
	size_t	y;
	int 	key;

	for (size_t i = 1; i < vector.size(); i++)
	{
		y = i;
		key = vector[i];
		while (y > 0 && vector[y - 1] > key)
		{
			vector[y] = vector[y - 1];
			y--;
		}
		vector[y] = key;
	}
}

void PmergeMe::mergeInsertSortList(std::list<int>& list)
{
	std::list<int>::iterator	mid = list.begin();

	std::advance(mid, list.size() / 2);
	if (list.size() <= INSERTION_SORT_THRESHOLD)
	{
		insertionSortList(list);
		return ;
	}
	std::list<int> left(list.begin(), mid);
	std::list<int> right(mid, list.end());
	mergeInsertSortList(left);
	mergeInsertSortList(right);
	std::merge(left.begin(), left.end(),
			   right.begin(), right.end(),
			   list.begin());
}

void PmergeMe::insertionSortList(std::list<int>& list)
{
	int	key;

	for (std::list<int>::iterator i = list.begin(); i != list.end(); i++)
	{
		key = *i;
		for (std::list<int>::iterator j = list.begin(); j != i; j++)
		{
			if (key < *j)
			{
				i = list.erase(i);
				i--;
				list.insert(j, key);
				break ;
			}
		}
	}
}

void	PmergeMe::benchmarkMergeInsertSortVector(std::vector<int> &vector)
{
	struct timeval	start;
	struct timeval	end;
	size_t 			usec;

	std::cout << "Before: ";
	printContainer(vector);
	gettimeofday(&start, NULL);
	mergeInsertSortVector(vector);
	gettimeofday(&end, NULL);
	std::cout << "After: ";
	printContainer(vector);
	usec = (end.tv_sec - start.tv_sec) * 1000000
		   + (end.tv_usec - start.tv_usec);
	std::cout << "Time to process a range of " << vector.size()
			  << " elements with vector : " << usec << " us" << std::endl;
}

void	PmergeMe::benchmarkMergeInsertSortList(std::list<int> &list)
{
	struct timeval	start;
	struct timeval	end;
	size_t 			usec;

	std::cout << "Before: ";
	printContainer(list);
	gettimeofday(&start, NULL);
	mergeInsertSortList(list);
	gettimeofday(&end, NULL);
	std::cout << "After: ";
	printContainer(list);
	usec = (end.tv_sec - start.tv_sec) * 1000000
		   + (end.tv_usec - start.tv_usec);
	std::cout << "Time to process a range of " << list.size()
			  << " elements with list : " << usec << " us" << std::endl;
}

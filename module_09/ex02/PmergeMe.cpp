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

void PmergeMe::insertionSort(std::vector<int>& vector)
{
	size_t	y;
	int 	tmp;

	for (size_t i = 1; i < vector.size(); i++)
	{
		y = i;
		tmp = vector[i];
		while (y > 0 && vector[y - 1] > tmp)
		{
			vector[y] = vector[y - 1];
			y--;
		}
		vector[y] = tmp;
	}
}
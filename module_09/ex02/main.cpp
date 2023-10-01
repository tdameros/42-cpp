#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

#include "PmergeMe.hpp"

static bool	isDigitCStr(const char *str);
static std::vector<int>	initializeIntVector(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Error: invalid argument" << std::endl;
		return (EXIT_FAILURE);
	}
	std::vector<int> test = initializeIntVector(argc, argv);
	std::vector<int> test1 = std::vector<int>(test.begin(), test.begin() + test.size() / 2);
	std::vector<int> test2 = std::vector<int>(test.begin()+ test.size() / 2, test.end());

	for (size_t i = 0; i < test1.size(); i++)
		std::cout << test1[i] << ", ";
	std::cout << std::endl;
	for (size_t i = 0; i < test2.size(); i++)
		std::cout << test2[i] << ", ";
	std::cout << std::endl;
	PmergeMe	merge = PmergeMe();
	merge.insertionSort(test1);
	merge.insertionSort(test2);
	std::merge(test1.begin(), test1.end(), test2.begin(), test2.end(), test.begin());
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test[i] << ", ";
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}

static std::vector<int>	initializeIntVector(int argc, char *argv[])
{
	std::vector<int>	numbers;
	int 				number;

	argc--;
	argv++;
	for (int i = 0; i < argc; i++)
	{
		if (!isDigitCStr(argv[i]))
			throw std::runtime_error("Error: invalid arguments");
		number = atoi(argv[i]);
		if (errno == ERANGE)
			throw std::runtime_error("Error: invalid arguments");
		numbers.push_back(number);
	}
	return (numbers);
}

static bool	isDigitCStr(const char *str)
{
	for (size_t i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}
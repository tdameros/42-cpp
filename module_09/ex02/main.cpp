#include <fstream>
#include <cstdlib>
#include <algorithm>

#include "PmergeMe.hpp"

static std::vector<int>	initializeIntVector(int argc, char *argv[]);
static std::list<int>	initializeIntList(int argc, char *argv[]);
static bool				isDigitCStr(const char *str);

int	main(int argc, char *argv[])
{
	std::vector<int>	vector;
	std::list<int>		list;

	if (argc == 1)
	{
		std::cout << "Error: invalid argument" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		vector = initializeIntVector(argc, argv);
		list = initializeIntList(argc, argv);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	PmergeMe::benchmarkMergeInsertSortVector(vector);
	PmergeMe::benchmarkMergeInsertSortList(list);
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

 static std::list<int>	initializeIntList(int argc, char *argv[])
{
	std::list<int>	numbers;
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

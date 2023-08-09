#include <iostream>

void printStrUpper(char *string);

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
		printStrUpper(argv[i]);
	std::cout << std::endl;
	return (0);
}

void printStrUpper(char *string)
{
	for (int i = 0; string[i] != '\0'; i++)
		std::cout << (char) toupper(string[i]);
}
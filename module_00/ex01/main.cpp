#include <string>
#include <iostream>
#include <cstdlib>
#include <cstddef>

#include "PhoneBook.hpp"

std::string	getInput(std::string prompt);
void		addCommand(PhoneBook *phoneBook);
void		searchCommand(PhoneBook *phoneBook);
static bool	isStrNumber(std::string str);

int	main(void)
{
	PhoneBook	phoneBook = PhoneBook();
	std::string	input = getInput("PhoneBook > ");

	while (!std::cin.eof() && input.compare("EXIT") != 0)
	{
		if (input.compare("ADD") == 0)
			addCommand(&phoneBook);
		else if (input.compare("SEARCH") == 0)
			searchCommand(&phoneBook);
		if (!std::cin.eof())
			input = getInput("PhoneBook > ");
	}
	if (std::cin.eof())
		std::cout << std::endl;
	return (0);
}

std::string getInput(std::string prompt)
{
	std::string input;

	while (input.empty())
	{
		std::cout << prompt;
		if (std::getline(std::cin, input) == 0)
			return ("");
	}
	return (input);
}

void	addCommand(PhoneBook *phoneBook)
{
	std::string first_name = getInput("Firstname: ");
	if (std::cin.eof())
		return ;
	std::string	last_name = getInput("Lastname: ");
	if (std::cin.eof())
		return ;
	std::string nickname = getInput("Nickname: ");
	if (std::cin.eof())
		return ;
	std::string phone_number = getInput("Phone number: ");
	if (std::cin.eof())
		return ;
	std::string darkest_secret = getInput("Darkest secret: ");
	if (std::cin.eof())
		return ;
	phoneBook->addContact(Contact(first_name,
				last_name,
				nickname,
				phone_number,
				darkest_secret));
}

void	searchCommand(PhoneBook *phoneBook)
{
	std::string	input;

	if (phoneBook->printContacts() == 0)
		return ;
	input = getInput("Enter index: ");
	if (std::cin.eof())
		return ;
	if (!isStrNumber(input))
		std::cout << "Error, invalid index." << std::endl;
	else
		phoneBook->printContactDetails(atoi(input.c_str()));
}

static bool	isStrNumber(std::string str)
{
	std::size_t	length;

	length = str.length();
	for (std::size_t i = 0; i != length; i++)
	{
		if (!std::isdigit(str[i]))
			return (0);
	}
	return (1);
}

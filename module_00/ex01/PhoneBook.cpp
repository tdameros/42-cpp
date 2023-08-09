#include <iostream>
#include <iomanip>
#include <sstream>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _contacts(), _number_of_contacts(0), _index_contact(0) {}

void PhoneBook::addContact(Contact contact)
{
	this->_contacts[this->_index_contact] = contact;
	this->_index_contact = (this->_index_contact + 1) % 8;
	if (this->_number_of_contacts < 8)
		this->_number_of_contacts++;
}

int	PhoneBook::printContacts(void)
{
	Contact contact;

	if (this->_number_of_contacts == 0)
	{
		std::cout << "Error, empty PhoneBook." << std::endl;
		return (0);
	}
	this->_printRow("index", "first name", "last name", "nickname");
	for (int i = 0; i < this->_number_of_contacts; i++)
	{
		contact = this->_contacts[i];
		this->_printRow(_intToString(i), contact.getFirstName(), contact.getLastName(), contact.getNickName());
	}
	return (1);
}

int	PhoneBook::printContactDetails(int index)
{
	if (index < 0 || index >= this->_number_of_contacts)
	{
		std::cout << "Error, index not found." << std::endl;
		return (0);
	}
	std::cout << this->_contacts[index];
	return (1);
}

void PhoneBook::_printRow(std::string c1, std::string c2, std::string c3, std::string c4)
{
	if (c2.length() > 10)
		c2 = c2.substr(0, 9) + ".";
	if (c3.length() > 10)
		c3 = c3.substr(0, 9) + ".";
	if (c4.length() > 10)
		c4 = c4.substr(0, 9) + ".";
	std::cout << std::setw(10) << c1 << "|";
	std::cout << std::setw(10) << c2 << "|";
	std::cout << std::setw(10) << c3 << "|";
	std::cout << std::setw(10) << c4 << "|";
	std::cout << std::endl;
}

std::string PhoneBook::_intToString(int i)
{
	std::stringstream out;

	out << i;
	return (out.str());
}

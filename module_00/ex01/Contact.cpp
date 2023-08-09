#include "Contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string first_name, const std::string last_name,
				 const std::string nickname, const std::string phone_number,
				 const std::string darkest_secret): \
				 _first_name(first_name), \
				 _last_name(last_name), \
				 _nickname(nickname), \
				 _phone_number(phone_number), \
				 _darkest_secret(darkest_secret) {
}

Contact& Contact::operator=(const Contact& other) {
	if (this != &other)
	{
		this->_first_name = other._first_name;
		this->_last_name = other._last_name;
		this->_nickname = other._nickname;
		this->_phone_number = other._phone_number;
		this->_darkest_secret = other._darkest_secret;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact)
{
	os << "Firstname: " << contact.getFirstName() << std::endl;
	os << "Lastname: " << contact.getLastName() << std::endl;
	os << "Nickname:" << contact.getNickName() << std::endl;
	os << "Phone number: " << contact.getPhoneNumber() << std::endl;
	os << "Darkest secret: " << contact.getDarkestSecret() << std::endl;
	return os;
}


const std::string	Contact::getFirstName() const
{
	return (this->_first_name);
}

const std::string	Contact::getLastName() const
{
	return (this->_last_name);
}

const std::string	Contact::getNickName() const
{
	return (this->_nickname);
}

const std::string	Contact::getPhoneNumber() const
{
	return (this->_phone_number);
}

const std::string	Contact::getDarkestSecret() const
{
	return (this->_darkest_secret);
}
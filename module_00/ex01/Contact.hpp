#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

# include <string>
# include <iostream>

class Contact {

	public:
		Contact(void);
		Contact(std::string first_name,
				std::string last_name,
				std::string nickname,
				std::string phone_number,
				std::string darkest_secret);
		Contact& operator=(const Contact& other);

		const std::string	getFirstName(void) const;
		const std::string	getLastName(void) const;
		const std::string	getNickName(void) const;
		const std::string	getPhoneNumber(void) const;
		const std::string	getDarkestSecret(void) const;

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

std::ostream& operator<<(std::ostream& os, const Contact& contact);

#endif

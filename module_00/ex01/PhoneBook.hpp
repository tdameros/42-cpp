#ifndef __PHONEBOOK_HPP__
# define __PHONEBOOK_HPP__

#include "Contact.hpp"

class PhoneBook {

	public:
		PhoneBook();

		void	addContact(Contact contact);
		int		printContacts(void);
		int		printContactDetails(int index);

	private:
		Contact _contacts[8];
		int 	_number_of_contacts;
		int 	_index_contact;

		void		_printRow(const std::string c1,
							  const std::string c2,
							  const std::string c3,
							  const std::string c4);
		std::string	_intToString(int i);
};


#endif

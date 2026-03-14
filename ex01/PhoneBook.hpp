#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int current_idx;
	public:
		PhoneBook();
		void addContact();
		void searchContact();
};

#endif
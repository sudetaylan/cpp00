#include "contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>

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

#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

int main() {
    PhoneBook myPhoneBook;
    std::string command;
	std::string str;

    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";

        std::getline(std::cin, command);
        if (!std::cin || command == "EXIT")
            break;
        if (command.empty())
            continue;
        if (command == "ADD")
			myPhoneBook.addContact();
        else if (command == "SEARCH") 
        {
            myPhoneBook.searchContact();
			std::cin.ignore(1000, '\n'); 
        }
    }
    return 0;
}
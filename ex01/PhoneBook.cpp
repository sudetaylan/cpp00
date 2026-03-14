#include <string>
#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() 
{
	this->current_idx = 0;
}

void PhoneBook::addContact()
{
    Contact& newContact = contacts[current_idx % 8];
    std::string input;

    input = "";
    while (input.empty())
    {
        std::cout << "First Name: ";
        if (!std::getline(std::cin, input))
			return;
    }
    newContact.setFirstName(input);

    input = "";
    while (input.empty())
    {
        std::cout << "Last Name: ";
        if (!std::getline(std::cin, input))
			return;
    }
    newContact.setLastName(input);

    input = "";
    while (input.empty())
    {
        std::cout << "Nickname: ";
        if (!std::getline(std::cin, input)) 
			return;
    }
    newContact.setNickname(input);

    input = "";
    while (true)
    {
        std::cout << "Phone Number: ";
        if (!std::getline(std::cin, input)) 
            return;
        if (input.empty())
            continue;
        bool only_digits = true;
        for (size_t i = 0; i < input.length(); i++) 
        {
            if (!std::isdigit(input[i])) 
            {
                only_digits = false;
                break;
            }
        }
        if (only_digits)
            break;
        else
            std::cout << "Error: The phone number must consist only of digits!" << std::endl;
    }
    newContact.setPhoneNumber(input);

    input = "";
    while (input.empty())
    {
        std::cout << "Darkest Secret: ";
        if (!std::getline(std::cin, input)) 
			return;
    }
    newContact.setDarkestSecret(input);

    std::cout << "Contact added to index " << current_idx % 8 << std::endl;
    current_idx++;
}

void PhoneBook::searchContact()
{
	std::string input;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;

    for (int i = 0; i < 8; i++){
        this->contacts[i].printIndex(i); 
    }
	std::cout << "Please enter the index you want to display: ";
	std::cin >> input;
	if(input.length() == 1 && input[0] >= '0' && input[0] <= '7')
	{
		int idx = input[0] - '0';
		if(contacts[idx].getFirstName().empty())
			std::cout << "This index is empty";
		else
			contacts[idx].printFull();
	}
	else
		std::cout << "Invalid index!" << std::endl;
}

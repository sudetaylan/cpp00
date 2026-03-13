#include "phonebook.hpp"

void Contact::setFirstName(const std::string& firstName){
	this->firstName = firstName;
};
void Contact::setLastName(const std::string& lastName){
	this->lastName = lastName;
};
void Contact::setNickname(const std::string& nickname){
	this->nickname = nickname;
};
void Contact::setPhoneNumber(const std::string& phoneNumber){
	this->phoneNumber = phoneNumber;
};
void Contact::setDarkestSecret(const std::string& darkestSecret){
	this->darkestSecret = darkestSecret;
};
std::string Contact::getfirstName() const{
	return(firstName);
};
std::string Contact::getLastName() const{
	return(lastName);
};
std::string Contact::getNickname() const{
	return(nickname);
};
std::string Contact::getPhoneNumber() const{
	return(phoneNumber);
};
std::string Contact::getDarkestSecret() const{
	return(darkestSecret);
};

std::string Contact::formatField(std::string content) const{
    if (content.length() > 10)
       return(content.substr(0, 9) + '.');
    return content;
}

void Contact::printIndex(int index) const{
    if (this->firstName.empty())
        return; 
    std::cout << "|" << std::setw(10) << index;
    std::cout << "|" << std::setw(10) << formatField(this->firstName);
    std::cout << "|" << std::setw(10) << formatField(this->lastName);
    std::cout << "|" << std::setw(10) << formatField(this->nickname) << "|" << std::endl;
}

void Contact::printFull() const{
    if (this->firstName.empty())
        return; 
    std::cout << "First Name:" << this->firstName << std::endl;
    std::cout << "Last Name:" << this->lastName << std::endl;
    std::cout << "Nickname:" <<this->nickname << std::endl;
    std::cout << "Phone Number:" <<this->phoneNumber << std::endl;
    std::cout << "Darkest Secret:" <<this->darkestSecret << std::endl;
}

PhoneBook::PhoneBook() {
    this->current_idx = 0;
}

void PhoneBook::addContact()
{
	Contact& newContact = contacts[current_idx % 8];
	std::string input;

	std::cout << "First Name: ";
	std::getline(std::cin>>std::ws, input);
	newContact.setFirstName(input);

	std::cout << "Last Name: ";
	std::getline(std::cin>>std::ws, input);
	newContact.setLastName(input);

	std::cout << "Nickname: ";
	std::getline(std::cin>>std::ws, input);
	newContact.setNickname(input);

	std::cout << "Phone Number: ";
	std::getline(std::cin>>std::ws, input);
	newContact.setPhoneNumber(input);

	std::cout << "Darkest Secret: ";
	std::getline(std::cin>>std::ws, input);
	newContact.setDarkestSecret(input);

	current_idx++;

}

void PhoneBook::searchContact()
{
	std::string input;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;

    for (int i = 0; i < 8; i++) {
        this->contacts[i].printIndex(i); 
    }

	std::cout << "Please enter the index you want to display: ";
	std::cin >> input;
	if(input.length() == 1 && input[0] >= '0' && input[0] <= '7')
	{
		int idx = input[0] - '0';
		if(contacts[idx].getfirstName().empty())
			std::cout << "This index is empty";
		else
			contacts[idx].printFull();
	}
	else
		std::cout << "Invalid index!" << std::endl;
}

int main() {
    PhoneBook myPhoneBook;
    std::string command;
	std::string str;

    while (true) {
        std::cout << "Komut girin (ADD, SEARCH, EXIT): ";
        if (!(std::cin >> command) || command == "EXIT")
            break;
        
        if (command == "ADD") {
			myPhoneBook.addContact();
        } else if (command == "SEARCH") {
            myPhoneBook.searchContact();
        }
    }
    return 0;
}
#include "Contact.hpp"

void Contact::setFirstName(const std::string& firstName)
{
	this->firstName = firstName;
}

void Contact::setLastName(const std::string& lastName)
{
	this->lastName = lastName;
}

void Contact::setNickname(const std::string& nickname)
{
	this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return(this->firstName);
}

std::string Contact::getLastName() const
{
	return(this->lastName);
}

std::string Contact::getNickname() const
{
	return(this->nickname);
}

std::string Contact::getPhoneNumber() const
{
	return(this->phoneNumber);
}

std::string Contact::getDarkestSecret() const
{
	return(this->darkestSecret);
}

int Contact::getVisualLength(const std::string& str) const 
{
    int len = 0;
    for (size_t i = 0; i < str.length(); i++) 
    {
        if ((str[i] & 0xc0) != 0x80)
            len++;
    }
    return len;
}

std::string Contact::formatField(std::string content) const
{
    int visualLen = getVisualLength(content);
    
    if (visualLen > 10) {
        std::string result = "";
        int count = 0;
        for (size_t i = 0; i < content.length() && count < 9; )
        {
            int charSize = 1;
            if ((unsigned char)content[i] >= 192)
                charSize = 2;
            result += content.substr(i, charSize);
            i += charSize;
            count++;
        }
        return result + ".";
    }
    return content;
}

void Contact::printIndex(int index) const
{
    if (this->firstName.empty())
        return;
    std::string fields[3];
    fields[0] = formatField(this->firstName);
    fields[1] = formatField(this->lastName);
    fields[2] = formatField(this->nickname);
    std::cout << "|" << std::setw(10) << index;
    for (int i = 0; i < 3; i++)
    {
        int extraBytes = fields[i].length() - getVisualLength(fields[i]);
        std::cout << "|" << std::setw(10 + extraBytes) << fields[i];
    }
    std::cout << "|" << std::endl;
}

void Contact::printFull() const
{
    if (this->firstName.empty())
        return; 
    std::cout << "First Name:" << this->firstName << std::endl;
    std::cout << "Last Name:" << this->lastName << std::endl;
    std::cout << "Nickname:" <<this->nickname << std::endl;
    std::cout << "Phone Number:" <<this->phoneNumber << std::endl;
    std::cout << "Darkest Secret:" <<this->darkestSecret << std::endl;
}
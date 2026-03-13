#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
		std::string formatField(std::string content) const;

	public:
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& lastName);
		void setNickname(const std::string& nickname);
		void setPhoneNumber(const std::string& phoneNumber);
		void setDarkestSecret(const std::string& darkestSecret);
		std::string getfirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		void printIndex(int index) const;
		void printFull() const;
};

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

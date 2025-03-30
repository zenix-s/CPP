#include "PhoneBookManager.hpp"

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

PhoneBookManager::PhoneBookManager()
{
}

PhoneBookManager::~PhoneBookManager()
{
}

PhoneBookManager::PhoneBookManager(const PhoneBookManager &other)
{
	*this = other;
}

PhoneBookManager &PhoneBookManager::operator=(const PhoneBookManager &other)
{
	(void) other;
	return (*this);
}

void PhoneBookManager::run()
{
	std::string input;
	PhoneBook  *phoneBook = new PhoneBook();

	while (1)
	{
		input = get_input("Enter command(ADD, SEARCH, EXIT): ");

		if (input == "EXIT")
			break;
		else if (input == "ADD")
			addContact(phoneBook);
		else if (input == "SEARCH")
			searchContact(phoneBook);
	}

	delete phoneBook;
}

std::string PhoneBookManager::get_input(std::string message)
{
	std::string input;

	std::cout << message;
	std::getline(std::cin, input);

	while (input.empty())
	{
		std::cout << "Field is required" << std::endl;
		std::cout << message;
		std::getline(std::cin, input);
	}

	return input;
}

void PhoneBookManager::addContact(PhoneBook *phoneBook)
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	firstName = get_input("Enter first name: ");
	lastName = get_input("Enter last name: ");
	nickname = get_input("Enter nickname: ");
	phoneNumber = get_input("Enter phone number: ");
	darkestSecret = get_input("Enter darkest secret: ");

	phoneBook->addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

void PhoneBookManager::printContacts(PhoneBook *phoneBook)
{
	int i;

	if (phoneBook->getContactsCount() == 0)
	{
		std::cout << "No contacts available" << std::endl;
		return;
	}

	std::cout << "     index|first name| last name|  nickname" << std::endl;
	for (i = 0; i < phoneBook->getContactsCount(); i++)
	{
		std::cout << phoneBook->getContactInfo(i, SHORT) << std::endl;
	}
}

void PhoneBookManager::searchContact(PhoneBook *phoneBook)
{
	std::string index;
	int         i;

	printContacts(phoneBook);

	index = get_input("Enter index: ");
	i = std::atoi(index.c_str());
	if (i < 1 || i > phoneBook->getContactsCount())
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}

	std::cout << phoneBook->getContactInfo(i - 1, FULL) << std::endl;
}

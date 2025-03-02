/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:24:21 by serferna          #+#    #+#             */
/*   Updated: 2025/03/02 21:04:26 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

std::string get_input(std::string message)
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

int main(void)
{
	PhoneBook *phoneBook = new PhoneBook();

	std::string input;
	while (1)
	{
		input = get_input("Enter command(ADD, SEARCH, EXIT): ");

		if (input == "EXIT")
			break;
		else if (input == "ADD")
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
		else if (input == "SEARCH")
		{
			if (phoneBook->getContactsCount() == 0)
			{
				std::cout << "No contacts available" << std::endl;
				continue;
			}

			// Display the saved contacts as a list of 4 columns: index, first name, last name and nickname.
			std::cout << "Contacts: " << phoneBook->getContactsCount() << std::endl;
			for (int i = 0; i < phoneBook->getContactsCount(); i++)
				std::cout << phoneBook->getContactInfo(i, 0) << std::endl;

			input.clear();

			// Then, prompt the user again for the index of the entry to display. If the index
			// is out of range or wrong, define a relevant behavior. 
			std::cout << "Enter index: ";
			std::getline(std::cin, input);

			int i = std::atoi(input.c_str());

			std::cout << "Index:" << i << std::endl;

			// Otherwise, display the contact information, one field per line.
			std::cout << phoneBook->getContactInfo(i - 1, 1) << std::endl;
		}
		else
		{
			std::cout << "Invalid command" << std::endl;
		}
	}

	delete phoneBook;
}

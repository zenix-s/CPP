/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookManager.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/08 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

PhoneBookManager::PhoneBookManager(const PhoneBookManager& other)
{
    *this = other;
}

PhoneBookManager& PhoneBookManager::operator=(const PhoneBookManager& other)
{
    (void)other;
    return (*this);
}

void PhoneBookManager::run()
{
    std::string input;
    PhoneBook*  phoneBook = new PhoneBook();

    while (1)
    {
        input = getInput("Enter command(ADD, SEARCH, EXIT): ");

        if (input == "EXIT")
            break;
        else if (input == "ADD")
            addContact(phoneBook);
        else if (input == "SEARCH")
            searchContact(phoneBook);
    }

    delete phoneBook;
}

std::string PhoneBookManager::getInput(std::string message)
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

void PhoneBookManager::addContact(PhoneBook* phoneBook)
{
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    firstName = getInput("Enter first name: ");
    lastName = getInput("Enter last name: ");
    nickname = getInput("Enter nickname: ");
    phoneNumber = getInput("Enter phone number: ");
    darkestSecret = getInput("Enter darkest secret: ");

    phoneBook->addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
}

void PhoneBookManager::printContacts(PhoneBook* phoneBook)
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

void PhoneBookManager::searchContact(PhoneBook* phoneBook)
{
    std::string index;
    int         i;

    printContacts(phoneBook);

    index = getInput("Enter index: ");
    i = std::atoi(index.c_str());
    if (i < 1 || i > phoneBook->getContactsCount())
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    std::cout << phoneBook->getContactInfo(i - 1, FULL) << std::endl;
}

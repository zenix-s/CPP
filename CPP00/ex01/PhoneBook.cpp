/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 02:40:44 by serferna          #+#    #+#             */
/*   Updated: 2025/03/02 21:04:23 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook()
{
	_contactsCount = 0;
}

PhoneBook::~PhoneBook()
{
	for (int i = 0; i < _contactsCount; i++)
		delete _contacts[i];
}

PhoneBook::PhoneBook(const PhoneBook &other)
{
	*this = other;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
	if (this != &other)
	{
		_contactsCount = other._contactsCount;
		for (int i = 0; i < _contactsCount; i++)
			_contacts[i] = other._contacts[i];
	}
	return (*this);
}

void PhoneBook::addContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
	if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() ||
	    darkestSecret.empty())
	{
		std::cout << "All fields are required" << std::endl;
		return;
	}

	if (_contactsCount == _maxContacts)
		delete _contacts[_maxContacts - 1];
	if (_contactsCount < _maxContacts)
		_contactsCount++;

	for (int i = _contactsCount - 1; i > 0; i--)
	{
		_contacts[i] = _contacts[i - 1];
		_contacts[i]->setIndex(i);
	}

	_contacts[0] = new Contact(0, firstName, lastName, nickname, phoneNumber, darkestSecret);
}

std::string PhoneBook::getContactInfo(int index, bool fullVersion) const
{
	if (index < 0 || index >= _contactsCount)
		return "Invalid index";

	if (fullVersion)
		return _contacts[index]->getContactInfo(FULL);
	return _contacts[index]->getContactInfo(SHORT);
}

int PhoneBook::getContactsCount() const
{
	return _contactsCount;
}

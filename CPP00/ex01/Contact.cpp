/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:46:35 by serferna          #+#    #+#             */
/*   Updated: 2025/03/02 20:54:19 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Utils.hpp"
#include <string>

Contact::~Contact()
{
}

Contact::Contact()
{
}

Contact::Contact(const Contact& other)
{
    *this = other;
}

Contact& Contact::operator=(const Contact& other)
{
    if (this == &other)
        return *this;

    _index = other._index;
    _firstName = other._firstName;
    _lastName = other._lastName;
    _nickname = other._nickname;
    _phoneNumber = other._phoneNumber;
    _darkestSecret = other._darkestSecret;
    return *this;
}

Contact::Contact(int index, std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret)
{
    _index = index;
    _firstName = firstName;
    _lastName = lastName;
    _nickname = nickname;
    _phoneNumber = phoneNumber;
    _darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
    return _firstName;
}

std::string Contact::getLastName() const
{
    return _lastName;
}

std::string Contact::getNickname() const
{
    return _nickname;
}

std::string Contact::getPhoneNumber() const
{
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return _darkestSecret;
}

std::string Contact::formatColumn(std::string str) const
{
    if (str.length() > 10)
    {
        str.resize(9);
        str += ".";
        return str;
    }

    str.insert(0, 10 - str.length(), ' ');
    return str;
}

std::string Contact::formatColumn(int nbr) const
{
    return formatColumn(Utils::toString(nbr));
}

std::string Contact::getShortContactInfo() const
{
    std::string info;

    info += formatColumn(_index + 1) + "|";
    info += formatColumn(_firstName) + "|";
    info += formatColumn(_lastName) + "|";
    info += formatColumn(_nickname);

    return info;
}

std::string Contact::getFullContactInfo() const
{
    std::string info;

    info += "First name: " + _firstName + "\n";
    info += "Last name: " + _lastName + "\n";
    info += "Nickname: " + _nickname + "\n";
    info += "Phone number: " + _phoneNumber + "\n";
    info += "Darkest secret: " + _darkestSecret + "\n";

    return info;
}

std::string Contact::getContactInfo(contactType type) const
{
    if (type == SHORT)
        return getShortContactInfo();
    return getFullContactInfo();
}

void Contact::setIndex(int index)
{
    _index = index;
}

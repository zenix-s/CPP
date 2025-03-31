/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:28:56 by serferna          #+#    #+#             */
/*   Updated: 2025/03/02 20:57:42 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
  private:
    static const int _maxContacts = 8;

    int      _contactsCount;
    Contact* _contacts[8];

  public:
    PhoneBook();
    PhoneBook(const PhoneBook& other);
    PhoneBook& operator=(const PhoneBook& other);
    ~PhoneBook();

    void addContact(std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);
    int         getContactsCount() const;
    std::string getContactInfo(int index, bool fullVersion) const;
};

#endif

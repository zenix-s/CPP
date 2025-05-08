/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookManager.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/08 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_MANAGER_HPP

#define PHONE_BOOK_MANAGER_HPP

#include "PhoneBook.hpp"
#include <string>

class PhoneBookManager
{
  public:
    PhoneBookManager();
    ~PhoneBookManager();
    PhoneBookManager(const PhoneBookManager& other);
    PhoneBookManager& operator=(const PhoneBookManager& other);

    void run();

  private:
    std::string getInput(std::string message);
    void        addContact(PhoneBook* phoneBook);
    void        printContacts(PhoneBook* phoneBook);
    void        searchContact(PhoneBook* phoneBook);
};

#endif

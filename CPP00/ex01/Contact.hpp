/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 01:39:25 by serferna          #+#    #+#             */
/*   Updated: 2025/03/02 21:02:00 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP

#define CONTACT_HPP

#include <string>

class Contact
{
  private:
	int         _index;
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

  public:
	Contact();
	Contact(const Contact &other);
	Contact &operator=(const Contact &other);
	~Contact();

	Contact(int index, std::string firstName, std::string lastName, std::string nickname, std::string phoneNumber, std::string darkestSecret);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	std::string formatColumn(int nbr) const;
	std::string formatColumn(std::string str) const;

	std::string getShortContactInfo() const;
	std::string getFullContactInfo() const;

	void setIndex(int index);
};

#endif

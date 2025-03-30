#ifndef PHONE_BOOK_MANAGER_HPP

#define PHONE_BOOK_MANAGER_HPP

#include "PhoneBook.hpp"
#include <string>

class PhoneBookManager
{
  public:
	PhoneBookManager();
	~PhoneBookManager();
	PhoneBookManager(const PhoneBookManager &other);
	PhoneBookManager &operator=(const PhoneBookManager &other);

	void run();

  private:
	std::string get_input(std::string message);
	void        addContact(PhoneBook *phoneBook);
	void        printContacts(PhoneBook *phoneBook);
	void        searchContact(PhoneBook *phoneBook);
};

#endif

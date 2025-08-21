#pragma once

#include "AForm.hpp"
#include <string>

class Intern
{
  public:
    Intern();
    Intern(const Intern& other);
    ~Intern();
    Intern& operator=(const Intern& other);

    AForm* makeForm(const std::string& formName, const std::string& target) const;
};

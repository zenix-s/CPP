
#include "WrongCat.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

WrongCat::WrongCat()
{
    Logger::printLog("WrongCat default constructor called");
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)
{
    Logger::printLog("WrongCat copy constructor called");
    *this = other;
}

WrongCat::~WrongCat()
{
    Logger::printLog("WrongCat destructor called");
}

std::string WrongCat::getType() const
{
    return _type;
}

void WrongCat::makeSound() const
{
    std::cout << "Woof, oops, I mean Meow!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    Logger::printLog("WrongCat assignment operator called");

    if (this == &other)
        return *this;

    _type = other._type;
    return *this;
}


#include "WrongCat.hpp"
#include "Logger.hpp"
#include "WrongAnimal.hpp"
#include <string>

WrongCat::WrongCat() : WrongAnimal()
{
    Logger::printLog("WrongCat default constructor called");
    _type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    Logger::printLog("WrongCat copy constructor called");
    *this = other;
}

WrongCat::~WrongCat()
{
    Logger::printLog("WrongCat destructor called");
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    Logger::printLog("WrongCat assignment operator called");

    if (this == &other)
        return *this;

    _type = other._type;
    return *this;
}

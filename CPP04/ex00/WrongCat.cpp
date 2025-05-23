
#include "WrongCat.hpp"
#include "Logger.hpp"
#include "WrongAnimal.hpp"
#include <string>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    Logger::printLog("WrongCat default constructor called");
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
    Logger::printLog("WrongCat copy constructor called");
}

WrongCat::~WrongCat()
{
    Logger::printLog("WrongCat destructor called");
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    Logger::printLog("WrongCat assignment operator called");

    (void)other; // Prevent unused variable warning)
    return *this;
}

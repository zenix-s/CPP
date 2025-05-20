#include "WrongAnimal.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(void)
{
    Logger::printLog("WrongAnimal default constructor called");
    _type = "Unknown creature";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    Logger::printLog("WrongAnimal copy constructor called");
    *this = other;
}

WrongAnimal::~WrongAnimal()
{
    Logger::printLog("WrongAnimal destructor called");
}

std::string WrongAnimal::getType(void) const
{
    return _type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "Wrong Unknown sound!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    Logger::printLog("WrongAnimal assignment operator called");

    if (this == &other)
        return *this;

    _type = other._type;
    return *this;
}

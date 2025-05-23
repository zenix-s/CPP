#include "WrongAnimal.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal(void)
{
    Logger::printLog("WrongAnimal default constructor called");
    _type = "Unknown creature";
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
    Logger::printLog("WrongAnimal constructor called");
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    Logger::printLog("WrongAnimal copy constructor called");
    copy(other);
}

void WrongAnimal::copy(const WrongAnimal& other)
{
    _type = other._type;
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

    if (this != &other)
        copy(other);

    return *this;
}

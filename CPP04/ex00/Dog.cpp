
#include "Dog.hpp"
#include "Animal.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

Dog::Dog() : Animal("100% certified good boy")
{
    Logger::printLog("Dog constructor called");
    _type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
    Logger::printLog("Dog copy constructor called");
    *this = other;
}

Dog::~Dog()
{
    Logger::printLog("Dog destructor called");
}

std::string Dog::getType() const
{
    return _type;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    Logger::printLog("Dog assignment operator called");

    if (this == &other)
        return *this;

    _type = other._type;
    Animal::_type = other.Animal::_type;
    return *this;
}

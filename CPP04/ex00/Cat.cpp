
#include "Cat.hpp"

#include "Animal.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal("Feline")
{
    Logger::printLog("Cat constructor called");
    _type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other)
{
    Logger::printLog("Cat copy constructor called");
    *this = other;
}

Cat::~Cat()
{
    Logger::printLog("Cat destructor called");
}

std::string Cat::getType() const
{
    return _type;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    Logger::printLog("Cat assignment operator called");

    if (this == &other)
        return *this;

    _type = other._type;
    Animal::_type = other.Animal::_type;
    return *this;
}

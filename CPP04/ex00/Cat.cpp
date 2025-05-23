#include "Cat.hpp"

#include "Animal.hpp"
#include "Logger.hpp"
#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat")
{
    Logger::printLog("Cat constructor called");
}

Cat::Cat(const Cat& other) : Animal(other)
{
    Logger::printLog("Cat copy constructor called");
    copy(other);
}

Cat::~Cat()
{
    Logger::printLog("Cat destructor called");
}

void Cat::copy(const Cat& other)
{
    Logger::printLog("Cat copy function called");
    (void)other; // Prevent unused variable warning
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    Logger::printLog("Cat assignment operator called");

    if (this != &other)
        copy(other);

    return *this;
}

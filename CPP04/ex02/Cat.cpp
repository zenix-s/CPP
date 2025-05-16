
#include "Cat.hpp"

#include "Logger.hpp"
#include <iostream>
#include <string>

Cat::Cat()
{
    Logger::printLog("Cat default constructor called");
    _type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& other)
{
    Logger::printLog("Cat copy constructor called");
    *this = other;
}

Cat::~Cat()
{
    Logger::printLog("Cat destructor called");
    
    delete _brain; 
}

std::string Cat::getType() const
{
    return _type;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::addIdea(const std::string& idea)
{
    if (_brain)
        _brain->addIdea(idea);
}

void Cat::printIdeas() const
{
    if (_brain)
        _brain->printIdeas();
}

Cat& Cat::operator=(const Cat& other)
{
    Logger::printLog("Cat assignment operator called");

    if (this == &other)
        return *this;

    _type = other._type;
    return *this;
}

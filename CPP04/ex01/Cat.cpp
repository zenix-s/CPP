
#include "Cat.hpp"

#include "Animal.hpp"
#include "Brain.hpp"
#include "Logger.hpp"
#include <cstddef>
#include <iostream>
#include <string>

Cat::Cat() : Animal("Cat")
{
    Logger::printLog("Cat constructor called");
    _brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other)
{
    Logger::printLog("Cat copy constructor called");
    copy(other);
}

Cat::~Cat()
{
    delete _brain;
    Logger::printLog("Cat destructor called");
}

void Cat::copy(const Cat& other)
{
    Logger::printLog("Cat copy function called");
    _type = other._type;
    _brain = other._brain ? new Brain(*other._brain) : NULL;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

void Cat::addIdea(std::string idea)
{
    if (!_brain)
        return;
    Logger::printLog("Cat addIdea to brain called");
    _brain->addIdea(idea);
}

void Cat::printIdeas() const
{
    if (!_brain)
        return;
    Logger::printLog("Cat print ideas");
    _brain->printIdeas();
}

Cat& Cat::operator=(const Cat& other)
{
    Logger::printLog("Cat assignment operator called");

    if (this != &other)
    {
        delete _brain;
        copy(other);
    }

    return *this;
}

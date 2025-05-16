
#include "Brain.hpp"

#include "Logger.hpp"
#include <iostream>
#include <string>

Brain::Brain()
{
    Logger::printLog("Brain default constructor called");
    for (int i = 0; i < 100; i++)
        ideas[i].clear();
}

Brain::Brain(const Brain& other)
{
    Logger::printLog("Brain copy constructor called");
    *this = other;
}

Brain::~Brain()
{
    Logger::printLog("Brain destructor called");
}

void Brain::printIdeas() const
{
    Logger::printLog("Brain printIdeas called");
    for (int i = 0; i < 100; i++)
    {
        if (!ideas[i].empty())
            std::cout << ideas[i] << std::endl;
    }
}

void Brain::addIdea(const std::string& idea)
{
    for (int i = 0; i < 100; i++)
    {
        if (ideas[i].empty())
        {
            ideas[i] = idea;
            break;
        }
    }
}

Brain& Brain::operator=(const Brain& other)
{
    Logger::printLog("Brain assignment operator called");

    if (this == &other)
        return *this;

    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];

    return *this;
}

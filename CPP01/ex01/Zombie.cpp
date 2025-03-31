#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
    _name = "Steve";
}

Zombie::Zombie(Zombie const& zombie)
{
    _name = zombie._name;
}

Zombie::Zombie(std::string name)
{
    _name = name;
}

Zombie::~Zombie()
{
    std::cout << _name << " has been destroyed." << std::endl;
}

Zombie& Zombie::operator=(Zombie const& zombie)
{
    if (this == &zombie)
        return *this;

    _name = zombie._name;
    return *this;
}

void Zombie::announce()
{
    std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    _name = name;
}

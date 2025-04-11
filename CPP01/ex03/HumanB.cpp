/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/03/11 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

#include <cstddef>
#include <iostream>

HumanB::HumanB(std::string name)
{
    _name = name;
    _weapon = NULL;
}

HumanB::~HumanB()
{
}

HumanB::HumanB(const HumanB& other)
{
    _name = other._name;
    _weapon = other._weapon;
}

HumanB& HumanB::operator=(const HumanB& other)
{
    if (this == &other)
        return *this;

    _name = other._name;
    _weapon = other._weapon;
    return *this;
}

void HumanB::attack()
{
    if (_weapon == NULL)
    {
        std::cout << _name << " has no weapon to attack with!" << std::endl;
        return;
    }
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
    _weapon = &weapon;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/03/11 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon)
{
    _name = name;
    _weapon = &weapon;
}

HumanA::~HumanA()
{
}

HumanA::HumanA(const HumanA& other)
{
    _name = other._name;
    _weapon = other._weapon;
}

HumanA& HumanA::operator=(const HumanA& other)
{
    if (this == &other)
        return *this;

    _name = other._name;
    _weapon = other._weapon;
    return *this;
}

void HumanA::attack()
{
    std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

void HumanA::setWeapon(Weapon& weapon)
{
    delete _weapon;
    _weapon = &weapon;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FILENAME                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: CURRENT_YEAR/MONTH/DAY 18:01:21 by serferna          #+#    #+#             */
/*   Updated: YEAR/MONTH/DAY 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

// Private member functions

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name, 100, 50, 20)
{
    std::cout << "ScavTrap Constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
    std::cout << "ScavTrap Copy constructor called for " << _name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called for " << _name << std::endl;
}

void ScavTrap::guardGate() const
{
    std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap Copy assignment operator called for " << _name << std::endl;
    if (this == &other)
        return *this;
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
    return *this;
}

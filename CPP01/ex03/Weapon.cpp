/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/03/30 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
    _type = "fist";
}

Weapon::Weapon(std::string type)
{
    _type = type;
}

Weapon::~Weapon()
{
}

Weapon::Weapon(const Weapon& other)
{
    _type = other._type;
}

Weapon& Weapon::operator=(const Weapon& other)
{
    if (this == &other)
        return *this;

    _type = other._type;
    return *this;
}

std::string const& Weapon::getType() const
{
    return _type;
}

void Weapon::setType(std::string type)
{
    _type = type;
}

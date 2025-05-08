/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/08 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"
#include <string>

Utils::Utils()
{
}

Utils::~Utils()
{
}

Utils::Utils(const Utils& other)
{
    *this = other;
}

Utils& Utils::operator=(const Utils& other)
{
    (void)other;
    return (*this);
}

std::string Utils::toString(int nbr)
{
    std::string str;
    if (nbr == 0)
        return ("0");
    while (nbr > 0)
    {
        str.insert(0, 1, '0' + (nbr % 10));
        nbr /= 10;
    }
    return (str);
}

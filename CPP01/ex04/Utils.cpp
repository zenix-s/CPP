/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/09 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

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

std::string Utils::Replace(std::string str, const std::string toReplace, const std::string toReplaceWith)
{
    size_t startingPosition = 0;

    while ((startingPosition = str.find(toReplace, startingPosition)) != std::string::npos)
    {
        str.erase(startingPosition, toReplace.length());
        str.insert(startingPosition, toReplaceWith);
        startingPosition += toReplaceWith.length();
    }

    return str;
}

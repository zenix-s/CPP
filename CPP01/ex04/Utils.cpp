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

std::string Utils::Replace(std::string str, const std::string from, const std::string to)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos)
    {
        str.erase(start_pos, from.length());
        str.insert(start_pos, to);
        start_pos += to.length();
    }
    return str;
}

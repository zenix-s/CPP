/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/03/12 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

class Utils
{
  public:
    Utils();
    ~Utils();
    Utils(const Utils& other);
    Utils& operator=(const Utils& other);

    static std::string Replace(std::string str, const std::string from, const std::string to);
};

#endif

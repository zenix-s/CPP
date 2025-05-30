/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/08 18:01:21 by serferna         ###   ########.fr       */
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

    static std::string toString(int nbr);
};

#endif

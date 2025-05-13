/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/09 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
  private:
    int              _value;
    static const int _fractionalBits = 8;

  public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed(const int value);
    Fixed(const float value);
    ~Fixed();

    int  getRawBits() const;
    void setRawBits(int const raw);
    
    Fixed& operator=(const Fixed& other);

    float toFloat() const;
    int   toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif

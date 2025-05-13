/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/09 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main()
{
    {
        Fixed       a;
        Fixed const b(Fixed(5.05f) * Fixed(2));
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max(a, b) << std::endl;
    }
    std::cout << "My tests" << std::endl;
    {
        // Test constructors
        Fixed a;
        Fixed b(10);
        Fixed c(42.42f);
        Fixed d(b);

        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "c: " << c << std::endl;
        std::cout << "d: " << d << std::endl;

        // Test assignment operator
        a = Fixed(1234.4321f);
        std::cout << "a after assignment: " << a << std::endl;

        // Test comparison operators
        std::cout << "b > c: " << (b > c) << std::endl;
        std::cout << "b < c: " << (b < c) << std::endl;
        std::cout << "b >= d: " << (b >= d) << std::endl;
        std::cout << "b <= d: " << (b <= d) << std::endl;
        std::cout << "b == d: " << (b == d) << std::endl;
        std::cout << "b != d: " << (b != d) << std::endl;

        // Test arithmetic operators
        Fixed e = b + c;
        Fixed f = b - c;
        Fixed g = b * c;
        Fixed h = b / c;

        std::cout << "b + c: " << e << std::endl;
        std::cout << "b - c: " << f << std::endl;
        std::cout << "b * c: " << g << std::endl;
        std::cout << "b / c: " << h << std::endl;

        // Test increment/decrement operators
        Fixed i;
        std::cout << "i: " << i << std::endl;
        std::cout << "++i: " << ++i << std::endl;
        std::cout << "i++: " << i++ << std::endl;
        std::cout << "i after i++: " << i << std::endl;
        std::cout << "--i: " << --i << std::endl;
        std::cout << "i--: " << i-- << std::endl;
        std::cout << "i after i--: " << i << std::endl;

        // Test min/max functions
        std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
        std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
    }
    return 0;
}

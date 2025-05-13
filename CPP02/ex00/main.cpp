/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/13 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << "Testing copy constructor and assignment operator" << std::endl;

        Fixed a;
        Fixed b(a);
        Fixed c;
        c = b;
        std::cout << a.getRawBits() << std::endl;
        std::cout << b.getRawBits() << std::endl;
        std::cout << c.getRawBits() << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;

    {
        std::cout << "Testing setRawBits and getRawBits" << std::endl;

        Fixed a;
        a.setRawBits(42);
        std::cout << "Raw bits set to: " << a.getRawBits() << std::endl;
        Fixed b(a);
        std::cout << "Raw bits of b after copy: " << b.getRawBits() << std::endl;
        Fixed c;
        c = b;
        std::cout << "Raw bits of c after assignment: " << c.getRawBits() << std::endl;
        c.setRawBits(84);
        std::cout << "Raw bits of c after set: " << c.getRawBits() << std::endl;
        std::cout << "Raw bits of b after c set: " << b.getRawBits() << std::endl;
        std::cout << "Raw bits of a after b set: " << a.getRawBits() << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;

    {
        std::cout << "Testing copy constructor and assignment operator with different values" << std::endl;

        Fixed a;
        a.setRawBits(100);
        std::cout << "Raw bits of a: " << a.getRawBits() << std::endl;
        Fixed b(a);
        std::cout << "Raw bits of b after copy: " << b.getRawBits() << std::endl;
        Fixed c;
        c = b;
        std::cout << "Raw bits of c after assignment: " << c.getRawBits() << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;

    {
        std::cout << "Testing empty constructor" << std::endl;

        Fixed a;
        std::cout << "Raw bits of a: " << a.getRawBits() << std::endl;
    }

    std::cout << "----------------------------------------" << std::endl;

    {
        std::cout << "Testing destructor with heap allocation" << std::endl;

        Fixed* a = new Fixed();
        delete a;
    }

    return 0;
}

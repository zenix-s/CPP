/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/03/30 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <iostream>

int main(void)
{
    {
        std::cout << "Creating a horde of 5 zombies with the name 'Walker'." << std::endl;

        Zombie* horde = zombieHorde(5, "Walker");
        for (int i = 0; i < 5; i++)
            horde[i].announce();

        delete[] horde;

        std::cout << std::endl;
    }

    {
        std::cout << "Creating a horde of 3 zombies with the name 'Runner'." << std::endl;

        Zombie* horde = zombieHorde(3, "Runner");
        for (int i = 0; i < 3; i++)
            horde[i].announce();
        delete[] horde;

        std::cout << std::endl;
    }

    {
        std::cout << "Creating a horde of 1 zombie with the name 'Crawler'." << std::endl;

        Zombie* horde = zombieHorde(1, "Crawler");
        for (int i = 0; i < 1; i++)
            horde[i].announce();
        delete[] horde;

        std::cout << std::endl;
    }

    {
        std::cout << "Creating a horde of 0 zombies with the name 'Noner'." << std::endl;

        Zombie* horde = zombieHorde(0, "Noner");
        for (int i = 0; i < 0; i++)
            horde[i].announce();
        delete[] horde;

        std::cout << std::endl;
    }

    return 0;
}

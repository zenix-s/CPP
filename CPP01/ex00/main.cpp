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

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    {
        std::cout << "Creating a zombie on the heap with the constructor that takes a string as an argument." << std::endl;

        Zombie* zombie = new Zombie("Steve");
        zombie->announce();
        delete zombie;
    }

    std::cout << std::endl;

    {
        std::cout << "Creating a zombie on the stack with the default constructor." << std::endl;

        Zombie zombie = Zombie();
        zombie.announce();
    }

    std::cout << std::endl;

    {
        std::cout << "Creating a zombie on the heap with the newZombie function." << std::endl;

        Zombie* zombie = newZombie("Steve");
        zombie->announce();
        delete zombie;
    }

    std::cout << std::endl;

    {
        std::cout << "Creating a zombie on the stack with the randomChump function." << std::endl;

        randomChump("Steve");
    }

    std::cout << std::endl;
}

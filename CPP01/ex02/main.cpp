/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2024/03/30 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";

    std::string* ptr = &str;
    std::string& ref = str;

    std::cout << "Memory address held by the variables" << std::endl;
    std::cout << "str: " << &str << std::endl;
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "ref: " << &ref << std::endl;

    std::cout << "Value of the variables" << std::endl;
    std::cout << "str: " << str << std::endl;
    std::cout << "ptr: " << *ptr << std::endl;
    std::cout << "ref: " << ref << std::endl;

    return 0;
}

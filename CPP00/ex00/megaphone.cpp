/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:52:13 by serferna          #+#    #+#             */
/*   Updated: 2025/03/02 00:38:28 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define DEFAULT_MESSAGE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

std::string toUpper(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        str[i] = std::toupper(static_cast<char>(str[i]));
    return str;
}

void megaphone(int word_count, char* words[])
{
    if (word_count <= 1)
    {
        std::cout << DEFAULT_MESSAGE << std::endl;
        return;
    }

    for (int word_index = 1; word_index < word_count; word_index++)
    {
        std::cout << toUpper(std::string(words[word_index]));
        std::cout << " ";
    }

    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    megaphone(argc, argv);
    return 0;
}

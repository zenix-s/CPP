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

void megaphone(int word_count, char *words[])
{
	if (word_count <= 1)
	{
		std::cout << DEFAULT_MESSAGE << std::endl;
		return;
	}

	for (int word_index = 1; word_index < word_count; word_index++)
	{
		std::string word = words[word_index];

		for (int char_index = 0; word[char_index]; char_index++)
			std::cout << (char) toupper(word[char_index]);
		std::cout << " ";
	}

	std::cout << std::endl;
}

int main(int argc, char *argv[])
{
	megaphone(argc, argv);
	return 0;
}

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

#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string_to_search> <string_to_replace>" << std::endl;
        return 1;
    }

    (void)argc;
    const std::string filename = argv[1];
    std::string       outFileName = std::string(filename) + std::string(".replace");
    std::string       stringToSearch = argv[2];
    std::string       stringToReplace = argv[3];

    // Open file
    std::ifstream file;
    file.open(filename.c_str(), std::ios::in);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    // Create output file
    // std::ofstream outFile(outFileName);
    std::ofstream outFile;
    outFile.open(outFileName.c_str(), std::ios::out);
    if (!outFile.is_open())
    {
        std::cerr << "Error creating output file: " << outFileName << std::endl;
        return 1;
    }

    std::string fileContent;
    std::string line;
    while (std::getline(file, line))
    {
        line = Utils::Replace(line, stringToSearch, stringToReplace);
        outFile << line << std::endl;
    }

    // Close file
    file.close();
    outFile.close();

    return 0;
}

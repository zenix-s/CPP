#include <iostream>
#include <ostream>
#include <string>
#include <ctime>

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

class Utils
{
  public:
    Utils();
    ~Utils();

    static std::string toString(int nbr);
};

Utils::Utils()
{
}

Utils::~Utils()
{
}

std::string Utils::toString(int nbr)
{
    std::string str;
    if (nbr == 0)
        return ("0");
    while (nbr > 0)
    {
        str.insert(0, 1, '0' + (nbr % 10));
        nbr /= 10;
    }
    return (str);
}

std::string FileNameLineSetter(std::string& fileName)
{
    std::string start = "/*   ";
    std::string end = " :+:      :+:    :+:   */";

    if (fileName.length() > 50)
        fileName.resize(50);
    else
        fileName.insert(fileName.length(), 50 - fileName.length(), ' ');
    return fileName;
}

std::string CreatedDateLineSetter(void)
{
    time_t timestamp = time(&timestamp);
    struct tm datetime = *localtime(&timestamp);

    std::string line = "";

    int i = 0;

    std::string year = std::to_string(1900 + datetime.tm_year);
    std::string month = std::to_string(1 + datetime.tm_mon);

    line.insert(0, "/*   Created: ");
    line.insert(14, year);
    line.insert(18, "/");
    line.insert(19, month.insert(0, 2 - std::to_string(1 + datetime.tm_mon).length(), '0'));
    line.insert(21, "/");

    return line;
}

int main(void)
{
    std::string line = CreatedDateLineSetter();

    std::cout << line << std::endl;

    return 0;
}

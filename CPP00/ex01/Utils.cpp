
#include "Utils.hpp"
#include <string>

Utils::Utils()
{
}

Utils::~Utils()
{
}

Utils::Utils(const Utils& other)
{
    *this = other;
}

Utils& Utils::operator=(const Utils& other)
{
    (void)other;
    return (*this);
}

std::string Utils::to_string(int nbr)
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

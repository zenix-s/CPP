#include "Utils.hpp"

const std::string Utils::BOLD = "\033[1m";
const std::string Utils::BOLD_OFF = "\033[22m";
const std::string Utils::RED = "\033[31m";
const std::string Utils::GREEN = "\033[32m";
const std::string Utils::YELLOW = "\033[33m";
const std::string Utils::BLUE = "\033[34m";
const std::string Utils::CYAN = "\033[36m";
const std::string Utils::WHITE = "\033[37m";
const std::string Utils::RESET = "\033[0m";

Utils::Utils()
{
}

Utils::Utils(const Utils& other)
{
    *this = other;
}

Utils::~Utils()
{
}

std::string Utils::getBold()
{
    return BOLD;
}

std::string Utils::getBoldOff()
{
    return BOLD_OFF;
}

std::string Utils::getRed()
{
    return RED;
}

std::string Utils::getGreen()
{
    return GREEN;
}

std::string Utils::getYellow()
{
    return YELLOW;
}

std::string Utils::getBlue()
{
    return BLUE;
}

std::string Utils::getCyan()
{
    return CYAN;
}

std::string Utils::getWhite()
{
    return WHITE;
}

std::string Utils::getReset()
{
    return RESET;
}

Utils& Utils::operator=(const Utils& other)
{
    if (this != &other)
    {
        // Copy the data from other to this
    }
    return *this;
}
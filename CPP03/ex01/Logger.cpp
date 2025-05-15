#include "Logger.hpp"
#include <iostream>

const bool Logger::_log = false;

const std::string Logger::BOLD = "\033[1m";
const std::string Logger::BOLD_OFF = "\033[22m";
const std::string Logger::RED = "\033[31m";
const std::string Logger::GREEN = "\033[32m";
const std::string Logger::YELLOW = "\033[33m";
const std::string Logger::BLUE = "\033[34m";
const std::string Logger::CYAN = "\033[36m";
const std::string Logger::WHITE = "\033[37m";
const std::string Logger::RESET = "\033[0m";

Logger::Logger()
{
}

Logger::Logger(const Logger& other)
{
    *this = other;
}

Logger::~Logger()
{
}

std::string Logger::getBold()
{
    return BOLD;
}

std::string Logger::getBoldOff()
{
    return BOLD_OFF;
}

std::string Logger::getRed()
{
    return RED;
}

std::string Logger::getGreen()
{
    return GREEN;
}

std::string Logger::getYellow()
{
    return YELLOW;
}

std::string Logger::getBlue()
{
    return BLUE;
}

std::string Logger::getCyan()
{
    return CYAN;
}

std::string Logger::getWhite()
{
    return WHITE;
}

std::string Logger::getReset()
{
    return RESET;
}

void Logger::printLog(const std::string& message)
{
    if (!_log)
        return;
    std::cout << CYAN << BOLD << message << BOLD_OFF << RESET << std::endl;
}

Logger& Logger::operator=(const Logger& other)
{
    (void)other; // Avoid unused parameter warning
    return *this;
}

#include "Logger.hpp"
#include <iostream>

const bool Logger::_log = true;

const std::string Logger::_bold = "\033[1m";
const std::string Logger::_boldOff = "\033[22m";
const std::string Logger::_red = "\033[31m";
const std::string Logger::_green = "\033[32m";
const std::string Logger::_yellow = "\033[33m";
const std::string Logger::_blue = "\033[34m";
const std::string Logger::_cyan = "\033[36m";
const std::string Logger::_white = "\033[37m";
const std::string Logger::_reset = "\033[0m";

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
    return _bold;
}

std::string Logger::getBoldOff()
{
    return _boldOff;
}

std::string Logger::getRed()
{
    return _red;
}

std::string Logger::getGreen()
{
    return _green;
}

std::string Logger::getYellow()
{
    return _yellow;
}

std::string Logger::getBlue()
{
    return _blue;
}

std::string Logger::getCyan()
{
    return _cyan;
}

std::string Logger::getWhite()
{
    return _white;
}

std::string Logger::getReset()
{
    return _reset;
}

void Logger::printLineJunp()
{
    std::cout << std::endl;
}

void Logger::printLog(const std::string& message)
{
    if (!_log)
        return;
    std::cout << _cyan << _bold << message << _boldOff << _reset << std::endl;
}

void Logger::printComment(const std::string& message)
{
    if (!_log)
        return;
    std::cout << _yellow << _bold << message << _boldOff << _reset << std::endl;
}

void Logger::printTitle(const std::string& message)
{
    if (!_log)
        return;
    std::cout << _green << _bold << message << _boldOff << _reset << std::endl;
}

void Logger::printError(const std::string& message)
{
    if (!_log)
        return;
    std::cout << _red << _bold << message << _boldOff << _reset << std::endl;
}

Logger& Logger::operator=(const Logger& other)
{
    (void)other; // Avoid unused parameter warning
    return *this;
}

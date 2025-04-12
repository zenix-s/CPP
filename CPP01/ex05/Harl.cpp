
#include "Harl.hpp"

#include <iostream>
#include <string>

const std::string Harl::_debugLevelText = "I love having extra bacon for my "
                                          "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
const std::string Harl::_infoLevelText = "I cannot believe adding extra bacon costs more money. You didn't put enough "
                                         "bacon in my burger! If you did, I wouldn't be asking for more!";
const std::string Harl::_warningLevelText = "I think I deserve to have some extra bacon for free. I've been coming for "
                                            "years whereas you started working here since last month.";
const std::string Harl::_errorLevelText = "This is unacceptable! I want to speak to the manager now.";

const Harl::funcPtr Harl::functions[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
const std::string   Harl::levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

Harl::Harl()
{
}

Harl::~Harl()
{
}

Harl::Harl(const Harl& other)
{
    *this = other;
}

Harl& Harl::operator=(const Harl& other)
{
    if (this == &other)
        return *this;

    return *this;
}

void Harl::debug(void)
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << _debugLevelText << std::endl;
}

void Harl::info(void)
{
    std::cout << "[INFO]" << std::endl;
    std::cout << _infoLevelText << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << _warningLevelText << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << _errorLevelText << std::endl;
}

void Harl::complain(std::string level)
{
    for (int i = 0; i < 4; ++i)
    {
        if (level == levels[i])
        {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "[...]" << std::endl;
    std::cout << "Invalid level: " << level << std::endl;
}

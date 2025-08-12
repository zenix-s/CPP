#include "ScalarConverter.hpp"
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iostream>

ScalarConverter::ScalarType ScalarConverter::getType(const std::string& input)
{
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
        return CHAR;

    if (input == "nanf" || input == "+inff" || input == "-inff")
        return FLOAT;

    if (input == "nan" || input == "+inf" || input == "-inf")
        return DOUBLE;

    if (input.find('.') != std::string::npos || (!input.empty() && input[input.length() - 1] == 'f'))
    {
        if (!input.empty() && input[input.length() - 1] == 'f')
            return FLOAT;
        return DOUBLE;
    }

    if (isNumeric(input))
        return INT;

    return INVALID;
}

bool ScalarConverter::isNumeric(const std::string& input)
{
    if (input.empty())
        return false;

    size_t i = 0;
    if (input[i] == '-' || input[i] == '+')
        i++;

    bool hasDecimal = false;
    for (; i < input.length(); ++i)
    {
        if (input[i] == '.')
        {
            if (hasDecimal)
                return false;
            hasDecimal = true;
        }
        else if (!isdigit(input[i]))
            return false;
    }
    return true;
}

void ScalarConverter::printChar(double value)
{
    if (std::isnan(value) || std::isinf(value))
        std::cout << "char: impossible" << std::endl;
    else if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (value < 32 || value == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value)
{
    if (std::isnan(value) || std::isinf(value))
        std::cout << "int: impossible" << std::endl;
    else if (value > INT_MAX || value < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value)
{
    float floatValue = static_cast<float>(value);
    if (std::isnan(floatValue))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(floatValue))
    {
        if (floatValue > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }
    else
    {
        std::cout << "float: " << floatValue;
        if (floatValue == static_cast<int>(floatValue))
            std::cout << ".0";
        std::cout << "f" << std::endl;
    }
}

void ScalarConverter::printDouble(double value)
{
    if (std::isnan(value))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "double: " << value;
        if (value == static_cast<int>(value))
            std::cout << ".0";
        std::cout << std::endl;
    }
}

void ScalarConverter::printInvalid()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::fromChar(const std::string& input)
{
    char   c = input[1];
    double value = static_cast<double>(c);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::fromInt(const std::string& input)
{
    int    value = std::atoi(input.c_str());
    double dValue = static_cast<double>(value);
    printChar(dValue);
    printInt(dValue);
    printFloat(dValue);
    printDouble(dValue);
}

void ScalarConverter::fromFloat(const std::string& input)
{
    double dValue = std::atof(input.c_str());
    float  value = static_cast<float>(dValue);
    printChar(dValue);
    printInt(dValue);
    printFloat(value);
    printDouble(dValue);
}

void ScalarConverter::fromDouble(const std::string& input)
{
    double value = std::atof(input.c_str());
    printChar(value);
    printInt(value);
    printFloat(static_cast<float>(value));
    printDouble(value);
}

void ScalarConverter::convert(const std::string& input)
{
    ScalarType type = getType(input);
    switch (type)
    {
        case CHAR:
            fromChar(input);
            break;
        case INT:
            fromInt(input);
            break;
        case FLOAT:
            fromFloat(input);
            break;
        case DOUBLE:
            fromDouble(input);
            break;
        default:
            printInvalid();
            break;
    }
}

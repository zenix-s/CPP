#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
    loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _exchangeRates(other._exchangeRates)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _exchangeRates = other._exchangeRates;
    return *this;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw FileOpenException();

    std::string line;
    // Skip header line
    if (!std::getline(file, line))
    {
        file.close();
        throw InvalidDatabaseException();
    }

    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;

        std::string date = line.substr(0, commaPos);
        std::string value = line.substr(commaPos + 1);

        if (!date.empty() && !value.empty())
        {
            float rate = static_cast<float>(std::atof(value.c_str()));
            _exchangeRates[date] = rate;
        }
    }
    file.close();

    if (_exchangeRates.empty())
        throw InvalidDatabaseException();
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    // Check if all characters are digits
    for (size_t i = 0; i < yearStr.length(); ++i)
        if (!std::isdigit(yearStr[i]))
            return false;
    for (size_t i = 0; i < monthStr.length(); ++i)
        if (!std::isdigit(monthStr[i]))
            return false;
    for (size_t i = 0; i < dayStr.length(); ++i)
        if (!std::isdigit(dayStr[i]))
            return false;

    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const
{
    if (_exchangeRates.empty())
        return "";

    std::map<std::string, float>::const_iterator it = _exchangeRates.upper_bound(date);

    if (it == _exchangeRates.begin())
        return "";

    --it;
    return it->first;
}

std::string BitcoinExchange::trim(const std::string& str) const
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";

    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    // Skip header line if it exists
    if (std::getline(file, line))
    {
        // Check if it's a header
        if (line.find("date") == std::string::npos || line.find("value") == std::string::npos)
        {
            // Not a header, process it
            file.clear();
            file.seekg(0);
        }
    }
    else
    {
        file.close();
        return;
    }

    while (std::getline(file, line))
    {
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));

        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }

        if (valueStr.empty())
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        char*  endPtr;
        double value = std::strtod(valueStr.c_str(), &endPtr);

        if (*endPtr != '\0')
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        // Find the exchange rate for this date
        std::string rateDate = date;
        if (_exchangeRates.find(date) == _exchangeRates.end())
        {
            rateDate = findClosestDate(date);
            if (rateDate.empty())
            {
                std::cout << "Error: no exchange rate available for " << date << std::endl;
                continue;
            }
        }

        float rate = _exchangeRates[rateDate];
        float result = static_cast<float>(value) * rate;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }

    file.close();
}

const char* BitcoinExchange::FileOpenException::what() const throw()
{
    return "Could not open database file";
}

const char* BitcoinExchange::InvalidDatabaseException::what() const throw()
{
    return "Invalid database format";
}

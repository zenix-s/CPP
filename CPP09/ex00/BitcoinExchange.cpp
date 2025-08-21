#include "BitcoinExchange.hpp"
#include <cmath>
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

bool BitcoinExchange::isValidDatabaseHeader(const std::string& header) const
{
    return header == "date,exchange_rate";
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::logic_error("Could not open database file");

    std::string line;
    if (!std::getline(file, line) || !isValidDatabaseHeader(line))
    {
        file.close();
        throw std::logic_error("Invalid database format");
    }

    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;

        std::string date = line.substr(0, commaPos);
        std::string value = line.substr(commaPos + 1);

        if (date.empty() || value.empty())
            continue;

        if (!isValidDate(date))
            continue;

        try
        {
            float rate = validateRate(value);
            _exchangeRates[date] = rate;
        }
        catch (const std::logic_error&)
        {
            continue;
        }
    }
    file.close();

    if (_exchangeRates.empty())
        throw std::logic_error("Invalid database format");
}

float BitcoinExchange::validateRate(const std::string& value) const
{
    if (value.empty())
        throw std::logic_error("Error: bad input");

    size_t i = 0;
    bool   hasDigits = false;
    bool   hasDecimalPoint = false;

    while (i < value.length() && (value[i] == ' ' || value[i] == '\t'))
        i++;

    if (i >= value.length())
        throw std::logic_error("Error: bad input");

    if (value[i] == '+' || value[i] == '-')
        i++;

    while (i < value.length())
    {
        char c = value[i];

        if (c >= '0' && c <= '9')
            hasDigits = true;
        else if (c == '.' && !hasDecimalPoint)
            hasDecimalPoint = true;
        else if (c == ' ' || c == '\t')
        {
            while (i < value.length() && (value[i] == ' ' || value[i] == '\t'))
                i++;
            break;
        }
        else
            throw std::logic_error("Error: bad input");
        i++;
    }

    if (!hasDigits)
        throw std::logic_error("Error: bad input");

    if (i < value.length())
        throw std::logic_error("Error: bad input");

    double temp = std::atof(value.c_str());

    if (std::isinf(temp) || std::isnan(temp))
        throw std::logic_error("Error: too large a number.");

    float rate = static_cast<float>(temp);

    if (std::isinf(rate) || std::isnan(rate))
        throw std::logic_error("Error: too large a number.");

    if (rate < 0)
        throw std::logic_error("Error: not a positive number.");

    if (rate > 1000)
        throw std::logic_error("Error: too large a number.");

    return rate;
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
    if (std::getline(file, line))
    {
        if (line.find("date") == std::string::npos || line.find("value") == std::string::npos)
        {
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

        float value;
        try
        {
            value = validateRate(valueStr);
        }
        catch (const std::logic_error& e)
        {
            std::string errorMsg = e.what();
            if (errorMsg == "Error: bad input")
                std::cout << "Error: bad input => " << line << std::endl;
            else
                std::cout << errorMsg << std::endl;
            continue;
        }

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

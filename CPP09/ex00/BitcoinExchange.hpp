#pragma once

#include <exception>
#include <map>
#include <string>

class BitcoinExchange
{
  private:
    std::map<std::string, float> _exchangeRates;

    void        loadDatabase(const std::string& filename);
    bool        isValidDate(const std::string& date) const;
    bool        isValidValue(const std::string& value) const;
    float       parseValue(const std::string& value) const;
    std::string findClosestDate(const std::string& date) const;
    std::string trim(const std::string& str) const;

  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void processInput(const std::string& filename);

    class FileOpenException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    class InvalidDatabaseException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};
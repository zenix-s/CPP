#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
  private:
    std::map<std::string, float> _exchangeRates;

    void        loadDatabase(const std::string& filename);
    bool        isValidDatabaseHeader(const std::string& header) const;
    bool        isValidDate(const std::string& date) const;
    float       validateRate(const std::string& value) const;
    std::string findClosestDate(const std::string& date) const;
    std::string trim(const std::string& str) const;

  public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void processInput(const std::string& filename);
};

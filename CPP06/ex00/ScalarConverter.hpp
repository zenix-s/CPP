#pragma once

#include <string>
class ScalarConverter
{
  private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

    enum ScalarType
    {
        CHAR,
        INT,
        FLOAT,
        DOUBLE,
        INVALID
    };

    static ScalarType getType(const std::string& input);
    static void       fromChar(const std::string& input);
    static void       fromInt(const std::string& input);
    static void       fromFloat(const std::string& input);
    static void       fromDouble(const std::string& input);
    static void       printChar(double value);
    static void       printInt(double value);
    static void       printFloat(double value);
    static void       printDouble(double value);
    static void       printInvalid();
    static bool       isNumeric(const std::string& input);

  public:
    static void convert(const std::string& input);
};

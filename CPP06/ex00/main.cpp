#include "ScalarConverter.hpp"
#include <iostream>

int main(void)
{
    std::cout << "Char" << std::endl;
    {
        std::string inputs[] = {"'a'", "'b'", "'c'", "'d'", "'e'", "'f'", "'g'", "'h'", "'i'", "'j'", "invalid_char"};

        for (int i = 0; i < 11; ++i)
        {
            std::string input = inputs[i];
            std::cout << "Input: " << input << std::endl;
            ScalarConverter::convert(input);
            std::cout << std::endl;
        }
    }

    std::cout << "Int" << std::endl;
    {
        std::string inputs[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "invalid_int"};

        for (int i = 0; i < 11; ++i)
        {
            std::string input = inputs[i];
            std::cout << "Input: " << input << std::endl;
            ScalarConverter::convert(input);
            std::cout << std::endl;
        }
    }

    std::cout << "Float" << std::endl;
    {
        std::string inputs[] = {"0.0f",  "1.1f", "-2.2f", "+3.3f", "4.4f",         "-5.5f",
                                "+6.6f", "7.7f", "8.8f",  "9.9f",  "invalid_float"};

        for (int i = 0; i < 11; ++i)
        {
            std::string input = inputs[i];
            std::cout << "Input: " << input << std::endl;
            ScalarConverter::convert(input);
            std::cout << std::endl;
        }
    }

    std::cout << "Double" << std::endl;
    {
        std::string inputs[] = {"0.0",  "1.1", "-2.2", "+3.3", "4.4",           "-5.5",
                                "+6.6", "7.7", "8.8",  "9.9",  "invalid_double"};

        for (int i = 0; i < 11; ++i)
        {
            std::string input = inputs[i];
            std::cout << "Input: " << input << std::endl;
            ScalarConverter::convert(input);
            std::cout << std::endl;
        }
    }

    std::cout << "Testing special cases" << std::endl;

    std::string specialInputs[] = {".",    "nanf",  "+inff", "-inff", "nan", "+inf",
                                   "-inf", "42.0f", "'0'",   "127",   "128", "-1"};

    for (int i = 0; i < 12; ++i)
    {
        std::string input = specialInputs[i];
        std::cout << "Input: " << input << std::endl;
        ScalarConverter::convert(input);
        std::cout << std::endl;
    }

    return 0;
}

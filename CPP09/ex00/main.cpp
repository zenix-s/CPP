#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return EXIT_FAILURE;
    }

    try
    {
        BitcoinExchange btc;
        btc.processInput(argv[1]);
    }
    catch (const BitcoinExchange::FileOpenException& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (const BitcoinExchange::InvalidDatabaseException& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
#include "RPN.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        return EXIT_FAILURE;
    }

    try
    {
        RPN rpn;
        int result = rpn.calculate(argv[1]);
        std::cout << result << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

#include "PmergeMe.hpp"
#include "FJSort.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Error" << std::endl;
        return EXIT_FAILURE;
    }

    try
    {
        // PmergeMe pmerge;
        // pmerge.processInput(argc, argv);

        FJSort fjSort;
        fjSort.processInput(argc, argv);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

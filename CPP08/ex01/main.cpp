#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "=== Exercise 01: Span ===" << std::endl;
    std::cout << std::endl;

    // Test the provided example
    std::cout << "Testing provided example:" << std::endl;
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test exceptions
    std::cout << "Testing exceptions:" << std::endl;
    
    // Test adding too many numbers
    try
    {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    // Test span calculation with no numbers
    try
    {
        Span sp(5);
        sp.shortestSpan(); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    // Test span calculation with only one number
    try
    {
        Span sp(5);
        sp.addNumber(42);
        sp.longestSpan(); // Should throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test with large number of elements
    std::cout << "Testing with 10000 numbers:" << std::endl;
    try
    {
        Span sp(10000);
        
        // Create a vector to use with addNumbers
        std::vector<int> numbers;
        srand(time(NULL));
        
        for (int i = 0; i < 10000; ++i)
        {
            numbers.push_back(rand() % 100000);
        }
        
        // Add all numbers using range of iterators
        sp.addNumbers(numbers.begin(), numbers.end());
        
        std::cout << "Added " << sp.size() << " numbers successfully" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test with negative numbers
    std::cout << "Testing with negative numbers:" << std::endl;
    try
    {
        Span sp(5);
        sp.addNumber(-10);
        sp.addNumber(-5);
        sp.addNumber(0);
        sp.addNumber(5);
        sp.addNumber(10);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test copy constructor and assignment operator
    std::cout << "Testing copy constructor and assignment:" << std::endl;
    try
    {
        Span sp1(3);
        sp1.addNumber(1);
        sp1.addNumber(2);
        sp1.addNumber(3);
        
        // Test copy constructor
        Span sp2(sp1);
        std::cout << "Copy - Size: " << sp2.size() << ", Shortest: " << sp2.shortestSpan() << std::endl;
        
        // Test assignment operator
        Span sp3(10);
        sp3 = sp1;
        std::cout << "Assignment - Size: " << sp3.size() << ", Longest: " << sp3.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
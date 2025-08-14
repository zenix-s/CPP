#include "Span.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>

bool test_provided_example()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        return (sp.shortestSpan() == 2 && sp.longestSpan() == 14);
    }
    catch (...)
    {
        return false;
    }
}

bool test_full_container_exception()
{
    try
    {
        Span sp(2);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        return false;
    }
    catch (...)
    {
        return true;
    }
}

bool test_no_span_exception_empty()
{
    try
    {
        Span sp(5);
        sp.shortestSpan();
        return false;
    }
    catch (...)
    {
        return true;
    }
}

bool test_no_span_exception_single()
{
    try
    {
        Span sp(5);
        sp.addNumber(42);
        sp.longestSpan();
        return false;
    }
    catch (...)
    {
        return true;
    }
}

bool test_large_dataset()
{
    try
    {
        Span             sp(10000);
        std::vector<int> numbers;

        for (int i = 0; i < 10000; ++i)
        {
            numbers.push_back(i);
        }

        sp.addNumbers(numbers.begin(), numbers.end());

        return (sp.size() == 10000 && sp.shortestSpan() == 1 && sp.longestSpan() == 9999);
    }
    catch (...)
    {
        return false;
    }
}

bool test_negative_numbers()
{
    try
    {
        Span sp(5);
        sp.addNumber(-10);
        sp.addNumber(-5);
        sp.addNumber(0);
        sp.addNumber(5);
        sp.addNumber(10);

        return (sp.shortestSpan() == 5 && sp.longestSpan() == 20);
    }
    catch (...)
    {
        return false;
    }
}

bool test_copy_constructor()
{
    try
    {
        Span sp1(3);
        sp1.addNumber(1);
        sp1.addNumber(2);
        sp1.addNumber(3);

        Span sp2(sp1);
        return (sp2.size() == 3 && sp2.shortestSpan() == 1 && sp2.longestSpan() == 2);
    }
    catch (...)
    {
        return false;
    }
}

bool test_assignment_operator()
{
    try
    {
        Span sp1(3);
        sp1.addNumber(1);
        sp1.addNumber(5);
        sp1.addNumber(10);

        Span sp2(10);
        sp2 = sp1;
        return (sp2.size() == 3 && sp2.longestSpan() == 9);
    }
    catch (...)
    {
        return false;
    }
}

bool test_duplicate_numbers()
{
    try
    {
        Span sp(5);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(10);
        sp.addNumber(15);

        return (sp.shortestSpan() == 0 && sp.longestSpan() == 10);
    }
    catch (...)
    {
        return false;
    }
}

bool test_random_dataset()
{
    try
    {
        Span             sp(1000);
        std::vector<int> numbers;
        srand(42);

        for (int i = 0; i < 1000; ++i)
        {
            numbers.push_back(rand() % 1000);
        }

        sp.addNumbers(numbers.begin(), numbers.end());

        unsigned int shortest = sp.shortestSpan();
        unsigned int longest = sp.longestSpan();

        return (sp.size() == 1000 && shortest <= longest);
    }
    catch (...)
    {
        return false;
    }
}

int main()
{
    std::cout << "=== Basic Functionality Tests ===" << std::endl;
    std::cout << "test 0: provided example test - " << (test_provided_example() ? "OK" : "KO") << std::endl;
    std::cout << "test 1: negative numbers handling - " << (test_negative_numbers() ? "OK" : "KO") << std::endl;
    std::cout << "test 2: duplicate numbers handling - " << (test_duplicate_numbers() ? "OK" : "KO") << std::endl;

    std::cout << std::endl << "=== Exception Handling Tests ===" << std::endl;
    std::cout << "test 3: full container exception - " << (test_full_container_exception() ? "OK" : "KO") << std::endl;
    std::cout << "test 4: no span exception (empty) - " << (test_no_span_exception_empty() ? "OK" : "KO") << std::endl;
    std::cout << "test 5: no span exception (single) - " << (test_no_span_exception_single() ? "OK" : "KO")
              << std::endl;

    std::cout << std::endl << "=== Copy/Assignment Tests ===" << std::endl;
    std::cout << "test 6: copy constructor - " << (test_copy_constructor() ? "OK" : "KO") << std::endl;
    std::cout << "test 7: assignment operator - " << (test_assignment_operator() ? "OK" : "KO") << std::endl;

    std::cout << std::endl << "=== Performance Tests ===" << std::endl;
    std::cout << "test 8: large dataset (10000 numbers) - " << (test_large_dataset() ? "OK" : "KO") << std::endl;
    std::cout << "test 9: random dataset (1000 numbers) - " << (test_random_dataset() ? "OK" : "KO") << std::endl;

    return 0;
}

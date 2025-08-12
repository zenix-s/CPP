#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main()
{
    std::cout << "=== Exercise 00: Easy find ===" << std::endl;
    std::cout << std::endl;

    // Test with vector
    std::cout << "Testing with std::vector:" << std::endl;
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found value 3 at position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found value 42 at position: " << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test with list
    std::cout << "Testing with std::list:" << std::endl;
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    try
    {
        easyfind(lst, 30);
        std::cout << "Found value 30 in list" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        easyfind(lst, 100);
        std::cout << "Found value 100 in list" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test with deque
    std::cout << "Testing with std::deque:" << std::endl;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);

    try
    {
        std::deque<int>::iterator it = easyfind(deq, 200);
        std::cout << "Found value 200 at position: " << std::distance(deq.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::deque<int>::iterator it = easyfind(deq, 999);
        std::cout << "Found value 999 at position: " << std::distance(deq.begin(), it) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test with const container
    std::cout << "Testing with const container:" << std::endl;
    const std::vector<int> const_vec(vec);
    try
    {
        easyfind(const_vec, 1);
        std::cout << "Found value 1 in const vector" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
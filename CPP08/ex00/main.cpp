#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

bool test_vector_find_existing()
{
    try
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::vector<int>::iterator it = easyfind(vec, 3);
        return (std::distance(vec.begin(), it) == 2);
    }
    catch (...)
    {
        return false;
    }
}

bool test_vector_find_nonexisting()
{
    try
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);

        easyfind(vec, 42);
        return false;
    }
    catch (...)
    {
        return true;
    }
}

bool test_list_find_existing()
{
    try
    {
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);

        std::list<int>::iterator it = easyfind(lst, 30);
        return (*it == 30);
    }
    catch (...)
    {
        return false;
    }
}

bool test_list_find_nonexisting()
{
    try
    {
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);

        easyfind(lst, 100);
        return false;
    }
    catch (...)
    {
        return true;
    }
}

bool test_deque_find_existing()
{
    try
    {
        std::deque<int> deq;
        deq.push_back(100);
        deq.push_back(200);
        deq.push_back(300);

        std::deque<int>::iterator it = easyfind(deq, 200);
        return (std::distance(deq.begin(), it) == 1);
    }
    catch (...)
    {
        return false;
    }
}

bool test_deque_find_nonexisting()
{
    try
    {
        std::deque<int> deq;
        deq.push_back(100);
        deq.push_back(200);

        easyfind(deq, 999);
        return false;
    }
    catch (...)
    {
        return true;
    }
}

bool test_const_container()
{
    try
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);

        const std::vector<int>           const_vec(vec);
        std::vector<int>::const_iterator it = easyfind(const_vec, 1);
        return (*it == 1);
    }
    catch (...)
    {
        return false;
    }
}

bool test_empty_container()
{
    try
    {
        std::vector<int> vec;
        easyfind(vec, 1);
        return false;
    }
    catch (...)
    {
        return true;
    }
}

int main()
{
    std::cout << "=== STL Container Tests ===" << std::endl;
    std::cout << "test 0: vector find existing value - " << (test_vector_find_existing() ? "OK" : "KO") << std::endl;
    std::cout << "test 1: vector find non-existing value - " << (test_vector_find_nonexisting() ? "OK" : "KO")
              << std::endl;
    std::cout << "test 2: list find existing value - " << (test_list_find_existing() ? "OK" : "KO") << std::endl;
    std::cout << "test 3: list find non-existing value - " << (test_list_find_nonexisting() ? "OK" : "KO") << std::endl;
    std::cout << "test 4: deque find existing value - " << (test_deque_find_existing() ? "OK" : "KO") << std::endl;
    std::cout << "test 5: deque find non-existing value - " << (test_deque_find_nonexisting() ? "OK" : "KO")
              << std::endl;

    std::cout << std::endl << "=== Special Cases Tests ===" << std::endl;
    std::cout << "test 6: const container functionality - " << (test_const_container() ? "OK" : "KO") << std::endl;
    std::cout << "test 7: empty container exception - " << (test_empty_container() ? "OK" : "KO") << std::endl;

    return 0;
}

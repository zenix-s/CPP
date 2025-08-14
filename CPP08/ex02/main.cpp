#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>
#include <vector>

bool test_provided_example()
{
    try
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);

        if (mstack.top() != 17)
            return false;

        mstack.pop();

        if (mstack.size() != 1)
            return false;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;

        int count = 0;
        while (it != ite)
        {
            ++it;
            ++count;
        }

        return (count == 5);
    }
    catch (...)
    {
        return false;
    }
}

bool test_comparison_with_list()
{
    try
    {
        MutantStack<int> mstack;
        std::list<int>   mlist;

        mstack.push(5);
        mstack.push(17);
        mlist.push_back(5);
        mlist.push_back(17);

        mstack.pop();
        mlist.pop_back();

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);

        if (mstack.size() != mlist.size())
            return false;

        MutantStack<int>::iterator stack_it = mstack.begin();
        std::list<int>::iterator   list_it = mlist.begin();

        while (stack_it != mstack.end() && list_it != mlist.end())
        {
            if (*stack_it != *list_it)
                return false;
            ++stack_it;
            ++list_it;
        }

        return (stack_it == mstack.end() && list_it == mlist.end());
    }
    catch (...)
    {
        return false;
    }
}

bool test_reverse_iterators()
{
    try
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);

        std::vector<int> forward_order;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        {
            forward_order.push_back(*it);
        }

        std::vector<int> reverse_order;
        for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
        {
            reverse_order.push_back(*it);
        }

        if (forward_order.size() != reverse_order.size())
            return false;

        for (size_t i = 0; i < forward_order.size(); ++i)
        {
            if (forward_order[i] != reverse_order[forward_order.size() - 1 - i])
                return false;
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool test_const_iterators()
{
    try
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);

        const MutantStack<int> const_mstack(mstack);

        int count = 0;
        for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it)
        {
            count++;
        }

        if (count != 3)
            return false;

        count = 0;
        for (MutantStack<int>::const_reverse_iterator it = const_mstack.rbegin(); it != const_mstack.rend(); ++it)
        {
            count++;
        }

        return (count == 3);
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
        MutantStack<int> original;
        original.push(1);
        original.push(2);
        original.push(3);

        MutantStack<int> copy(original);

        if (copy.size() != original.size())
            return false;

        if (copy.top() != original.top())
            return false;

        original.push(4);

        return (copy.size() == 3 && original.size() == 4);
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
        MutantStack<int> original;
        original.push(1);
        original.push(2);
        original.push(3);

        MutantStack<int> assigned;
        assigned = original;

        if (assigned.size() != original.size())
            return false;

        if (assigned.top() != original.top())
            return false;

        original.push(4);

        return (assigned.size() == 3 && original.size() == 4);
    }
    catch (...)
    {
        return false;
    }
}

bool test_string_type()
{
    try
    {
        MutantStack<std::string> strStack;
        strStack.push("Hello");
        strStack.push("World");
        strStack.push("!");

        if (strStack.size() != 3)
            return false;

        if (strStack.top() != "!")
            return false;

        int count = 0;
        for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
        {
            count++;
        }

        return (count == 3);
    }
    catch (...)
    {
        return false;
    }
}

bool test_empty_stack()
{
    try
    {
        MutantStack<int> empty;

        if (empty.size() != 0)
            return false;

        if (empty.begin() != empty.end())
            return false;

        if (empty.rbegin() != empty.rend())
            return false;

        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool test_stack_conversion()
{
    try
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);

        std::stack<int> s(mstack);

        if (s.size() != mstack.size())
            return false;

        if (s.top() != mstack.top())
            return false;

        return true;
    }
    catch (...)
    {
        return false;
    }
}

bool test_iterator_operators()
{
    try
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);

        MutantStack<int>::iterator it = mstack.begin();

        ++it;

        --it;

        if (it != mstack.begin())
            return false;

        if (*it != 10)
            return false;

        return true;
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
    std::cout << "test 1: comparison with std::list - " << (test_comparison_with_list() ? "OK" : "KO") << std::endl;
    std::cout << "test 2: stack conversion compatibility - " << (test_stack_conversion() ? "OK" : "KO") << std::endl;

    std::cout << std::endl << "=== Iterator Tests ===" << std::endl;
    std::cout << "test 3: reverse iterators - " << (test_reverse_iterators() ? "OK" : "KO") << std::endl;
    std::cout << "test 4: const iterators - " << (test_const_iterators() ? "OK" : "KO") << std::endl;
    std::cout << "test 5: iterator operators - " << (test_iterator_operators() ? "OK" : "KO") << std::endl;

    std::cout << std::endl << "=== Copy/Assignment Tests ===" << std::endl;
    std::cout << "test 6: copy constructor - " << (test_copy_constructor() ? "OK" : "KO") << std::endl;
    std::cout << "test 7: assignment operator - " << (test_assignment_operator() ? "OK" : "KO") << std::endl;

    std::cout << std::endl << "=== Type/Edge Case Tests ===" << std::endl;
    std::cout << "test 8: string type support - " << (test_string_type() ? "OK" : "KO") << std::endl;
    std::cout << "test 9: empty stack behavior - " << (test_empty_stack() ? "OK" : "KO") << std::endl;

    return 0;
}

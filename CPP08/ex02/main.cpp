#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "=== Exercise 02: Mutated abomination ===" << std::endl;
    std::cout << std::endl;

    // Test the provided example
    std::cout << "Testing provided example:" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << std::endl;

    // Compare with std::list behavior
    std::cout << "Comparing with std::list (should have same output):" << std::endl;
    {
        std::list<int> mlist;
        mlist.push_back(5);
        mlist.push_back(17);
        std::cout << mlist.back() << std::endl;
        mlist.pop_back();
        std::cout << mlist.size() << std::endl;
        mlist.push_back(3);
        mlist.push_back(5);
        mlist.push_back(737);
        mlist.push_back(0);
        
        std::list<int>::iterator it = mlist.begin();
        std::list<int>::iterator ite = mlist.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    std::cout << std::endl;

    // Test reverse iterators
    std::cout << "Testing reverse iterators:" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        mstack.push(4);
        mstack.push(5);

        std::cout << "Forward iteration: ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Reverse iteration: ";
        for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // Test const iterators
    std::cout << "Testing const iterators:" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);

        const MutantStack<int> const_mstack(mstack);
        
        std::cout << "Const forward iteration: ";
        for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Const reverse iteration: ";
        for (MutantStack<int>::const_reverse_iterator it = const_mstack.rbegin(); it != const_mstack.rend(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // Test copy constructor and assignment
    std::cout << "Testing copy constructor and assignment:" << std::endl;
    {
        MutantStack<int> original;
        original.push(1);
        original.push(2);
        original.push(3);

        // Test copy constructor
        MutantStack<int> copy(original);
        std::cout << "Copy size: " << copy.size() << ", top: " << copy.top() << std::endl;

        // Test assignment operator
        MutantStack<int> assigned;
        assigned = original;
        std::cout << "Assigned size: " << assigned.size() << ", top: " << assigned.top() << std::endl;

        // Modify original and verify copies are independent
        original.push(4);
        std::cout << "After modifying original:" << std::endl;
        std::cout << "Original size: " << original.size() << std::endl;
        std::cout << "Copy size: " << copy.size() << std::endl;
        std::cout << "Assigned size: " << assigned.size() << std::endl;
    }

    std::cout << std::endl;

    // Test with different types
    std::cout << "Testing with string type:" << std::endl;
    {
        MutantStack<std::string> strStack;
        strStack.push("Hello");
        strStack.push("World");
        strStack.push("!");

        std::cout << "String stack contents: ";
        for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // Test empty stack iterators
    std::cout << "Testing empty stack:" << std::endl;
    {
        MutantStack<int> empty;
        std::cout << "Empty stack size: " << empty.size() << std::endl;
        std::cout << "begin() == end(): " << (empty.begin() == empty.end() ? "true" : "false") << std::endl;
    }

    return 0;
}
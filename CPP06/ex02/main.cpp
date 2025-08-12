#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"
#include <iostream>

int main(void)
{
    std::cout << "Testing Base type identification" << std::endl;
    std::cout << std::endl;

    // Test with multiple generated objects
    for (int i = 0; i < 10; ++i)
    {
        Base* ptr = generate();

        std::cout << "Test " << i + 1 << ":" << std::endl;
        std::cout << "Generated object address: " << ptr << std::endl;

        std::cout << "Identify by pointer: ";
        identify(ptr);

        std::cout << "Identify by reference: ";
        identify(*ptr);

        delete ptr;
        std::cout << std::endl;
    }

    // Test with specific instances
    std::cout << "Testing with specific instances:" << std::endl;
    std::cout << std::endl;

    A* a = new A();
    B* b = new B();
    C* c = new C();

    std::cout << "Testing A instance:" << std::endl;
    std::cout << "By pointer: ";
    identify(a);
    std::cout << "By reference: ";
    identify(*a);
    std::cout << std::endl;

    std::cout << "Testing B instance:" << std::endl;
    std::cout << "By pointer: ";
    identify(b);
    std::cout << "By reference: ";
    identify(*b);
    std::cout << std::endl;

    std::cout << "Testing C instance:" << std::endl;
    std::cout << "By pointer: ";
    identify(c);
    std::cout << "By reference: ";
    identify(*c);
    std::cout << std::endl;

    // Test with Base pointers pointing to derived objects
    Base* baseA = a;
    Base* baseB = b;
    Base* baseC = c;

    std::cout << "Testing through Base pointers:" << std::endl;
    std::cout << "A through Base*: ";
    identify(baseA);
    std::cout << "B through Base*: ";
    identify(baseB);
    std::cout << "C through Base*: ";
    identify(baseC);

    delete a;
    delete b;
    delete c;

    return 0;
}

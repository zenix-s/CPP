#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    Fixed       a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "\n--- Additional tests ---" << std::endl;
    {
        Fixed x(10.5f);
        Fixed y(2.25f);

        std::cout << "x: " << x << ", y: " << y << std::endl;
        std::cout << "x + y = " << (x + y) << std::endl;
        std::cout << "x - y = " << (x - y) << std::endl;
        std::cout << "x * y = " << (x * y) << std::endl;
        std::cout << "x / y = " << (x / y) << std::endl;
    }
    std::cout << "My tests" << std::endl;
    {
        Fixed a;
        Fixed b(10);
        Fixed c(42.42f);
        Fixed d(b);

        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "c: " << c << std::endl;
        std::cout << "d: " << d << std::endl;

        a = Fixed(1234.4321f);
        std::cout << "a after assignment: " << a << std::endl;

        std::cout << "b > c: " << (b > c) << std::endl;
        std::cout << "b < c: " << (b < c) << std::endl;
        std::cout << "b >= d: " << (b >= d) << std::endl;
        std::cout << "b <= d: " << (b <= d) << std::endl;
        std::cout << "b == d: " << (b == d) << std::endl;
        std::cout << "b != d: " << (b != d) << std::endl;

        Fixed e = b + c;
        Fixed f = b - c;
        Fixed g = b * c;
        Fixed h = b / c;

        std::cout << "b + c: " << e << std::endl;
        std::cout << "b - c: " << f << std::endl;
        std::cout << "b * c: " << g << std::endl;
        std::cout << "b / c: " << h << std::endl;

        std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
        std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;

        Fixed i(42.42f);
        Fixed j(i);
        std::cout << "i: " << i << std::endl;
        std::cout << "++i: " << ++i << std::endl;
        std::cout << "i: " << i << std::endl;
        std::cout << "i++: " << i++ << std::endl;
        std::cout << "i: " << i << std::endl;

        std::cout << "j: " << j << std::endl;
        std::cout << "--j: " << --j << std::endl;
        std::cout << "j: " << j << std::endl;
        std::cout << "j--: " << j-- << std::endl;
        std::cout << "j: " << j << std::endl;
    }

    return 0;
}
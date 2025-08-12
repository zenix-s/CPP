#include "iter.hpp"
#include <iostream>
#include <string>

// Test functions
template <typename T>
void print(const T& element)
{
    std::cout << element << " ";
}

template <typename T>
void increment(T& element)
{
    element++;
}

void toUpper(char& c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';
}

void addExclamation(std::string& str)
{
    str += "!";
}

int main()
{
    std::cout << "=== Exercise 01: Iter ===" << std::endl;
    std::cout << std::endl;

    std::cout << "Testing with int array:" << std::endl;
    int    intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original array: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;

    iter(intArray, intSize, increment<int>);
    std::cout << "After increment: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "Testing with double array:" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Original array: ";
    iter(doubleArray, doubleSize, print<double>);
    std::cout << std::endl;

    iter(doubleArray, doubleSize, increment<double>);
    std::cout << "After increment: ";
    iter(doubleArray, doubleSize, print<double>);
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "Testing with char array:" << std::endl;
    char   charArray[] = {'h', 'e', 'l', 'l', 'o'};
    size_t charSize = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "Original array: ";
    iter(charArray, charSize, print<char>);
    std::cout << std::endl;

    iter(charArray, charSize, toUpper);
    std::cout << "After toUpper: ";
    iter(charArray, charSize, print<char>);
    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "Testing with string array:" << std::endl;
    std::string stringArray[] = {"Hello", "World", "Test"};
    size_t      stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Original array: ";
    iter(stringArray, stringSize, print<std::string>);
    std::cout << std::endl;

    iter(stringArray, stringSize, addExclamation);
    std::cout << "After adding exclamation: ";
    iter(stringArray, stringSize, print<std::string>);
    std::cout << std::endl;

    return 0;
}

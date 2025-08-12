#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    std::cout << "=== Exercise 02: Array ===" << std::endl;
    std::cout << std::endl;

    // Test default constructor
    std::cout << "Testing default constructor:" << std::endl;
    try
    {
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test parameterized constructor
    std::cout << "Testing parameterized constructor:" << std::endl;
    try
    {
        Array<int> arr(5);
        std::cout << "Array size: " << arr.size() << std::endl;
        
        // Test default initialization
        std::cout << "Default values: ";
        for (unsigned int i = 0; i < arr.size(); i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        
        // Modify values
        for (unsigned int i = 0; i < arr.size(); i++)
        {
            arr[i] = i * 10;
        }
        
        std::cout << "Modified values: ";
        for (unsigned int i = 0; i < arr.size(); i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test copy constructor
    std::cout << "Testing copy constructor:" << std::endl;
    try
    {
        Array<int> original(3);
        original[0] = 1;
        original[1] = 2;
        original[2] = 3;
        
        Array<int> copy(original);
        
        std::cout << "Original: ";
        for (unsigned int i = 0; i < original.size(); i++)
        {
            std::cout << original[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "Copy: ";
        for (unsigned int i = 0; i < copy.size(); i++)
        {
            std::cout << copy[i] << " ";
        }
        std::cout << std::endl;
        
        // Modify original to test deep copy
        original[0] = 42;
        std::cout << "After modifying original[0] to 42:" << std::endl;
        std::cout << "Original[0]: " << original[0] << std::endl;
        std::cout << "Copy[0]: " << copy[0] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test assignment operator
    std::cout << "Testing assignment operator:" << std::endl;
    try
    {
        Array<int> arr1(3);
        arr1[0] = 10;
        arr1[1] = 20;
        arr1[2] = 30;
        
        Array<int> arr2(5);
        arr2 = arr1;
        
        std::cout << "arr1 size: " << arr1.size() << ", values: ";
        for (unsigned int i = 0; i < arr1.size(); i++)
        {
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;
        
        std::cout << "arr2 size: " << arr2.size() << ", values: ";
        for (unsigned int i = 0; i < arr2.size(); i++)
        {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;
        
        // Test self-assignment
        arr1 = arr1;
        std::cout << "After self-assignment, arr1 size: " << arr1.size() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test bounds checking
    std::cout << "Testing bounds checking:" << std::endl;
    try
    {
        Array<int> arr(3);
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        
        std::cout << "Valid access arr[1]: " << arr[1] << std::endl;
        
        // This should throw an exception
        std::cout << "Attempting to access arr[5]..." << std::endl;
        std::cout << arr[5] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test with empty array bounds checking
    std::cout << "Testing empty array bounds checking:" << std::endl;
    try
    {
        Array<int> empty;
        std::cout << "Attempting to access empty[0]..." << std::endl;
        std::cout << empty[0] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught expected exception: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test with different types
    std::cout << "Testing with string type:" << std::endl;
    try
    {
        Array<std::string> strArr(3);
        strArr[0] = "Hello";
        strArr[1] = "World";
        strArr[2] = "!";
        
        std::cout << "String array: ";
        for (unsigned int i = 0; i < strArr.size(); i++)
        {
            std::cout << strArr[i] << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test with double type
    std::cout << "Testing with double type:" << std::endl;
    try
    {
        Array<double> doubleArr(4);
        doubleArr[0] = 1.1;
        doubleArr[1] = 2.2;
        doubleArr[2] = 3.3;
        doubleArr[3] = 4.4;
        
        std::cout << "Double array: ";
        for (unsigned int i = 0; i < doubleArr.size(); i++)
        {
            std::cout << doubleArr[i] << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    // Test const correctness
    std::cout << "Testing const correctness:" << std::endl;
    try
    {
        Array<int> arr(3);
        arr[0] = 100;
        arr[1] = 200;
        arr[2] = 300;
        
        const Array<int>& constRef = arr;
        std::cout << "Accessing const array: " << constRef[1] << std::endl;
        std::cout << "Const array size: " << constRef.size() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
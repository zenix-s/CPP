# CPP Module 07 - C++ Templates

This module focuses on C++ templates, introducing the concept of generic programming in C++.

## Overview

Templates are a powerful feature in C++ that allow you to write generic and reusable code. They enable you to create functions and classes that work with any data type without having to rewrite the code for each specific type.

## Exercises

### Exercise 00: Start with a few functions
**Files:** `ex00/whatever.hpp`, `ex00/main.cpp`, `ex00/Makefile`

Implement three basic function templates:
- `swap`: Swaps the values of two given parameters
- `min`: Returns the smallest of two values (returns second if equal)
- `max`: Returns the greatest of two values (returns second if equal)

**Key Concepts:**
- Function templates
- Template parameter deduction
- Generic programming basics

### Exercise 01: Iter
**Files:** `ex01/iter.hpp`, `ex01/main.cpp`, `ex01/Makefile`

Implement a function template `iter` that:
- Takes an array address, its length, and a function as parameters
- Applies the given function to each element of the array
- Works with any type of array and any compatible function

**Key Concepts:**
- Function templates with multiple template parameters
- Function pointers and template functions as parameters
- Template instantiation

### Exercise 02: Array
**Files:** `ex02/Array.hpp`, `ex02/main.cpp`, `ex02/Makefile`

Develop a class template `Array<T>` that implements:
- Default constructor (empty array)
- Constructor with size parameter
- Copy constructor and assignment operator (deep copy)
- Subscript operator `[]` with bounds checking
- `size()` member function
- Exception handling for out-of-bounds access

**Key Concepts:**
- Class templates
- Template instantiation
- Dynamic memory management with templates
- Exception handling
- Orthodox Canonical Form with templates

## Compilation

Each exercise can be compiled individually:
```bash
cd ex00 && make
cd ex01 && make
cd ex02 && make
```

Or compile all exercises at once:
```bash
make all
```

## Testing

Run individual tests:
```bash
cd ex00 && ./whatever
cd ex01 && ./iter
cd ex02 && ./array
```

Or run all tests:
```bash
make test
```

## Key Learning Points

1. **Template Syntax**: Understanding the `template<typename T>` syntax
2. **Type Deduction**: How the compiler deduces template parameters
3. **Template Instantiation**: When and how templates are instantiated
4. **Generic Programming**: Writing code that works with multiple types
5. **Template Specialization**: Understanding when specific implementations might be needed
6. **Memory Management**: Proper allocation and deallocation in template classes
7. **Exception Safety**: Handling errors in template code

## Important Notes

- All templates are defined in header files (no separate .cpp files for template definitions)
- Template code must be C++98 compliant
- Proper exception handling is implemented for bounds checking
- Deep copy semantics are maintained in the Array class
- All output uses standard std::cout for simplicity and portability

## Expected Output

### Exercise 00
```
a = 3, b = 2
min( a, b ) = 2
max( a, b ) = 3
c = chaine2, d = chaine1
min( c, d ) = chaine1
max( c, d ) = chaine2
```

### Exercise 01
```
=== Exercise 01: Iter ===

Testing with int array:
Original array: 1 2 3 4 5 
After increment: 2 3 4 5 6 

Testing with double array:
Original array: 1.1 2.2 3.3 4.4 5.5 
After increment: 2.1 3.2 4.3 5.4 6.5 

Testing with char array:
Original array: h e l l o 
After toUpper: H E L L O 

Testing with string array:
Original array: Hello World Test 
After adding exclamation: Hello! World! Test! 
```

### Exercise 02
```
=== Exercise 02: Array ===

Testing default constructor:
Empty array size: 0

Testing parameterized constructor:
Array size: 5
Default values: 0 0 0 0 0 
Modified values: 0 10 20 30 40 

Testing copy constructor:
Original: 1 2 3 
Copy: 1 2 3 
After modifying original[0] to 42:
Original[0]: 42
Copy[0]: 1

Testing bounds checking:
Valid access arr[1]: 2
Attempting to access arr[5]...
Caught expected exception: Array index out of bounds
```

This module provides a solid foundation for understanding C++ templates and generic programming concepts.
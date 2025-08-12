# CPP Module 08 - Templated containers, iterators, algorithms

This module focuses on using C++ STL containers, iterators, and algorithms. Unlike previous modules, this is the first time we're allowed to use STL containers and algorithms to solve problems.

## Overview

Module 08 introduces the practical use of the Standard Template Library (STL) in C++. The exercises demonstrate how to work with templated containers, use iterators effectively, and apply STL algorithms to solve common programming problems.

## Exercises

### Exercise 00: Easy find
**Files:** `ex00/easyfind.hpp`, `ex00/main.cpp`, `ex00/Makefile`

Implement a function template `easyfind` that:
- Accepts a container type T and an integer value
- Finds the first occurrence of the integer in the container
- Returns an iterator to the found element
- Throws an exception if the value is not found
- Works with any STL container that supports iterators

**Key Concepts:**
- Function templates
- STL algorithms (`std::find`)
- Iterator usage
- Exception handling
- Template parameter deduction

### Exercise 01: Span
**Files:** `ex01/Span.hpp`, `ex01/Span.cpp`, `ex01/main.cpp`, `ex01/Makefile`

Develop a `Span` class that:
- Stores a maximum of N integers
- Provides `addNumber()` to add single numbers
- Provides `addNumbers()` to add multiple numbers using iterators
- Calculates shortest and longest spans between stored numbers
- Handles edge cases with proper exception throwing
- Can efficiently handle large datasets (10,000+ numbers)

**Key Concepts:**
- STL containers (`std::vector`)
- STL algorithms (`std::sort`, `std::min_element`, `std::max_element`)
- Iterator ranges
- Exception design
- Performance considerations
- Orthodox Canonical Form

### Exercise 02: Mutated abomination
**Files:** `ex02/MutantStack.hpp`, `ex02/MutantStack.tpp`, `ex02/main.cpp`, `ex02/Makefile`

Create a `MutantStack` class template that:
- Inherits from `std::stack`
- Adds iterator functionality to the normally non-iterable stack
- Provides forward and reverse iterators
- Supports const and non-const iterations
- Maintains all original stack functionality
- Should behave identically to other STL containers when iterating

**Key Concepts:**
- Template inheritance
- Iterator types and implementation
- Accessing protected members of base classes
- Template specialization
- Container adapter modification

## Compilation

Each exercise can be compiled individually:
```bash
cd ex00 && make
cd ex01 && make
cd ex02 && make
```

Or compile all exercises at once from the CPP08 directory:
```bash
make -C ex00 && make -C ex01 && make -C ex02
```

## Testing

Run individual tests:
```bash
cd ex00 && ./easyfind
cd ex01 && ./span
cd ex02 && ./mutantstack
```

## Key Learning Points

1. **STL Containers**: Understanding when and how to use `std::vector`, `std::list`, `std::deque`, and `std::stack`
2. **STL Algorithms**: Practical application of `std::find`, `std::sort`, `std::min_element`, `std::max_element`
3. **Iterator Concepts**: Working with different iterator types and ranges
4. **Template Design**: Creating flexible, reusable template functions and classes
5. **Exception Safety**: Proper exception handling in template code
6. **Performance**: Understanding performance implications of different STL choices
7. **Container Adaptation**: Modifying existing containers to add functionality

## Important Notes

- This is the first module where STL containers and algorithms are allowed
- Template implementations are in header files (.hpp) or template files (.tpp)
- All code must be C++98 compliant
- Proper exception handling is crucial for robust code
- Iterator validity and container-specific behaviors must be considered
- Performance testing with large datasets (10,000+ elements) is required

## Expected Output

### Exercise 00
```
=== Exercise 00: Easy find ===

Testing with std::vector:
Found value 3 at position: 2
Error: Value not found in container

Testing with std::list:
Found value 30 in list
Error: Value not found in container

Testing with std::deque:
Found value 200 at position: 1
Error: Value not found in container

Testing with const container:
Found value 1 in const vector
```

### Exercise 01
```
=== Exercise 01: Span ===

Testing provided example:
2
14

Testing exceptions:
Caught expected exception: Container is full, cannot add more numbers
Caught expected exception: Not enough numbers to calculate span (need at least 2)
Caught expected exception: Not enough numbers to calculate span (need at least 2)

Testing with 10000 numbers:
Added 10000 numbers successfully
Shortest span: 0
Longest span: 99999
```

### Exercise 02
```
=== Exercise 02: Mutated abomination ===

Testing provided example:
17
1
5
3
5
737
0

Comparing with std::list (should have same output):
17
1
5
3
5
737
0

Testing reverse iterators:
Forward iteration: 5 3 5 737 0 
Reverse iteration: 0 737 5 3 5 
```

## Design Considerations

### Exercise 00
- Uses `std::find` algorithm for efficient searching
- Provides both const and non-const overloads
- Template function works with any container supporting iterators

### Exercise 01
- Uses `std::vector` for dynamic storage
- Leverages `std::sort` for efficient shortest span calculation
- Uses `std::min_element` and `std::max_element` for longest span
- Iterator-based `addNumbers` method for bulk insertion
- Comprehensive exception handling

### Exercise 02
- Inherits from `std::stack` to maintain all original functionality
- Accesses protected member `c` (underlying container) for iterator implementation
- Provides full iterator interface (forward, reverse, const variants)
- Template implementation allows use with any type

This module demonstrates the power and flexibility of the STL while teaching best practices for template programming and container usage in C++.
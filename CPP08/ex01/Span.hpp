#pragma once

#include <vector>
#include <stdexcept>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    // Orthodox Canonical Form
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    // Member functions
    void addNumber(int number);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    // Utility functions
    unsigned int size() const;
    unsigned int maxSize() const;

    // Exceptions
    class FullContainerException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class NoSpanException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};
#include "Span.hpp"
#include <algorithm>

// Orthodox Canonical Form
Span::Span() : _maxSize(0), _numbers()
{
}

Span::Span(unsigned int n) : _maxSize(n), _numbers()
{
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

// Member functions
void Span::addNumber(int number)
{
    if (_numbers.size() >= _maxSize)
        throw FullContainerException();
    _numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while (begin != end)
    {
        addNumber(*begin);
        ++begin;
    }
}

unsigned int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();
    
    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());
    
    unsigned int minSpan = static_cast<unsigned int>(sorted[1] - sorted[0]);
    for (size_t i = 2; i < sorted.size(); ++i)
    {
        unsigned int currentSpan = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        if (currentSpan < minSpan)
            minSpan = currentSpan;
    }
    
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();
    
    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
    
    return static_cast<unsigned int>(*maxIt - *minIt);
}

// Utility functions
unsigned int Span::size() const
{
    return _numbers.size();
}

unsigned int Span::maxSize() const
{
    return _maxSize;
}

// Exception implementations
const char* Span::FullContainerException::what() const throw()
{
    return "Container is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw()
{
    return "Not enough numbers to calculate span (need at least 2)";
}
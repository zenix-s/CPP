#pragma once

#include <vector>

class Span
{
  private:
    unsigned int     _maxSize;
    std::vector<int> _numbers;

  public:
    Span();
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void addNumbers(int start, int end);

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    unsigned int size() const;
    unsigned int maxSize() const;

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

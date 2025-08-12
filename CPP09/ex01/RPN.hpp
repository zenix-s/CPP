#pragma once

#include <exception>
#include <stack>
#include <string>

class RPN
{
  private:
    std::stack<int> _stack;

    bool isOperator(const std::string& token) const;
    bool isNumber(const std::string& token) const;
    int  performOperation(int a, int b, char op) const;
    void processToken(const std::string& token);
    void clearStack();

  public:
    RPN();
    RPN(const RPN& other);
    ~RPN();
    RPN& operator=(const RPN& other);

    int calculate(const std::string& expression);

    class InvalidExpressionException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    class DivisionByZeroException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    class EmptyStackException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

    class InvalidNumberException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
};
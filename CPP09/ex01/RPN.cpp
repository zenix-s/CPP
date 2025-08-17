#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN()
{
}



RPN::RPN(const RPN& other) : _stack(other._stack)
{
}

RPN::~RPN()
{
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

bool RPN::isOperator(const std::string& token) const
{
    return token.length() == 1 && 
           (token[0] == '+' || token[0] == '-' || 
            token[0] == '*' || token[0] == '/');
}

bool RPN::isNumber(const std::string& token) const
{
    if (token.empty())
        return false;
    
    size_t start = 0;
    if (token[0] == '-' || token[0] == '+')
    {
        if (token.length() == 1)
            return false;
        start = 1;
    }
    
    for (size_t i = start; i < token.length(); ++i)
    {
        if (!std::isdigit(token[i]))
            return false;
    }
    
    return true;
}

int RPN::performOperation(int a, int b, char op) const
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0)
                throw DivisionByZeroException();
            return a / b;
        default:
            throw InvalidExpressionException();
    }
}

void RPN::processToken(const std::string& token)
{
    if (isNumber(token))
    {
        int num = std::atoi(token.c_str());
        if (num >= 10 || num < 0)
            throw InvalidNumberException();
        _stack.push(num);
    }
    else if (isOperator(token))
    {
        if (_stack.size() < 2)
            throw EmptyStackException();
        
        int b = _stack.top();
        _stack.pop();
        int a = _stack.top();
        _stack.pop();
        
        int result = performOperation(a, b, token[0]);
        _stack.push(result);
    }
    else
    {
        throw InvalidExpressionException();
    }
}

void RPN::clearStack()
{
    while (!_stack.empty())
        _stack.pop();
}

int RPN::calculate(const std::string& expression)
{
    clearStack();
    
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token)
    {
        processToken(token);
    }
    
    if (_stack.size() != 1)
        throw InvalidExpressionException();
    
    return _stack.top();
}

const char* RPN::InvalidExpressionException::what() const throw()
{
    return "Error";
}

const char* RPN::DivisionByZeroException::what() const throw()
{
    return "Error";
}

const char* RPN::EmptyStackException::what() const throw()
{
    return "Error";
}

const char* RPN::InvalidNumberException::what() const throw()
{
    return "Error";
}

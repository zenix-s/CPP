#include "RPN.hpp"
#include <climits>
#include <cmath>
#include <cstdlib>
#include <sstream>

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
    return token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
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

double RPN::performOperation(double a, double b, char op) const
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
                throw std::logic_error("Error");
            return a / b;
        default:
            throw std::logic_error("Error");
    }
}

void RPN::processToken(const std::string& token)
{
    if (isNumber(token))
    {
        double num = std::atof(token.c_str());
        if (num >= 10 || num < 0)
            throw std::logic_error("Error");
        _stack.push(num);
    }
    else if (isOperator(token))
    {
        if (_stack.size() < 2)
            throw std::logic_error("Error");

        double b = _stack.top();
        _stack.pop();
        double a = _stack.top();
        _stack.pop();

        double result = performOperation(a, b, token[0]);

        if (std::isnan(result) || std::isinf(result) || result > INT_MAX || result < INT_MIN)
            throw std::logic_error("Error");

        _stack.push(result);
    }
    else
    {
        throw std::logic_error("Error");
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
    std::string        token;

    while (iss >> token)
        processToken(token);

    if (_stack.size() != 1)
        throw std::logic_error("Error");

    double result = _stack.top();

    return static_cast<int>(result);
}

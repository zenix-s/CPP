#pragma once

#include <stack>
#include <string>

class RPN
{
  private:
    std::stack<double> _stack;

    bool   isOperator(const std::string& token) const;
    bool   isNumber(const std::string& token) const;
    double performOperation(double a, double b, char op) const;
    void   processToken(const std::string& token);
    void   clearStack();

  public:
    RPN();
    RPN(const RPN& other);
    ~RPN();
    RPN& operator=(const RPN& other);

    int calculate(const std::string& expression);
};

//
//
// #ifndef FORM_HPP
// #define FORM_HPP

// #include <iostream>
// #include <ostream>
// #include <string>

// class Form
// {
//   private:
//     void copy(const Form& other);

//   public:
//     Form();
//     Form(const Form& other);
//     ~Form();
//     Form& operator=(const Form& other);
// };

// std::ostream& operator<<(std::ostream& os, const Form& form);

// #endif

#include "Form.hpp"
#include "Logger.hpp"

Form::Form() : _name("Simple Form"), _isSigned(false), _signGrade(150), _executionGrade(150)
{
    Logger::printLog("Form Default constructor called");
}

Form::Form(const std::string& name, const int signGrade, const int executionGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executionGrade(executionGrade)
{
    Logger::printLog("Form Constructor called");

    if (_signGrade > 150)
        throw Form::GradeToLowException();
    if (_signGrade < 1)
        throw Form::GradeToHighException();
    if (_executionGrade > 150)
        throw Form::GradeToLowException();
    if (_executionGrade < 1)
        throw Form::GradeToHighException();
}

Form::Form(const Form& other)
    : _name(other.getName()), _isSigned(other.getIsSigned()), _signGrade(other.getSignGrade()), _executionGrade(other.getExecutionGrade())
{
    Logger::printLog("Form Copy Constructor called");
}

Form::~Form()
{
    Logger::printLog("Form Destructor called");
}

Form& Form::operator=(const Form& other)
{
    Logger::printLog("Form equal operator called");

    if (this != &other)
        copy(other);

    return *this;
}

void Form::copy(const Form& other)
{
    _isSigned = other.getIsSigned();
}

const std::string Form::getName() const
{
    return _name;
}

const int Form::getSignGrade() const
{
    return _signGrade;
}

const int Form::getExecutionGrade() const
{
    return _executionGrade;
}

const bool Form::getIsSigned() const
{
    return _isSigned;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw Form::GradeToLowException();

    _isSigned = true;
}

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _name("Simple Form"), _signGrade(150), _executionGrade(150), _isSigned(false)
{
}

Form::Form(const std::string& name, const int signGrade, const int executionGrade)
    : _name(name), _signGrade(signGrade), _executionGrade(executionGrade), _isSigned(false)
{
    if (_signGrade > 150)
        throw Form::GradeTooLowException();
    if (_signGrade < 1)
        throw Form::GradeTooHighException();
    if (_executionGrade > 150)
        throw Form::GradeTooLowException();
    if (_executionGrade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(const Form& other)
    : _name(other.getName()), _signGrade(other.getSignGrade()), _executionGrade(other.getExecutionGrade()),
      _isSigned(other.getIsSigned())
{
}

Form::~Form()
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _isSigned = other.getIsSigned();

    return *this;
}

const std::string Form::getName() const
{
    return _name;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecutionGrade() const
{
    return _executionGrade;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw Form::GradeTooLowException();

    _isSigned = true;
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << form.getName() << " (sign grade: " << form.getSignGrade() << ", execution grade: " << form.getExecutionGrade()
       << ") is " << (form.getIsSigned() ? "" : "not ") << "signed";

    return os;
}
